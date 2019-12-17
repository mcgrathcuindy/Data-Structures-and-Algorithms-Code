# include <stdio.h>
# include <stdlib.h>
# define MAX 6
int CQ[MAX];
int front = 0;
int rear = 0;
int count = 0;

void insertCQ(int data)
{
    if(count ==MAX)
    {
        printf("\n Circular Queue is Full");
    }
    else
    {
        CQ[rear] = data;
        rear = (rear + 1) % MAX;
        count ++;
        printf("\n Data Inserted in the Circular Queue ");
    }
}

int deleteCQ()
{
    int item;
    if(count ==0)
    {
        printf("\n\nCircular Queue is Empty..");
        return -9999;
    }
    else
    {
        item=CQ[front];
        front = (front + 1) % MAX;
        count --;
        return item;
    }
}

void displayCQ()
{
    int i, j;
    if(count ==0)
    {
        printf("\n\n\t Circular Queue is Empty ");
    }
    else
    {
        printf("\n Elements in Circular Queue are: ");
        j = count;
        for(i = front; j != 0; j--)
        {
            printf("%d\t", CQ[i]);
            i = (i + 1) % MAX;
        }
    }
}

int menu()
{
    int ch;
    printf("\n \t Circular Queue Operations using ARRAY..");
    printf("\n -----------**********-------------\n");
    printf("\n 1. Insert ");
    printf("\n 2. Delete ");
    printf("\n 3. Display");
    printf("\n 4. Quit ");
    printf("\n Enter Your Choice: ");
    scanf("%d", &ch);
    return ch;
}

void main()
{
    int ch, data;
    do
    {
        ch = menu();
        switch(ch)
        {
            case 1:
                printf("\n Enter data: ");
                scanf("%d", &data);
                insertCQ(data);
                displayCQ();
                break;
            case 2:
                data = deleteCQ();
                if(data>=-9999)
                    printf("\n%d deleted from queue\n", data);
                displayCQ();
                break;
            case 3:
                displayCQ();
                break;
            case 4:
                return;
            default:
                printf("\n Invalid Choice ");
        }
    } while(1);
}