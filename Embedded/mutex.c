//http://lxr.free-electrons.com/source/include/linux/mutex.h#L51
//http://lxr.free-electrons.com/source/kernel/locking/mutex.c


typedef struct Mutex{
	int lock;
}Mutex;

int test_and_set(Mutex *mx)
{
	int last_value = mx->lock;
	mx->lock = 1;
	return last_value;
}

int compare_and_swap(Mutex *mx, int old_val, int new_val)
{
	int save = mx->lock;  //save current value
	if(save == old_val)    //update lock only if matches the old value or if not locked
		mx->lock = new_val;
	return save;  //return lock status
}

int mutex_init()
{
	Mutex *mx = malloc(sizeof(Mutex));
	mx->lock = 0;
}

void mutex_lock(Mutex *mx)
{
	while(mx->lock == 1 || tes_and_set(mx)) //while(mx->lock == 1 || compare_and_swap(mx, 0, 1) != 0);
	{
		//Do nothing, while we wait to get the lock
	} 
}

void mutex_unlock(Mutex *mx)
{
	if(mx)
	  mx->lock = 0; 
}

void main(void)
{
	int counter =0;
	Mutex *mx = mutex_init();
	if(mx == NULL) 
	{
		printf("Lock initialization failed");
		exit();
	}
	mutex_lock(mx);
	counter++;
	mutex_unlock(mx);
}

int value; //variable to contain lock value merely to explain current state
//bare metal
void acquire_lock(Mutex *mx)
{
	int lock = mx->lock;
	__asm //inline assembly
	{
		mov eax,1  //eax is a 32 bit reg in which we are assigning 1
		xchg eax, lock //exchange eax and lock variable atomically
		mov value , eax //spin on this
	}
}

void free_lock(Mutex *mx)
{
	mx->lock = 0;
}

void main(void)
{
	Mutex mx;
	acquire_lock(&mx);
	if(value == 0) //would contain previous value of lock
	  printf("Lock available");
	 
	acquire_lock(&mx);
	if(value == 1)
		printf("Already Locked");
	
	free_lock();
	if(value == 1)
		printf("Freed now, although was locked earlier and can be acquired");
	
	acquire_lock(&mx);
	if(value == 0)
		printf("Lock was available,so now acquired");
	
}
