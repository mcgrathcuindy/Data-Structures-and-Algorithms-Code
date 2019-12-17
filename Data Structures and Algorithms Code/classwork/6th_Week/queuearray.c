#include <stdlib.h>
#include <stdio.h>
# define MAX 6
int Q[MAX];
int front=0, rear=0;

void displayQ();
void enQueue(int data);
int deQueue();

void enQueue(int data)
{
    if(rear == MAX)
    {
        printf("\n Linear Queue is full");
        return;
    }
    else
    {
        Q[rear] = data;
        rear++;
        printf("\n Data Inserted in the Queue ");
    }
}

int deQueue()
{
    if(rear == front)
    {
        printf("\n\n Queue is Empty..");
        return -9999;
    }
    else
    {
        printf("\n Deleted element from Queue is %d", Q[front]);
        return Q[front++];
    }
}

void displayQ()
{
    int i;
    if(front == rear)
    {
        printf("\n\n\t Queue is Empty");
        return;
    }
    else
    {
        printf("\n Elements in Queue are: ");
        for(i = front; i < rear; i++)
        {
            printf("%d\t", Q[i]);
        }
    }
}

int menu()
{
    int ch;
    printf("\n \tQueue operations using ARRAY..");
    printf("\n -----------**********-------------\n");
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
    int data, result;
    do
    {
        ch = menu();
        switch(ch)
        {
            case 1:
                printf("\n Enter data: ");
                scanf("%d", &data);
                enQueue(data);
                displayQ();
                break;
            case 2:
                data = deQueue();
                if(data>=-9999)
                    printf("\n%d deleted from queue\n", data);
                displayQ();
                break;
            case 3:
                displayQ();
                break;
            case 4:
                return;
        }
    }while(1);
    return;
}