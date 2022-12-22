#include <stdio.h>
#include <stdlib.h>

int size = 40;
char s1[40];
int stack[40];
int top = -1;

void push(int n)
{
	if (top < size -1)
	{
		stack[++top] = n;
	}
	return;
}
int pop()
{	
	int n;
	if (top > -1)
	{
		n = stack[top];
		stack[top--] = -1;
		return n;
	}
	return -1;
}

int Postfix_evaluation(){
	int i, op1, op2, res;
	char ch;
	
	for(i=0; i< size; i++)
	{
		stack[i] = -1;
	}
	printf("Enter a postfix expression: ");
	scanf("%s",&s1);

	for(i=0; s1[i] != '\0'; i++)
	{
		ch = s1[i];

		if(isdigit(ch))
		{
			push(ch-'0');
		}
		else if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '%')
		{
			op2 = pop();
			op1 = pop();

			switch(ch){
			case '+':
				res = op1+op2;
				break;
			case '-':
				res = op1-op2;
				break;
			case '*':
				res = op1*op2;
				break;
			case '/':
				res = op1/op2;
				break;
			case '^':
				res = op1^op2;
				break;
			case '%':
				res = op1%op2;
				break;
			}		
			push(res);
		}		
	
	}
	
	printf("\nThe postfix evaluation is: %d\n",pop());
}
int main()
{
	Postfix_evaluation();
	return 0;
}


