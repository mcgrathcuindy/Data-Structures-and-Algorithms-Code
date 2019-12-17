#include "stdio.h"
#include "stacklinklist.c"

int menu()
{
    int ch;
    printf("\n \tStack operations using pointers.. ");
    printf("\n -----------**********-------------\n");
    printf("\n 1. Push ");
    printf("\n 2. Pop ");
    printf("\n 3. Display");
    printf("\n 4. isEmpty ");
    printf("\n 5. Peek");
    printf("\n 6. Quit ");
    printf("\n Enter your choice: ");
    scanf("%d", &ch);
    return ch;
}

void main()
{
    int ch, data;
    node *newnode;
    node *start=NULL; //always points to the 1st node or NULL (if empty)
    node *top = NULL; //always points to the last node or NULL (if empty)

    do
    {
        ch = menu();
        switch(ch)
        {
            case 1:
                printf("\n Enter data: ");
                scanf("%d", &data);
                //newnode = getnode(data);
                push(&start, &top, data);
                break;
            case 2:
                data=pop(&start, &top);
                printf("%d", data);
                break;
            case 3:
                display(start, top);
                break;
            case 4:
                data=isEmpty(&top);
                if (data==1)
                    printf("stack is empty");
                else 
                    printf("stack is not empty");
                break;
            case 5:
                data=peek(&top);
                printf("%d", data);
                break;
            case 6:
                exit (0);
        }
    } while(1);
}


