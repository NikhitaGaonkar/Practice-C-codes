//Contex switch time

int counter;
pthread_mutex_t start;
pthread_mutex_t lock;
pthread_cond_t cond;

void my_thread()
{
	//try to start
	pthread_mutex_lock(&start);
	pthread_mutex_unlock(&start);
	//try to get mutex for counter
	pthread_mutex_lock(&lock);
	if(counter > 0)
		pthread_cond_signal(&cond);
	for(;;)
	{
		counter++;
		pthread_cond_wait(&cond, &lock); //wait and unlock the mutex
		pthread_cond_signal(&cond);
	}
	pthread_mutex_unlock(&lock)
}

int main()
{
	counter =0;
	pthread_t t1;
	pthread_t t2;
	//lock the threads
	pthread_mutex_lock(&start);
	//crate thereads
	pthread_create(&t1, NULL, my_thread, NULL);
	pthread_create(&t2, NULL, my_thread, NULL);
	//trigger the thread
	pthread_detach(t1);
	pthread_detach(t1);
	//get the current time stamp
	my_time = get_time();
	//let the threads run
	pthread_mutex_unlock(&start);
	//sleep for one second
	sleep(1000);  
	//lock both threads
	pthread_mutex_lock(&lock);
	//normalize the result in sec precision
	my_time = get_time() - my_time /1000;
	
	//com
}