# include <stdio.h>
# include <stdlib.h>
struct stack
{
    int data;
    struct stack *next;
};

void push();
void pop();
void display();
int menu();

typedef struct stack node;
node *start=NULL; //always points to the 1st node or NULL (if empty)
node *top = NULL; //always points to the last node or NULL (if empty)

node* getnode()
{
    node *temp;
    temp=(node *) malloc( sizeof(node)) ;
    printf("\n Enter data ");
    scanf("%d", &temp -> data);
    temp -> next = NULL;
    return temp;
}

void push(node *newnode)
{
    node *temp;
    if( newnode == NULL )
    {
        printf("\n Stack Overflow..");
        return;
    }
    if(start == NULL)
    {
 
    }
    else
    {

    }
    printf("\n\n\t Data pushed into stack");
    return;
}

void pop()
{
    node *temp;
    if(top == NULL)
    {

    }
    temp = start;
    if( start -> next == NULL) //One node only
    {

    }
    else
    {

    }
    return;
}

void display()
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

int menu()
{
    int ch;
    printf("\n \tStack operations using pointers.. ");
    printf("\n -----------**********-------------\n");
    printf("\n 1. Push ");
    printf("\n 2. Pop ");
    printf("\n 3. Display");
    printf("\n 4. Quit ");
    printf("\n Enter your choice: ");
    scanf("%d", &ch);
    return ch;
}

void main()
{
    int ch;
    node *newnode;
    do
    {
        ch = menu();
        switch(ch)
        {
            case 1:
                newnode = getnode();
                push(newnode);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit (0);
        }
    } while(1);
    //sreturn;
}