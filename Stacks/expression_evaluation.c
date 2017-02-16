#include<stdio.h>
#include<stdlib.h>

/*
   e.g 
   (1 + ( ( 2 + 3 ) *( 4 * 5 ) ))
   (1 + (( 5 ) * ( 20 ))
   (1 + ( 100 ))
   101
   Using Djakarta algorithm of 2 stacks
   create two stack - one for value and one for operation
   on every closing bracket pop two values and pop one operation, 
   perform the operation and push the value to value stack
*/

//TODO
int is_opening_bracket(char ch)
{
	
}

int is_closing_bracket(char ch)
{
	
}

int is_operation(char ch)
{
	
}


int apply_ops(char op, int a, int b)
{
	switch(op)
	{
		case '+':
		  return a+b;
		case '-':
		  return a-b;
		case '*'
		  return a*b;
		case '/':
		  if(b == 0)
		  {
			  printf("Exception: Division by 0");
			  return -1;
		  }
		  return a/b;
		 default:
		  return 0;
	}
}

int evaluate_expression(char str[])
{
	int len = strlen(str);
	Stack *val = create_stack();
	Stack *ops = create_stack();
	for(int i=0; i<len; i++)
	{
		if(is_opening_bracket(str[i]))
			;
		else if(is_operation(str[i]))
			push(ops, str[i]);
		else if(is_closing_bracket(str[i])
            push(vals, apply_ops(pop(ops), pop(vals), pop(vals)));			
		else push(vals, str[i]-'0');
			
	}
	
	return pop(vals);
}