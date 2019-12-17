#include <stdio.h>
#include <malloc.h>
struct link
{
    int coef;
    int expo;
    struct link *next;
};
typedef struct link node;

//Take two inputs from the user (coef and expo) and create the node
node * getnode()
{
    int coef, expo;
    node *newnode;
    newnode = (node *) malloc(sizeof(node));
    printf("\nEnter the coefficient:\n");
    scanf("%d", &coef);
    newnode->coef = coef;
    printf("\nEnter the exponent:\n");
    scanf("%d", &expo);
    newnode->expo = expo;
    newnode->next = NULL;
    
    return newnode;
}

//Create the polynimial by continuously asking the user if he wants to add more node or not. 
//If the user says no then break. Otherwise, create a newnode by calling getnode()
//Then traverse end of p and insert the new node
//Finally return p
node * create_poly (node *p )
{
    int ch = 1;
    node *temp,*newnode;
    temp = p;
    if(temp != NULL){
        while(temp->next != NULL){
            temp = temp->next;
        }
    } 
    while(ch == 1){
       printf("\nWould you like to add a new node?(1 = yes, 0 = no)\n");
       scanf("%d", &ch);
       if(ch != 1){
           break;
       } else {
           newnode = getnode();
           if(temp == NULL){
               temp = newnode;
               p = newnode;
           } else {
           temp->next = newnode;
           temp = temp->next;
           }
       }
    }
    return p;
}

//Display the values (coef and expo) in the nodes of the link list pointed by p 
void display (node *p){
    node *temp;
    temp = p;
    printf("\n");
    while(temp != NULL){
        printf("(%dx^%d)\n",temp->coef, temp->expo);
        if(temp->next != NULL){
            printf(" + \n");
        }
        temp = temp->next;
    }
    return;
}

// Add the content of p1 and p2 (polynomial addition) and print the result
void add_poly(node *p1,node *p2)
{
    node *newnode, *temp1, *temp2;
    printf("\n");
    temp1 = p1;
        temp2 = p2;
        temp1 = p1;
    while(1){
        if( p1 == NULL || p2 == NULL ){
            break;
        }
        if(temp1->expo == temp2->expo){
            printf("(%dx^%d)\n", (temp1->coef + temp2->coef), temp1->expo);
            temp1 = temp1->next;
            temp2 = temp2->next;
        } else if ((temp1->expo > temp2->expo) || (temp2 == NULL)){
            printf("(%dx^%d)\n", temp1->coef, temp1->expo);
            temp1 = temp1->next;
        } else if ((temp1->expo < temp2->expo) || (temp1 == NULL)){
            printf("(%dx^%d)\n", temp2->coef, temp2->expo);
            temp2 = temp2->next;
        }
        if((temp1 != NULL) || (temp2 != NULL)){
            printf(" + \n");
        }
        if( (temp1 == NULL) && (temp2 == NULL)){
            break;
        }
    }
    printf("\n");
    //print the rest of elements of the other link list (which has still more nodes)
    return;
}


void main()
{
    node *poly1 = NULL ,*poly2 = NULL;
    printf("\nEnter First Polynomial..(in ascending-order of exponent)\n");
    poly1 = create_poly (poly1);
    printf("Enter Second Polynomial..(in ascending-order of exponent)\n");
    poly2 = create_poly (poly2);
    printf("\nDisplaying Polynomial 1: \n");
    display (poly1);
    printf("\nDisplaying Polynomial 2: \n");
    display (poly2);
    printf("\nResultant Polynomial : \n");
    add_poly(poly1, poly2);
    return;
}