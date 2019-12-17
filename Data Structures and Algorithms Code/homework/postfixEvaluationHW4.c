/*
Christopher McGrath
CSCI 240 HW4.c postfix Evaluation
10/5/19
*/
#define SIZE 50            /* Size of Stack */
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int stack[SIZE];
int top=-1;       /* Global declarations */
 
/* Function for PUSH operation */
void push(int item)
{
    if(top == SIZE - 1)
    {
        printf("Stack overflow...\n");
        return;
    }
    else 
    {
        top++;
        stack[top] = item;
    }
    return;
} 

int Power(int base, int pow)
{
	if (pow==0) 
	    return 1;
    else if (pow==1)
        return base;
	else
		return base*Power(base, pow-1);
}

/* Function for POP operation */
int pop()
{
    if( top < 0)
    {
        printf("Stack underflow...\n");
        return;
    }
    else
        return stack[top--];
}

/* Function for precedence */
int pr(char elem)
{                 
    if(elem == '(')
        return -2;
    else if(elem == ')')
        return -1;
    else if(elem == '+'||elem == '-')
        return 1;
    else if(elem == '/'||elem == '*')
        return 2;
    else if(elem == '^')
        return 3;
    else 
        return 4;
}

//Evaluate postfix expression

void evaluatepostfix (char pofx[])
{
    int i = 0;
    char currentPosition = pofx[i];
    int A = 0, B = 0, evaluation = 0;
    
    while(currentPosition != '\0')
    {
        currentPosition = pofx[i];
        if(isdigit(currentPosition))
            push(currentPosition - 48);
        else if(currentPosition == '*' || currentPosition == '/' || currentPosition == '+' || currentPosition == '-' || currentPosition == '^')
        {
            A = pop();
            B = pop();
            if(currentPosition == '*')
                evaluation = B * A;
            else if(currentPosition == '/')
                evaluation = B / A;
            else if(currentPosition == '+')
                evaluation = B + A;
            else if(currentPosition == '-')
                evaluation = B - A;
            else if(currentPosition == '^')
                evaluation = Power(B,A);
            push(evaluation);
        }
        i++;
    }
    printf("Evaluation result: %d\n", evaluation);
}

/* main function begins */
int main()
{
	char postfix[SIZE];        
	printf("ASSUMPTION: The postfix expression contains single letter variables and single digit constants only.\n");
	printf("\nEnter postfix expression : ");
    scanf("%s",postfix);
	evaluatepostfix(postfix);
	return 0;
}