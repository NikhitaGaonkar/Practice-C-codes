#include<stdio.h>
#include<stdlib.h>


//size of an int without sizeof

int main()
{
	int *a, *s ,v =10;
	a =&v;
	s=a;
	a++;
	
	int size =(int)a-(int)s;
	printf("%d \n", size);
	printf("%d", sizeof(v));
	return 0;
}

/*
size_t size = (size_t)(1 + ((X*)0));
X is a data type
(X*)0 is a null pointer
+1 tells you the size

*/
