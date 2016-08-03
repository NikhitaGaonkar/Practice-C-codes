#include<stdio.h>

typedef T int

T BinMap[100]={0};

void FindPair(T arr[], T sum)
{
  int index =0 ;
  int Size = sizeof(arr);
  T temp =0;
  for(index=0 ; index<Size; index++)
  {
    temp = sum - arr[index];
    if((temp>= 0) && (BinMap[temp] == 1))
       printf("The pairs are %d and %d", arr[index], temp);
    BinMap[arr[inex]]= 1;
  }
}
