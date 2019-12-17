# include <stdio.h>
# include <stdlib.h>
# define MAX 6
int stack[MAX];
int top = -1;
int menu()
{
    int ch;
    printf("\n … Stack operations using ARRAY... \n");
    printf("\n -----------**********-------------\n");
    printf("1. Push \n");
    printf("2. Pop \n");
    printf("3. Display\n");
    printf("4. Is empty? \n");
    printf("5. Peek \n");
    printf("6. Quit \n");
    printf("Enter your choice: \n");
    scanf("%d", &ch);
    return ch;
}

void display()
{
    int i;
    if(top < 0)
    {
        printf("\nStack empty..\n");
        return;
    }
    else
    {
        printf("\nElements in stack:\n");
        for(i = 0; i <= top; i++)
        printf("\t%d", stack[i]);
    }
    return;
}

int pop()
{
    int item;
    if(top < 0)
    {
        printf("\nStack Underflow..\n");
        exit(0);
    }
    else
    {
        item=stack[top]; //how about return stack[top--]?
        top=top-1;
        return item;
    }
}

void push(int item)
{
    if(top == MAX-1)
    {
        printf("\nStack Overflow..\n");
        return;
    }
    else
    {
        top = top + 1;
        stack[top] = item;
        printf("\nData Pushed into the stack\n");
    }
    return;
}

//returns the top element of stack without removing it
int peek()   
{
	if (top == -1)
	{
        printf("\nstack is empty\n");
		exit(0);
	}
	else
		return stack[top];	
}

//checks stack is empty or not
void isEmpty()	
{	
	if (top ==-1)
	    printf("stack is empty \n");
	else
		printf("stack is not empty \n");
    return;
}

void main()
{
    int ch, topofstack,data;
    do
    {
        ch = menu();
        switch(ch)
        {
            case 1:
                printf("\nEnter data: \n");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                printf ("The popped item is %d\n",pop());
                break;
            case 3:
                display();
                break;
            case 4:
                isEmpty();
                break;
            case 5:
                printf("%d",peek());
                break;
            case 6:
                exit(0);
        }
    } while(1);
    return;
}