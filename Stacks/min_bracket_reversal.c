#include<stdio.h>
#include<stdlib.h>
/*
Given an expression with only ‘}’ and ‘{‘. 
The expression may not be balanced. Find minimum number of bracket reversals to make the expression balanced.

Examples:

Input:  exp = "}{"
Output: 2
We need to change '}' to '{' and '{' to
'}' so that the expression becomes balanced, 
the balanced expression is '{}'

Input:  exp = "{{{"
Output: Can't be made balanced using reversals

Input:  exp = "{{{{"
Output: 2 

Input:  exp = "{{{{}}"
Output: 1 

Input:  exp = "}{{}}{{{"
Output: 3

The idea is to first remove all balanced part of expression. For example, convert “}{{}}{{{” to “}{{{” by removing highlighted part. 
If we take a closer look, we can notice that, after removing balanced part, we always end up with an expression of the form }}…}{{…{, 
an expression that contains 0 or more number of closing brackets followed by 0 or more numbers of opening brackets.

How many minimum reversals are required for an expression of the form “}}..}{{..{” ?. 
Let m be the total number of closing brackets and n be the number of opening brackets. 
We need ⌈m/2⌉ + ⌈n/2⌉ reversals. For example }}}}{{ requires 2+1 reversals.
*/

//declare a character stack!!!!
typedef struct Node{
	char data;
	struct Node * next;
}Node;

typedef struct Stack{
	
	Node *first; //head node 
	int size; //size of the stack
}Stack;

#define ERROR -1

int min_bracket_reversals(char *exp, int size)
{
	//can balance only even no of brackets
	if(exp == NULL || (size%2)!= 0) 
	{
		printf("Cannot balance");
		return ERROR;
	}
	
	Stack *s = create_stack();
	for(int i=0; i<size; i++)
	{
		if(exp[i] == '}' && !isEmpty(s))
		{
			if(top(s) == '{')
				pop(s);
			else
				push(s, exp[i])
		}
		else
			push(s, exp[i]);
	}
//no of } and { brackets
	int m=0, n=0;
	while(!isEmpty(s))
	{
		if(top(s) == '}')
		  m++;
	    else
		  n++;
	    pop(s);
	}
	
	return (ceil(m/2) + ceil(n/2));
}

Test cases:
char exp[]= "}}{{"; 2
char exp[]= " ";  -1
char exp[]= "{{}"; -1
char exp[]= "}{{}}{{{"; 3
char exp[]= "{{{}}{{{{"; 2









