# include <stdlib.h>
#include <stdio.h>

struct queue
{
    int data;
    struct queue *next;
};
typedef struct queue node;
node *front = NULL;
node *rear = NULL;

node* getnode()
{
    node *temp;
    temp = (node *) malloc(sizeof(node)) ;
    printf("\n Enter data ");
    scanf("%d", &temp -> data);
    temp -> next = NULL;
    return temp;
}

void insertQLL()
{
    node *newnode;
    newnode= getnode();
    if(newnode== NULL)
    {
        printf("\n Queue Full");
        return;
    }
    if(front == NULL)
    {
        front = newnode;
        rear=newnode;
    }
    else
    {
        rear -> next = newnode;
        rear=newnode;
    }
    printf("\n Data Inserted into the Queue..");
    return;
}

void deleteQLL()
{
    node *temp;
    if(front == NULL)
    {
        printf("\n\n\t Empty Queue..");
        return;
    }
    temp = front;
    front = front -> next;
    printf("\n\n\t Deleted element from queue is %d ", temp -> data);
    free(temp);
    return;
}

void displayQLL()
{
    node *temp;
    if(front == NULL)
    {
        printf("\n\n\t\t Empty Queue ");
    }
    else
    {
        temp = front;
        printf("\n\n\n\t\t Elements in the Queue are: ");
        while(temp != NULL)
        {
            printf("%d ", temp -> data);
            temp = temp -> next;
        }
    }
}

int menu()
{
    int ch;
    printf("\n \t..Queue operations using pointers.. ");
    printf("\n\t -----------**********-------------\n");
    printf("\n 1. Insert ");
    printf("\n 2. Delete ");
    printf("\n 3. Display");
    printf("\n 4. Quit ");
    printf("\n Enter your choice: ");
    scanf("%d", &ch);
    return ch;
}

void main()
{
    int ch;
    do
    {
        ch = menu();
        switch(ch)
        {
            case 1:
                insertQLL();
                break;
            case 2:
                deleteQLL();
                break;
            case 3:
                displayQLL();
                break;
            case 4:
                return;
        }
    } while(ch != 4);
}