/*
Christopher McGrath
CSCI 240 HW3.c polynomial addition
9/24/19
*/
#include <stdio.h>
#include <malloc.h>
#include <math.h>
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
    node * newnode;
    newnode = (node*)malloc(sizeof(node));
    printf("\nEnter the coefficient for the node: ");
    scanf("%d", &newnode -> coef);
    printf("(\nEnter the expo for the node: ");
    scanf("%d", &newnode -> expo);
    newnode -> next = NULL;
    return newnode;
}

//Create the polynimial by continuously asking the user if he wants to add more node or not. 
//If the user says no then break. Otherwise, create a newnode by calling getnode()
//Then traverse end of p and insert the new node
//Finally return p
node * create_poly (node *p )
{
    int ch;
    node *temp,*newnode;
    while( 1 )
    {
       printf("\nWould you like to add a node? (1 to add) (0 to quit)\n");
       scanf("%d", &ch);
       if(ch == 1)
       {
            newnode = getnode();
            if(p == NULL)
                p = newnode;
            else 
            {
                temp = p;
                while(temp -> next != NULL)
                    temp = temp -> next;
                temp -> next = newnode;
            }
       }
        else if(ch == 0)
            break;
        else 
            printf("\nPlease enter a valid option 1 or 0\n");
    }
    return p;
}

//Display the values (coef and expo) in the nodes of the link list pointed by p 
void display (node *p)
{
    node *temp;
    temp = p;
    if(p == NULL)
        printf("Empty list...\n");
    else
    {
        while(temp -> next != NULL)
        {
            if(temp -> coef > 0)
                printf("+ %d(X^%d) ", temp -> coef, temp -> expo);
            else if(temp -> coef < 0)
                printf("- %d(X^%d) ", abs(temp -> coef), temp -> expo);
            temp = temp -> next;
        }
            if(temp -> coef > 0)
                printf("+ %d(X^%d)\n", abs(temp -> coef), temp -> expo);
            else if(temp -> coef < 0)
                printf("- %d(X^%d)\n", abs(temp -> coef), temp -> expo);
    }
}

// Add the content of p1 and p2 (polynomial addition) and print the result
void add_poly(node *p1,node *p2)
{
    node *newnode;
    while(1)
    {  
        if( p1 == NULL && p2 == NULL )
            break;
        else if( p1 == NULL && p2 != NULL)
        {
            display(p2);
            break;
        }
        else if( p1 != NULL && p2 == NULL)
        {
            display(p1);
            break;
        }
        else
        {
            if(p1 -> expo == p2 -> expo)
            {
                newnode = (node*)malloc(sizeof(node));
                newnode -> coef = p1 -> coef + p2 -> coef;
                newnode -> expo = p1 -> expo;
                newnode -> next = NULL;
                if(newnode -> coef > 0)
                    printf("+ %d(X^%d) ", newnode -> coef, newnode -> expo);
                else if(newnode -> coef < 0)
                    printf("- %d(X^%d) ", abs(newnode -> coef), newnode -> expo);
                p1 = p1 -> next;
                p2 = p2 -> next;
                free(newnode);
            }
            else if(p1 -> expo > p2 -> expo)
            {
                if(p1 -> coef > 0)
                    printf("+ %d(X^%d) ", p1 -> coef, p1 -> expo);
                else if(p1 -> coef < 0)
                    printf("- %d(X^%d) ", abs(p1 -> coef), p1 -> expo);
                p1 = p1 -> next;
            }
            else if(p1 -> expo < p2 -> expo)
            {
                if(p2 -> coef > 0)
                    printf("+ %d(X^%d) ", p2 -> coef, p2 -> expo);
                else if(p2 -> coef < 0)
                    printf("- %d(X^%d) ", abs(p2 -> coef), p2 -> expo);
                p2 = p2 -> next;
            }
        }
    }
    printf("\n");
    //print the rest of elements of the other link list (which has still more nodes)
    return;
}


void main()
{
    node *poly1 = NULL ,*poly2 = NULL;
    printf("\nEnter First Polynomial..(in descending-order of exponent)");
    poly1 = create_poly (poly1);
    printf("Enter Second Polynomial..(in descending-order of exponent)");
    poly2 = create_poly (poly2);
    printf("\nDisplaying Polynomial 1: ");
    display (poly1);
    printf("\nDisplaying Polynomial 2: ");
    display (poly2);
    printf("\nResultant Polynomial : ");
    add_poly(poly1, poly2);
    return;
}