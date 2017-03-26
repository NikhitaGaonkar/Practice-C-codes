
//Semaphore implementation
/*
 Ref: http://greenteapress.com/thinkos/html/thinkos012.html
 
 Property 1: if there is only one thread that is ready to run, the
             scheduler has to let it run.
 Property 2: if a thread is ready to run, then the time it waits until
			it runs is bounded.
Property 3: if there are threads waiting on a semaphore when a
			thread executes signal, then one of the waiting threads has to be
			woken.

*/
typedef struct Semaphore{
	int value;  //max value of sempahore
	int wakeup; // no of threads woken up but not resumed
	Mutex *mutex; //for exclusive access to value
	Cond *cond;  // the condition variable threads wait on if they wait on the semaphore.
	
}Semaphore;


Semaphore *make_semaphore(int value)
{
	Semaphore *s = malloc(sizeof(Semaphore));
	s->value = value;
	s->wakeup = 0;
	s->mutex = make_mutex();
	s->cond  = make_cond();
}

/*
When a thread waits on the semaphore, it has to lock the mutex before it decrements value.
If the value of the semaphore becomes negative, the thread blocks until a “wakeup” is available. 
While it is blocked, the mutex is unlocked, so another thread can signal.
*/
void sem_wait(Semaphore *s)
{
	mutex_lock(s->mutex);
	s->value--;
	
	if(s->value < 0)
	{
	  do{
		  cond_wait(s->cond, s->mutex); //this unlocks the mutex
	  }while(s->wakeup < 1);
	  s->wakeup--;
	}
	
	mutex_unlock(s->mutex);
}

/*
a thread has to lock the mutex before it increments value. 
If the semaphore was negative, that means threads are waiting, so the signalling thread increments wakeups and signals the condition variable.
At this point one of the waiting threads might wake up, but the mutex is still locked until the signalling thread unlocks it.

At that point, one of the waiting threads returns from cond_wait and checks whether a wakeup is still available. 
If not, it loops and waits on the condition variable again. If so, it decrements wakeups, unlocks the mutex, and exits.
*/
void sem_signal(Semaphore *s)
{
	mutex_lock(s->mutex);
	s->value++;
	
	if(s->value < 0)
	{ 
		s->wakeup++; // to wake up a thread that is waiting
		cond_signal(s->cond); //signal the thread 
	}
	
	mutex_unlock(s->mutex);
}


/*
One thing about this solution that might not be obvious is the use of a do...while loop. 
Can you figure out why it is not a more conventional while loop? What would go wrong?

The problem is that with a while loop this implementation would not have Property 3. 
It would be possible for a thread to signal and then run around and catch its own signal.

With the do...while loop, it is guaranteed1 that when a thread signals, 
one of the waiting threads will get the signal, even if the signalling thread runs around and 
gets the mutex before one of the waiting threads resumes.
*/



//Simpler without condition variable
void sem_wait(Semaphore *s)
{
	mutex_lock(s->mutex);
	s->value--;
	
	while(s->value < 0)
	{
		mutex_unlock(s->mutex);
		sleep();  //or wait();
		mutex_lock(s->mutex); //unlock and loop to check if semaphore available
	}
	
	mutex_unlock(s->mutex);
}

void sem_signal(Semaphore *s)
{
	mutex_lock(s->mutex);
	s->value++;
	mutex_unlock(s->mutex);
}






