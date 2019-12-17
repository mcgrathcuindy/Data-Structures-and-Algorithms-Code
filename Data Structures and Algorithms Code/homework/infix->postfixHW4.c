/*
Christopher McGrath
CSCI 240 HW4.c Infix to Postfix
10/5/19
*/
#define SIZE 50            /* Size of Stack */
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char stack[SIZE];
int top=-1;       /* Global declarations */
 
/* Function for PUSH operation */

void push(char item)
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

/* Function for POP operation */
char pop()
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

 /* Function for infix to postfix conversion */
void InfixToPostfix(char infx[], char pofx[])
{                        
    int i=0, j=0;
    char currentPosition = infx[i];
    char temp;
    push('(');
    strcat(infx, ")"); //I remove this at the end of the function
    
    while(currentPosition != '\0')
    {
        if( isalpha(currentPosition) || isdigit(currentPosition))
        {
            pofx[j] = currentPosition;
            j++;
        }
        else if(pr(currentPosition) == -2)
            push(currentPosition);
        else if((pr(currentPosition)==1 || pr(currentPosition)==2 || pr(currentPosition)==3) == 1)
        {
            temp = pop();
            while((pr(temp)==1 || pr(temp)==2 || pr(temp)==3) == 1 && pr(temp) >= pr(currentPosition))
            {
                pofx[j] = temp;
                j++;
                temp = pop();
            }
            push(temp);
            push(currentPosition);
        }
        else if(currentPosition == ')')
        {
            temp = pop();
            while(temp != '(')
            {
                pofx[j] = temp;
                j++;
                temp = pop();
            }
        }
        else
            printf("\nCan only evaluate operators, operands, and parentheses\n");
        i++;
        currentPosition = infx[i];
    }
    pofx[j] = '\0';
    
    //This is code to get rid of the Parenthesis 
    //we concatenated onto the infx string at the
    //beginning of this function
    char tempString[SIZE];
    for(j = 0; j < i-1; ++j){
        tempString[j] = infx[j];
    }
    tempString[j] = '\0';
    strcpy(infx, tempString);
}

/* main function begins */
int main()
{
	char infix[SIZE], postfix[SIZE];         /* declare infix string and postfix string */
	printf("ASSUMPTION: The infix expression contains single letter variables and single digit constants only.\n");
	printf("\nEnter Infix expression : ");
    scanf("%s",infix);
	InfixToPostfix(infix,postfix);                   /* call to convert */
	printf("\n\nGiven Infix Expn: %s  Postfix Expn: %s\n",infix,postfix);
	return 0;
}