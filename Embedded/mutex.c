/* atomic execution by hardware */
boolean test_and_set(boolean &mutex) {
   boolean tmp=mutex;
   mutex = true;
   return tmp;
}

void mutex_init(boolean &mutex) {
   mutex = false;
}

void mutex_lock(boolean &mutex) {
   while(test_and_set(mutex));
}

void mutex_unlock(boolean &mutex) {
   mutex = false;
}