/*
Christopher McGrath
Take input from user and delete all nodes greater than that value
I took some of these functions from doubleLinkedListInClass.c
10/9/19
*/
#include <stdio.h>
#include <stdlib.h>

struct dlinklist
{
    struct dlinklist *left;
    int data;
    struct dlinklist *right;
};
typedef struct dlinklist node;
node *start = NULL;

node* getnode()
{
    node * newnode;
    newnode = (node *) malloc(sizeof(node));
    printf("\n Enter data: ");
    scanf("%d", &newnode -> data);
    newnode -> left = NULL;
    newnode -> right = NULL;
    return newnode;
}

void createlist(int n)
{
    int i;
    node *newnode;
    node *temp;
    for(i = 0; i < n; i++)
    {
        newnode = getnode();
        if(start == NULL)
            start = newnode;
        else
        {
            temp = start;
            while(temp -> right)
            temp = temp -> right;
            temp -> right = newnode;
            newnode -> left = temp;
        }
    }
    return;
}

void traverse_left_to_right()
{
    node *temp;
    temp = start;
    printf("\n The contents of List: ");
    if(start == NULL )
        printf("\n Empty List\n");
    else
    {
        while(temp != NULL)
        {
            printf("\t %d ", temp -> data);
            temp = temp -> right;
        }
    }
    return;
}

void delete_greater_values(int n)
{
    node  * temp = start;
    
    while(temp != NULL && temp -> data > n)
    {
        if(temp -> right == NULL)
        {
            if(temp -> data > n)
            {
                free(temp);
                start = NULL;
                return;
            }
        }
        else
        {
            start = temp -> right;
            free(temp);
            temp = start;
        }
    } 
    
    while(temp -> right != NULL)
    {
        if(temp -> data > n)
        {
            node *newnode = temp;
            temp -> left -> right = temp -> right;
            temp -> right -> left = temp -> left;
            temp = temp -> left;
            free(newnode);
        }
        temp = temp -> right;
    }
    if(temp -> data > n)
    {
        temp -> left -> right = NULL;
        free(temp);
    }
    return;
}    

int main(void)
{
    int n = 0;
    printf(" How many nodes would you like in the list? ");
    scanf("%d", &n);
    createlist(n);
    
    printf(" Enter a value, and each value greater than it will be deleted: ");
    scanf("%d", &n);
    delete_greater_values(n);
    traverse_left_to_right();
    printf("\n");
    
    return 0;
}
