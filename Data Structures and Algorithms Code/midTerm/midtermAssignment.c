/*
Name:  Alex Scull, Christopher McGrath
Date:  Midterm Assignment, Doubly Circular Linked List
Desc:  October 15th, 2019
*/
# include <stdio.h>
# include <stdlib.h>

struct cdlinklist
{
    struct cdlinklist *left;
    int data;
    struct cdlinklist *right;
};
typedef struct cdlinklist node;
node *start = NULL;
int nodectr;

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

int menu()
{
    int ch;
    printf("\n 1. Create ");
    printf("\n\n--------------------------");
    printf("\n 2. Insert a node at Beginning");
    printf("\n 3. Insert a node at End");
    printf("\n 4. Insert a node at Middle");
    printf("\n\n--------------------------");
    printf("\n 5. Delete a node from Beginning");
    printf("\n 6. Delete a node from End");
    printf("\n 7. Delete a node from Middle");
    printf("\n\n--------------------------");
    printf("\n 8. Display the list from Left to Right");
    printf("\n 9. Display the list from Right to Left");
    printf("\n 10.Search a data item in the list");
    printf("\n 11.Exit");
    printf("\n\n Enter your choice: ");
    scanf("%d", &ch);
    return ch;
}

void cdll_createlist(int n)
{
    nodectr = n;
    int i;
    node *newnode, *temp;
    if(start == NULL)
    {
        newnode = getnode();
        start = newnode;
        start -> right = start;
        start -> left = start;
        
        for(i = 1; i < n; i++)
        {
            newnode = getnode();
            temp = start;
            while(temp -> right != start)
                temp = temp -> right;
            temp -> right = newnode;
            start -> left = temp -> right;
            temp -> right -> left = temp; 
            temp -> right -> right = start;
        }
    }
    else
        printf("\n List already exists..");
    return;
}
    
void cdll_display_left_right()
{
    node *temp;
    temp = start;
    if(start == NULL)
        printf("\n Empty List");
    else
    {
        printf("\n The contents of List: ");
        printf(" %d ", temp -> data);
        temp = temp -> right;
        while(temp != start)
        {
            printf(" %d ", temp -> data);
            temp = temp -> right;
        }
    }
    return;
}

void cdll_display_right_left()
{
    node *temp, *last;
    temp = start;
    if(start == NULL)
    {
        printf("List is empty...\n");
        return;
    }
    else if(temp -> left == temp && temp -> right == temp)
    {
        printf("\n The contents of list right to left: ");
        printf(" %d ", temp -> data);
    }
    else 
    {
        last = start -> left;
        printf("\n The contents of list right to left: ");
        
        while(last -> left != start -> left)
        {
            printf(" %d ", last -> data);
            last = last -> left;
        }
        printf(" %d ", start -> data);
    }
    return;
}

void cdll_search()
{
    node *temp = start;
    int value = 0, pos = 1, ctr = 0;
    
    printf("What value do you want to search for?\n");
    scanf("%d", &value);
    printf("\n");
    
    if(start == NULL)
        printf("List is empty...\n");
    else
    {
        if(temp -> data == value)
        {
            printf("\t%d found at position %d\n", value, pos);
            ctr++;
        }
        temp = temp -> right;
        while(temp != start)
        {
            pos++;
            if(temp -> data == value)
            {
                printf("\t%d found at position %d\n", value, pos);
                temp = temp -> right;
                ctr++;
            }
            else
                temp = temp -> right;
        }
        printf("\n\t%d occurs %d time(s)\n", value, ctr);
    }
    return;
}

void cdll_insert_beg()
{
    node *newnode, *last, *temp = start;
    newnode = getnode();
    if(start == NULL)
    {
        start = newnode;
        start -> right = start;
        start -> left = start;
    }
    else if(temp -> left == temp && temp -> right == temp)
    {
        newnode -> right = start;
        newnode -> left = start;
        start -> left = newnode;
        start -> right = newnode;
        start = newnode;

    }
    else
    {
            last = start -> left;
            last -> right = newnode;
            newnode -> right = start;
            start -> left = newnode;
            newnode -> left = last;
            start = newnode;
    }
    printf("\n Node inserted at beginning..");
    nodectr++;
    return;
}

void cdll_insert_end()
{
    node *newnode, *last, *temp = start;
    newnode = getnode();
    if(start == NULL){
        start = newnode;
        start -> right = start;
        start -> left = start;
    }
    else if(temp -> left == temp && temp -> right == temp)
    {
        temp -> right = newnode;
        temp -> left = newnode;
        temp -> right -> left = temp;
        temp -> right -> right = temp;
    }
    else
    {
        last = start -> left;
        last -> right = newnode;
        last -> right -> right = start;
        last -> right -> left = last;
        start -> left = last -> right;
    }
    printf("\n Node inserted at end..");
    nodectr++;
    return;
}

void cdll_insert_mid()
{
    node *newnode, *temp, *left;
    int pos, ctr = 2;
    newnode = getnode();
    printf("\nPlease Enter a Position: ");
    scanf("%d", &pos);
    if(pos > nodectr){
        printf("Position Not in Range");
        return;
    }
    if(pos > 1 && pos < nodectr){
        temp = start;
        left = temp;
        while(ctr < pos){
            left = temp;
            temp = temp -> right;
            ctr++;
        }
        newnode -> left = temp;
        newnode -> right = temp -> right;
        temp -> right -> left = newnode;
        temp -> right = newnode;
        nodectr++;
        printf("Node inserted at middle");
    }
    else
        printf("position %d of list is not a middle position ", pos);
        
    return;
}

void cdll_delete_beg()
{
    node *temp = start, *last = start;
    if( start == NULL)
    {
        printf("Empty List...\n");
        return;
    }
    else if(temp -> left == temp && temp -> right == temp)
    {
        free(temp);
        start = NULL;
        printf("Last remaining node deleted...\n");
        nodectr--;
        return;
    }
    else
    {
        while(last -> right != start)
            last = last -> right;
        start = start -> right;
        start -> left = last;
        last -> right = start;
        free(temp);
        nodectr--;
        printf("Node deleted...");
    }
    return;
}

void cdll_delete_last()
{
    node *temp = start, *last = start;
    if(start == NULL)
    {
        printf("List Empty...\n");
        return;
    }
    else if(temp -> left == temp && temp -> right == temp)
    {
        free(temp);
        start = NULL;
        printf("Last remaining node deleted...\n");
        nodectr--;
        return;
    }
    else
    {
        while(temp -> right != start)
        {
            last = temp;
            temp = temp -> right;
        }
        free(temp);
        last -> right = start;
        start -> left = last;
        nodectr--;
        if(nodectr == 0)
            start == NULL;
        printf("Node deleted...\n");
    }
    
    return;
}

void cdll_delete_mid()
{
    int i = 0, pos;
    node *temp;
    if(start == NULL)
    {
        printf("\n Empty List");
        return;
    }
    else
    {
        printf("\n Enter the position of the node to delete: ");
        scanf("%d", &pos);
        if(pos > nodectr)
        {
            printf("\nthis node does not exist");
            return;
        }
        if(pos > 1 && pos < nodectr)
        {
            temp = start;
            i= 1;
            while(i < pos)
            {
                temp = temp -> right;
                i++;
            }
            temp -> right -> left = temp -> left;
            temp -> left -> right = temp -> right;
            free(temp);
            nodectr--;
            printf("\n node deleted..");
        }
        else
        {
            printf("\n It is not a middle position..");
        }
    }
    return;
}

void main(void)
{
    int ch,n;
    while(1)
    {
        ch = menu();
        switch( ch)
        {
            case 1 :
                printf("\n Enter Number of nodes to create: ");
                scanf("%d", &n);
                cdll_createlist(n);
                printf("\n List created..");
                break;
            case 2 :
                cdll_insert_beg();
                break;
            case 3 :
                cdll_insert_end();
                break;
            case 4 :
                cdll_insert_mid();
                break;
            case 5 :
                cdll_delete_beg();
                break;
            case 6 :
                cdll_delete_last();
                break;
            case 7 :
                cdll_delete_mid();
                break;
            case 8 :
                cdll_display_left_right();
                break;
            case 9 :
                cdll_display_right_left();
                break;
            case 10 :
                cdll_search();
                break;
            case 11:
                exit(0);
        }
    }
    return;
}