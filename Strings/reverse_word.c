#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

void reverse_stringII(char *str, int start, int end)
{
	if(str == NULL) return;
	end -= 1;
	char temp;
	while(start<end)
	{
		temp = str[start];
		str[start++] = str[end];
		str[end--] = temp;
	}
}

void reverse_wordsII(char *str)
{
	if(str == NULL) return;
	int len = strlen(str);
	int i=0, j=0;
	//reverse the whole string
	reverse_stringII(str, 0, len);
	for(i =0; i<= len; i++)
	{
		if(i == len || str[i] == ' ')
		{ 
			//reverse the word, i points to '', hence i-1
			reverse_stringII(str, j, i);
			j = i+1;
		}
	}
	
}

//to do
char * reverse_wordsI(char *str)
{
	if(str == NULL) return;
	int len = strlen(str);
	char *result = malloc(sizeof(char)* len+1);
	if(result == NULL) return;
	char space = ' ';
	int i= 0;
	int j = len;
	for(i = len; i>=0; i--)
	{
		if(str[i] == ' ')
		  j = i; //setting the end
		if(i== 0 || str[i-1] == ' ')
		{
			if(strlen(result)!= 0)
			  strcat(result, space); //add space between words
			//strcat(result, substr(str, i, j));
		}
	}
	return result;
}
 
/* Driver function to test above functions */
int main()
{
  char s[] = "i like c programming";
  printf("%s \n", s);
  char *temp = s;
  reverse_wordsII(s);
  printf("%s\n", s);
  reverse_words(s);
  printf("%s", s);
 
 //includes spaces //to do
  char str[] = "  i like c   programming  ";
  printf("%s \n", str);
  char *res = reverse_wordsI(s);
  printf("%s\n", res);
  getchar();
  return 0;
}
