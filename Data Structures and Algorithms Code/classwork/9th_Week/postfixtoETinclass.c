#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Used for a binary tree node.
typedef struct bintreenode 
{
    char data;
    struct bintreenode* left;
    struct bintreenode* right;
}btreenode;

int top=-1;
btreenode* stack[20];
//btreenode* node;

//modify push
void push(btreenode* node)
{
        stack[++top] = node;
}

//modify pop
btreenode * pop()
{
    return(stack[top--]);
}

btreenode* create_node(char val)
{
    btreenode *temp;
    temp = (btreenode *) malloc(sizeof(btreenode)) ;
    temp -> data=val;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}

// Prints all the items in the tree rooted at root via an in order traversal.
void inOrder(btreenode* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%c ", root->data);
        inOrder(root->right);
    }
}

int isOperator(char c) 
{ 
    if(c == '+' || c == '-' || c == '/' || c == '*')
        return 1;
    else return 0;
} 
  

// Returns root of constructed tree for given postfix expression 
btreenode* constructTree(char postfix[]) 
{ 
    int i = 0;
    btreenode * temp;
    while(postfix[i] != '\0')
    {
        if(!isOperator(postfix[i]))
        {
            temp = create_node(postfix[i]);
            push(temp);
        }
        else
        {
            temp = create_node(postfix[i]);
            temp -> right = pop();
            temp -> left = pop();
            push(temp);
        }
    i++;
    }
    return pop();
} 


// This function receives the root of the syntax tree and recursively evaluates it  
int evalExpressionTree(btreenode* root)  
{  
    if(root == NULL)
        return 0;
    if(root -> right == NULL && root -> left == NULL)
        return root -> data -'0';
    else
    {
        if(isOperator(root -> data))
        {
            if(root -> data == '+')
                return evalExpressionTree(root -> left) + evalExpressionTree(root -> right);
            if(root -> data == '-')
                return evalExpressionTree(root -> left) - evalExpressionTree(root -> right);
            if(root -> data == '*')
                return evalExpressionTree(root -> left) * evalExpressionTree(root -> right);
            if(root -> data == '/')
                return evalExpressionTree(root -> left) / evalExpressionTree(root -> right);
        }
    }
}  



// Driver program to test above 
int main() 
{ 
    //char postfix[] = "ab+ef*g*-";
    char postfix[] = "54*12-+"; //ans: 19
    //char postfix[] = "345*6/+"; //Ans 6
    //char postfix[]="48+65-*32-22+*/"; //Ans 3   
    btreenode* root = constructTree(postfix); 
    printf("Inorder traversal of the expression tree is \n"); 
    inOrder(root);
    printf("\nEvaluation result of the expression tree is %d \n", evalExpressionTree(root));
    return 0; 
} 