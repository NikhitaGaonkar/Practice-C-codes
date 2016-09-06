#include<stdio.h>
#include<stdbool.h>


int BinarySearch(int low, int high , int arr[], int elem)
{
  if(high >= low)
  {
  
    int mid = (low+high)/2;

  // idea is to return the 1st occurrence
  /* Check if arr[mid] is the first occurrence of x.
            arr[mid] is first occurrence if x is one of the following
            is true:
            (i) mid == 0 and arr[mid] == x
            (ii) arr[mid-1] < x and arr[mid] == x
        */
    if((mid==0 || elem> arr[mid-1]) && (elem==arr[mid]))
      return mid;
    else if(elem>arr[mid])
      return (BinarySearch(mid+1,high,arr,elem));
    else
      return(BinarySearch(low,mid-1,arr,elem));
  }
  
  return -1;    
}

 
int check(int l, int r, int arr[], int x)
{
	int i;
	for(i= l; i< r; i++)
	  return(x== arr[i]);
}

#if 0
//o(n)
bool IsMajority(int arr[], int size, int x)
{
	int count = 0;
	int i;
	for(i=0; i<size; i++)
	{
		if(arr[i]== x)
		  count++;
		if(count > size/2)
		  return true;
	}
	 return false;
	
}
#endif

#if 0
//o(n/2) best case
bool IsMajority(int arr[], int size, int x)
{
	int curr, prev,count = 0;
	int med = size/2;
	
	if(x>arr[med])
	{
		if(check(med, size, arr,x))
		  count++;		
	}
	else if(x < arr[med])
	{
		if(check(med, size, arr,x))
		  count++;	
	}
	else
	{
		count++;
		prev = med;
		while(med <size)
		{
			if(x==arr[med])
			  count++;
		    else
		      break;
		    med++;
		}
		while(prev)
		{
			if(x== arr[med])
			  count++;
			else
			  break;
		    prev--;
		}
		
	}
	

	if(count >size/2)
	  return true;
	  
	return false;	
}
#endif

//log(n)
bool IsMajority(int arr[], int size, int elem)
{
  int i = BinarySearch(0, size-1 ,arr, elem);

  if(i== -1)
    return false;
  if(((i+size/2)< size-1) && elem == arr[i+size/2])
    return true;

 return false;
}



int main()
{
 int a[7] ={1,2,3,3,3,3,10};
 if(IsMajority(a, 7, 3))
   printf("True");
 else printf("False");	
 return 0;
	
}
