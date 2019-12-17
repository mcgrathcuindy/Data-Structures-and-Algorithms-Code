# include <stdio.h>
# include <stdlib.h>
struct slinklist
{
    int data;
    struct slinklist *next;
};
typedef struct slinklist node;
node *start = NULL;
int menu()
{
    int ch;
    printf("\n 1.Create a list ");
    printf("\n--------------------------");
    printf("\n 2.Insert a node at beginning ");
    printf("\n 3.Insert a node at end");
    printf("\n 4.Insert a node at middle");
    printf("\n--------------------------");
    printf("\n 5.Delete a node from beginning");
    printf("\n 6.Delete a node from Last");
    printf("\n 7.Delete a node from Middle");
    printf("\n--------------------------");
    printf("\n 8.Traverse the list (Left to Right)");
    printf("\n 9.Traverse the list (Right to Left)");
    printf("\n--------------------------");
    printf("\n 10. Count nodes ");
    printf("\n 11. Exit ");
    printf("\n 12. Count Occurance ");
    printf("\n 13. Search and Delete");
    printf("\n\n Enter your choice: ");
    scanf("%d",&ch);
    return ch;
}

//Take the data as input from user and create a node for the link list
node* getnode()
{
    node * newnode;
    newnode = (node *) malloc(sizeof(node));
    printf("\n Enter data: ");
    scanf("%d", &newnode -> data);
    newnode -> next = NULL;
    return newnode;
}

int count_occurance(int n)
{
    int count = 0;
    node * temp = start;
    while(temp != NULL)
    {
        if(temp->data == n)
        {
            temp = temp->next;
            count++;
        }
        else
            temp = temp->next;
    }
    return count;
}

void searchanddelete(int n)
{
    if(start==NULL){
        printf("It's an empty list...\n");
        return;
    }
    
    int flag = 0;
    node * temp = start, *current = start;
    
    if(start->data == n){
        temp = start;
        start = temp->next;
        free(temp);
        printf("\n%d succesfully deleted\n", n);
        return;
    }
    
    while(temp->next != NULL)
    {
        if(temp->next->data == n)
        {
            flag++;
            current = temp->next;
            break;
        }
        else 
            temp = temp -> next;
    }
    if(flag == 0){
        printf("\n Value not found in list...\n");
        return;
    }
    else if(current->next != NULL)
    {
        temp -> next = current -> next;
        free(current);
        printf("\n%d succesfully deleted\n", n);
    }
    else if(current->next == NULL)
    {
        temp -> next = NULL;
        free(current);
        printf("\n%d succesfully deleted\n", n);
    }
    
}

//Count the number of node in the link list
int countnode(node *ptr)
{
    int count=0;
    while(ptr != NULL)
    {
        count++;
        ptr=ptr->next;
    }
    return (count);
}

//Create a link list with n nodes
void createlist(int n)
{
    int i;
    node *newnode;
    node *temp;
    for(i = 0; i < n; i++)
    {
        newnode = getnode();
        if(start == NULL)
        {
            start = newnode;
        }
        else
        {
            temp = start;
            while(temp -> next != NULL)
                temp = temp -> next;
            temp -> next = newnode;
        }
    }
    return;
}

//Print the data value of each node in the link list
void traverse()
{
    node *temp;
    temp = start;
    printf("\n The contents of List (Left to Right): \n");
    if(start == NULL)
    {
        //print a message and return
        printf("\n Empty List");
    }
    else
    {
        while(temp != NULL)
        {
            //print the data item and go to the next node
            printf("%d-->",temp->data);
            temp = temp->next;
        }
    }
    printf(" X ");
    return;
}

//Print the data value of each node in the link list in reverse order using recursion
void rev_traverse(node *start)
{
    if (start == NULL) 
       return; 
  
    rev_traverse(start->next); 
 
    printf("%d-->", start->data); 
}

//Insert a node at the beginning of the link list
void insert_at_beg()
{
    node *newnode;
    newnode = getnode();
    if(start == NULL)
    {
        start=newnode;    
    }
    else
    {
        
        newnode->next=start;
        start=newnode;
    }
    return;
}

//Insert a node at the end of the link list
void insert_at_end()
{
    node *newnode, *temp;
    newnode = getnode();
    temp=start;
    //if no node...
    while(temp->next!=NULL)
        temp=temp->next;
    //else
    temp->next=newnode;
    return;
}

//Insert a node at the intermediate position of the link list
void insert_at_mid()
{
    node *newnode, *temp, *prev;
    int pos, nodectr, ctr = 1;
    newnode = getnode();
    printf("\n Enter the position: ");
    scanf("%d", &pos);
    nodectr = countnode(start);
    /*if(pos > 1 && pos < nodectr)
    {
        temp = prev = start;
        while(ctr < pos)
        {
            prev = temp;
            temp = temp -> next;
            ctr++;
        }
        prev -> next = newnode;
        newnode -> next = temp;
        //can you solve it with just the temp pointer??
    }*/
    if(pos > 1 && pos < nodectr)
    {
        temp = start;
        while(ctr < pos)
        {
            temp = temp -> next;
            ctr++;
        }
        newnode -> next = temp->next;
        temp->next=newnode;
    }
    else
        printf("position %d is not a middle position", pos);
    return;
}

//Delete a node at the beginning of the link list
void delete_at_beg()
{
    node *temp;
    if(start==NULL){
        printf("It's an empty list...\n");
        return;
    }
    else
    {
        temp = start;
        start = temp->next;
        free(temp);
        printf("\n node deleted\n");
    }
    return;
}

//Delete a node at the end of the link list
void delete_at_last()
{
    node *temp, *prev;
    if(start == NULL)
    {
        printf("\n Empty List..");
        return ;
    }
    else
    {
        temp = start;
        prev = start;
        while(temp -> next != NULL)
        {
            prev = temp;
            temp = temp -> next;
        }
        prev -> next = NULL;
        free(temp);
        printf("\n Node deleted ");
    }
    return;
}

//Delete a node at the intermediate position of the link list
void delete_at_mid()
{
    int ctr = 1, pos, nodectr;
    node *temp, *prev;
    if(start == NULL)
    {
        printf("\n Empty List..");
        return ;
    }
    else
    {
        printf("\n Enter position of node to delete: ");
        scanf("%d", &pos);
        nodectr = countnode(start);
        if(pos > nodectr)
        {
            printf("\nThisnode doesnot exist");
        }
        if(pos > 1 && pos < nodectr)
        {
            temp = prev = start;
            while(ctr < pos)
            {
                prev = temp;
                temp = temp -> next;
                ctr ++;
            }
            prev -> next = temp -> next;
            free(temp);
            printf("\n Node deleted..");
        }
        else
        {
            printf("\n Invalid position..");
            //getch();
        }
    }
    return;
}
//free the entire link list
void deleteList()  
{  
    node * temp, *current;
    
    if(start == NULL)
    {
        printf("List empty...\n");
        return;   
    }
    else
    {
        current = temp = start;
        while(current != NULL){
            current = temp -> next;
            free(temp);
            temp = current;
        }
    }
    start = NULL;
    return;
}
//Driver function for the single link list operations
void main()
{
    int ch, n;
    while(1)
    {
        ch = menu();
        switch(ch)
        {
            case 1:
                if(start == NULL)
                {
                    printf("\n Number of nodes you want to create: ");
                    scanf("%d", &n);
                    createlist(n);
                    printf("\n List created..");
                }
                else
                    printf("\n List is already created..");
                break;

            case 2:
                insert_at_beg();
                break;
            
            case 3:
                insert_at_end();
                break;

            case 4:
                insert_at_mid();
                break;

            case 5:
                delete_at_beg();
                break;

            case 6:
                delete_at_last();
                break;

            case 7:
                delete_at_mid();
                break;
            
            case 8:
                traverse();
                break;

            case 9:
                printf("\n The contents of List (Right to Left): \n");
                rev_traverse(start);
                printf(" X ");
                break;

            case 10:
                printf("\n No of nodes : %d ", countnode(start));
                break;

            case 11 :
                deleteList();
                exit(0);
                break;
                
            case 12 :
                printf("\n What number do you want to count? ");
                scanf("%d", &n);
                printf("\n %d occurs %d times \n", n, count_occurance(n));
                break;
                
            case 13 :
                printf("\n What number do you want to search and delete? ");
                scanf("%d", &n);
                searchanddelete(n);
                break;
                
            default:
                printf("Wrong Choice\n");
                break;
        }
    }
    return;
}