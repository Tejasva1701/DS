//Program 10: Implement the conversion of infix notation to postfix notation.

#include <stdio.h>
#include <stdlib.h>
#define size 20

char stack[size];
int top = -1;

char pop()
{
    if (top == -1){
        printf("Stack Underflow\n");
        return -1;
    }
    char ch = stack[top];
    top--;
    return (ch);
}

void push(char op)
{
    if (top == size-1)
        printf("Stack Overflow\n");

    else
    {
        top++;
        stack[top] = op;
    }
}

int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int Precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return -1;
}

int Postfix(char *str){
    int i, j;
    for (i = 0, j = -1; str[i]; ++i)
    {

        if (isOperand(str[i]))
        {
            str[++j] = str[i];
        }

        else if (str[i] == '(')
        {
            push(str[i]);
        }

        else if (str[i] == ')')
        {
            while (top != -1 &&  stack[top] !='(')
            {
                str[++j] = pop();
            }
            if (top !=-1 && stack[top] != '('){
                return -1;
            }
            else{
                pop();
            }
        }
        else{
            while (top != 1 && Precedence(str[i]) <= Precedence(stack[top])){
            	str[++j] = pop();	
			}
            push(str[i]);
        }
    }

    while (top != -1)
    {
        str[++j] = pop();
    }

    str[++j] = '\0';
    printf("%s", str);
}

int main()
{
	char str[size];
	printf("Enter a infix expression: ");
	scanf("%s",&str);
    printf("Postfix Expression of the given infix expression is: ");
	Postfix(str);
    return 0;
}


