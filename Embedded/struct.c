#include <stdio.h>
#include <stdlib.h>

//#pragma pack(2)

struct foo
{
   char a;
   char *b;
};


int main()
{
	unsigned int x= 0xfffffe00;
	unsigned int y= ((~x)&((~x)+1));
	printf("%d", y);
	//printf("%d ", sizeof(struct foo));
}

/*
More or less (pointer wise), on 16, 32 and 64-bit arches, pointer sizes are 2, 4 and 8 respectively.

It's not safe to assume padding, but natural padding of a char resulting in 4 octets will often be the case, yes. For x86, fields are usually 32-bit aligned. The reason for this is to increase the system's performance at the cost of memory usage.

Similarly, for x64, fields are usually 64-bit/8-byte aligned, so sizeof(foo) would be 16. 

So, if x86:

4 bytes for 16-bit OS
8 bytes for 32-bit OS
16 bytes for 64-bit OS

x86 refers to the 8086 family of instruction set architectures, but you would imply 32-bit if you would say just "x86". x86-16 implies 16-bit and x64 implies x86-64.

As for the rest of your quote, pointers are 16 bits in x86-16, so you'd be correct to assume it would be what you wrote. 


some compilers such as Microsoft has a packing pragma that let you change how the compiler aligns the data in the structure or c++ class. 
#pragma pack(1) // byte align the data
struct foo
{
   char a;
   char *b;
};
With byte alignment the compiler does not put holes in the structure, so sizeof(struct foo) will be 5

#pragma pack(2) // word align the data
struct foo
{
   char a;
   char *b;
};
With word alignment the compiler will align the pointer in an even byte boundry (or address) and sizeof(struct foo) will be 6. 


*/
