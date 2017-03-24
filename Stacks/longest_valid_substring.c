#include<stdio.h>
#include<stdlib.h>

/*
Given a string consisting of opening and closing parenthesis,
find length of the longest valid parenthesis substring.

Examples:

Examples:

Input : ((()
Output : 2
Explanation : ()

Input: )()())
Output : 4
Explanation: ()() 

Input:  ()(()))))
Output: 6
Explanation:  ()(()))
*/
typedef struct Node{
	char data;
	struct Node * next;
}Node;

typedef struct Stack{
	
	Node *first; //head node 
	int size; //size of the stack
}Stack;

#define ERROR -1
/*
			  0 1 2 3 4 5 6 7 8 9 10
char exp[] = "( ) ) ) ( ( ) ) ) ) )"

i=0  exp[0] = '(' push 0 to stack [-1, 0]
i=1  exp[1] = ')' pop 0,  len = 1- (-1) = 2
i=2  exp[2] = ')' pop -1 now stack is empty so look for new string
i=3  exp[3] = ')' pop stack empty push 3 [3]
i=4  exp[4] = '(' push 4 [3,4]
i=5  exp[5] = '(' push 5 [3,4,5]
i=6  exp[6] = ')' pop 5 len = 6-4 = 2 [3,4]
i=7  exp[7] = ')' pop 4 len = 7-3 = 4
i=8  exp[8] = ')' pop 3 []
i=9  exp[9] = ')' push 9 [9]
i=10  exp[10] = ')' pop 9[]
done return  len =4  

basically storing the starting point of the valid substring and updating the len
*/

int max_substring(char *exp, int size)
{
	//only one bracket cant be valid
	if(exp == NULL || size == 1) return ERROR;
	
	Stack *s = create_stack();
	//base of ist valid substring
	push(s, -1);
	int len =0;
	
	for(int i=0; i<size; ++i)
	{
		if(exp[i] == '(')
			push(s, i);
		else
		{
			if(!isEmpty)
			  pop(s);
		    if(!isEmpty(s))
				len = max(len, i-top(s)); //current index - starting index or base of substring under consideration
			else
				push(s, i) //set the new base index for next possible valid substring
		}
	}
	return len;
}




