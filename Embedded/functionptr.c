#include<stdio.h> 

int *func (int a, int b)
{
	int * ptr = NULL;
    printf("\n a = %d\n",a);
    printf("\n b = %d\n",b); 

    return ptr;
} 

int main(void)
{
    int(*fptr)(int,int); // Function pointer 

    fptr = func; // Assign address to function pointer 

    func(2,3);
    fptr(2,3); 

    return 0;
}
