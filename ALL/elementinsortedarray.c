#include <stdio.h>

int binary_search( const int value, const int *arr, size_t start, size_t end ){
    if( value < arr[start] || value > arr[end] ){
        return -1;
    }

    while(start <= end){
        int pivot = (start+end) >> 1; 
        if(arr[pivot] == value){
            return pivot;
        }else if(arr[pivot] < value){
            start = pivot+1;
        } else if(arr[pivot] > value){
            end = pivot-1;
        } 
    }
    return -1;
}

int get_occurences( int begin, const int *arr, size_t max){
    int counter = 1;
    int cursor = begin;
    while ( (cursor+1) < max && arr[cursor] == arr[cursor+1]) {
        counter++;
        cursor++;
    }
    cursor = begin;
    while ( (cursor-1) > 0 && arr[cursor] == arr[cursor-1]) {
        counter++;
        cursor--;
    }
    return counter;
}


#define MAX 22
int main()
{   
    int value;
    int arr_sorted []={1,1,2,3,3,
                       4,4,4,4,5,
                       5,7,7,7,7,
                       8,8,8,9,11,
                       12,12};    
    size_t arr_size = MAX; // works also the other way               

    printf( "\nPlease input the integer you would like to find.\n" );
    scanf( "%d", &value );
    printf("Searching %d\n", value);
    int pos = binary_search( value, arr_sorted, 0, arr_size-1);

    if( pos == -1) {    
        printf( "%d has not been found.\n", value );
    } else{
        int howmany = get_occurences( pos, arr_sorted, arr_size);
        printf( "The first matching index is %d.\n", pos );
        printf( "The total number of instances is %d.\n", howmany );
    }

    return 0;
}
