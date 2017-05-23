#include<stdio.h>
#include<stdlib.h>

void reverse_string(char *start, char *end)
{
  char temp;
  while(start < end)
  {
    temp = *start;
    *start++ = *end;
    *end-- = temp;
  }

}

void reverse_words(char *str)
{
  char *word_start = NULL;
  char *temp = str;
  
  while(*temp)
  {
    //takes care of spaces in between
    if(*temp != ' ' && word_start == NULL)
    {
	word_start = temp;
    }
    //reversing each word within the  string  
    if((*(temp+1)== '\0' || *(temp+1)== ' ') && word_start !=NULL)
    {
      reverse_string(word_start, temp);
      word_start = NULL;
    }
    
    temp++;
  }
  //reverse of the whole string
  reverse_string(str, temp-1 );
}

 
/* Driver function to test above functions */
int main()
{
  char s[] = "i like c programming ";
  char *temp = s;
  reverse_words(s);
  printf("%s", s);
  getchar();
  return 0;
}
