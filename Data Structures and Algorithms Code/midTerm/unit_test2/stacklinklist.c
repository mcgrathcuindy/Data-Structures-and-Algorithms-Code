# include <stdio.h>
# include <stdlib.h>
struct stack
{
    int data;
    struct stack *next;
};
typedef struct stack node;

node* getnode(int data)
{
    node* newnode;
    newnode = (node*) malloc(sizeof(node));
    newnode -> data = data;
    newnode -> next = NULL;
    return newnode;
}

//Get the element at the top of the stack (the one that will be returned if pop() is called) without removing it
//else return -1 (if stack is empty)
int peek(node ** top)   
{
	if (*top == NULL)
	    return -1;
	else
		return (*top)->data;	
}

//checks stack is empty (return 1) or not (return 0)
int isEmpty(node ** top)	
{	
	if(*top == NULL)
        return 1;
	else
        return 0;		
}

void push(node ** start, node **top, int data)
{
    node *temp;
    node * newnode;
    newnode = getnode(data);
    if( newnode == NULL )
    {
        printf("\n Stack Overflow..");
        return;
    }
    if(*start == NULL)
    {
        *start = newnode;
        *top = newnode;
    }
    else
    {
        /*
        temp = start;
        while( temp -> next != NULL)
            temp = temp -> next;
        temp -> next = newnode;
        top = newnode;
        */
        (*top)->next=newnode;
        *top=newnode;
    }
    //printf("\n\n\t Data pushed into stack");
    return;
}

int pop(node **start, node ** top)
{
    node *temp;
    int result;
    if(*top == NULL)
    {
        //printf("\n\n\t Stack underflow");
        return -9999;
    }
    temp = *start;
    if( (*start) -> next == NULL) //One node only
    {
        result= (*top) -> data;
        *start = NULL;
        free(*top);
        *top = NULL;
    }
    else
    {
        while(temp -> next != (*top))
        {
            temp = temp -> next;
        }
        temp -> next = NULL;
        result= (*top) -> data;
        //printf("\n\n\t Popped element is %d ", top -> data);
        free(*top);
        *top = temp;
    }
    return result;
}

void display(node *start, node * top)
{
    node *temp;
    if(top == NULL)
    {
        printf("\n\n\t\t Stack is empty ");
    }
    else
    {
        temp = start;
        printf("\n\n\n\t\t Elements in the stack: \n");
        printf("%d ", temp -> data);
        while(temp != top)
        {
            temp = temp -> next;
            printf("%d ", temp -> data);
        }
    }
    return;
}


