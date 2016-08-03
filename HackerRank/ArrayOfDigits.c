#include<stdio.h>
//#include<conio.h>

/* 
  given an array of digits print all possible combination of alphabets
  between a-z
*/
char res[120];
void print(int arr[],int index,int end,int k)
{
          if(index>=end){
                        //int temp;
                        res[k]='\0';
                        printf("%s",res);
                        //for(temp=0;temp<k;temp++)
                        //printf("%c",res[temp]);
                        printf("\n");
                        return ;
                        }
          res[k]=arr[index]+96;
          print(arr,index+1,end,k+1);
          if(index+1>=end)return ;
          if(arr[index]<2||arr[index]==2&&arr[index+1]<=6)
          {
                                            res[k]=(arr[index]*10+arr[index+1]+96);
                                          //  printf("%c",res[k]);
                                            print(arr,index+2,end,k+1);
          }
          return ;
}
 
int main()
{
    int arr[]={1,2,1};
    int end=sizeof(arr)/sizeof(arr[0]); //4;
    print(arr,0,end,0);
   // getch();
    return 0;
}
