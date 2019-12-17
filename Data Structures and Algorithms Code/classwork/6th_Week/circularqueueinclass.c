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
int count =0;

node* getnode()
{
    node *temp;
    temp = (node *) malloc(sizeof(node)) ;
    printf("\n Enter data ");
    scanf("%d", &temp -> data);
    temp -> next = NULL;
    return temp;
}

void insertCQLL()
{
    node *newnode;
    newnode= getnode();
    if(count==0)
    {
    front = newnode;
    rear = newnode;
    }
    else
    {
    rear -> next = newnode;
    rear = newnode;
    rear -> next = front;
    }
    count++;
    printf("\n Data Inserted into the Queue..");
    return;
}

void deleteCQLL()
{
    node *temp;
    if(count==0)
    {
        printf("\n\n\t Empty Queue..");
        return;
    }
    else
    {
        temp = front;
        front = front -> next;
        rear -> next = front -> next;
        free(temp);
    }
    return;
}

void displayCQLL()
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
        do
        {
            printf("%d--> ", temp -> data);
            temp = temp -> next;
        } while(temp != front);
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
                insertCQLL();
                break;
            case 2:
                deleteCQLL();
                break;
            case 3:
                displayCQLL();
                break;
            case 4:
                return;
        }
    } while(ch != 4);
}