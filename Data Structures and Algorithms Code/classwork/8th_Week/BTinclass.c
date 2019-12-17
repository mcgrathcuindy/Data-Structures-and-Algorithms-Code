#include <stdio.h>
#include <stdlib.h>

// Used for a binary tree node.
typedef struct bintreenode 
{
    int data;
    struct bintreenode* left;
    struct bintreenode* right;
} btreenode;

// Used for a node in the queue.
typedef struct node 
{
    btreenode* nodePtr;
    struct node* next;
} node;

// Used to represent the queue efficiently.
typedef struct queue 
{
    node* front;
    node* back;
} queue;

// Some test functions.
void insert(btreenode* root, int value);
void deleteDeepest(btreenode* root, btreenode* d_node); 
void deletion(btreenode* root, int value);
void bfs(btreenode* root); //level order traversal

// In class activity
void preOrder(btreenode* root);
void inOrder(btreenode* root);
void postOrder(btreenode* root);

int search(btreenode* root, int value);
int searchNonRecursive(btreenode* root, int value);
int height(btreenode* root);
int numNodesOneChild(btreenode* root);
int numNodesOneChildNonRecursive(btreenode* root);
void freeTree(btreenode* root);

// Queue functions.
void init(queue* q);
int empty(queue* q);
void enqueue(queue* q, btreenode* item);
btreenode* dequeue(queue* q);

btreenode* create_node(int val);

int menu();

void main()
{
    btreenode *root, *temp_node;
    int k, done = 0, ans=1, val;
    
    // Create tree 
    root = create_node(2); 
    root->left = create_node(7); 
    root->right = create_node(5); 
    root->left->right = create_node(6); 
    root->left->right->left = create_node(1); 
    root->left->right->right = create_node(11); 
    root->right->right = create_node(9); 
    root->right->right->left = create_node(4); 
  
    do
    {
        ans = menu();
        switch(ans)
        {
            case 1 :
                // Get value to insert.
                
                break;
            
            case 2 :
                
                break;
                
            case 3 :
                printf("What value would you like to search for?\n");
                scanf("%d", &val);
                if (search(root, val))
                    printf(" Found %d in the tree.\n", val);
                else
                    printf(" Did not find %d in the tree.\n", val); 
                break;
            
            case 4 :
                printf("What value would you like to search for?\n");
                scanf("%d", &val);
                if (searchNonRecursive(root, val))
                    printf(" Found %d in the tree.\n", val);
                else
                    printf(" Did not find %d in the tree.\n", val); 
                break;
            
            case 5 :
                printf("Here is an inorder traversal of your tree: ");
                inOrder(root);
                printf("\n");
                break;
            
            case 6:
                // Print the resulting tree.
                printf("Here is an preorder traversal of your tree: ");
                preOrder(root);
                printf("\n");
                break;
            
            case 7:
                // Print the resulting tree.
                printf("Here is an postorder traversal of your tree: ");
                postOrder(root);
                printf("\n");
                break;
            
            case 8:
                // Print the resulting tree.
                printf("Here is an level torder traversal of your tree: ");
                bfs(root);
                printf("\n");
                break;
                
            case 9:
                // Print the resulting tree.
                printf("Height of the tree: %d", height(root));
                printf("\n");
                break;
                
            case 10:
                printf("Number of nodes with one child: %d", numNodesOneChild(root));
                printf("\n");
                break;
            
            case 11:
                printf("Number of nodes with one child: %d", numNodesOneChildNonRecursive(root));
                printf("\n");
                break;
            
            case 12:
                freeTree(root);
                exit(0);
        }
    }while(1);
}

// Prints out the menu of choices for the user and returns their choice.
int menu() {

  int ans;
  printf("Here are your choices.\n");
  printf("1. Insert an item into your tree.\n");
  printf("2. Delete an item from your tree.\n");
  printf("3. Search for an item in your tree.\n");
  printf("4. Search for an item in your tree (Non recursive).\n");
  printf("5. Print tree. (Inorder)\n");
  printf("6. Print tree. (Preorder)\n");
  printf("7. Print tree. (Postorder)\n");
  printf("8. Print tree. (level order)\n");
  printf("9. Find height of the tree.\n");
  printf("10. Find number of nodes with one child.\n");
  printf("11. Find number of nodes with one child (Non Recursive).\n");
  printf("12. Quit.\n");
  scanf("%d", &ans);
  return ans;
}  

btreenode* create_node(int val)
{
    btreenode* temp = (btreenode*)malloc(sizeof(btreenode));
    temp -> data = val;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}


// Prints a breadth first search traversal of the binary search tree rooted at root.
// In particular, values are printed row by row, from left to right (based on the common
// visualization of a binary tree.)
void bfs(btreenode* root) 
{

    return;
}

// Inserts a new node into the binary tree rooted at root with data set to value.
//The node is inserted to a node whose left/right child is NULL using level order traversal

void insert(btreenode* root, int value) 
{

    return;
}

// find the node to be deleted and also the deepest node
//copy the value of the deepest node to the node to be deleted
void deletion(btreenode* root, int value) 
{ 

    return; 
} 

// delete the deepest node  
void deleteDeepest(btreenode* root, btreenode* d_node) 
{ 
    
    return;
} 

// Returns 1 iff value is contained in the tree pointed to be root, 0 otherwise.
int search(btreenode* root, int value) 
{
    // Nothing is in an empty tree.
    if (root != NULL) 
    {
        if (root->data==value)
            return 1;            
        else
            return (search(root->left, value)||search(root->right, value));
    }
    else 
        return 0;
}

// Returns 1 iff value is contained in the tree pointed to be root, 0 otherwise.
int searchNonRecursive(btreenode* root, int value) 
{
    btreenode* temp;
    if (root==NULL)
        return 0;
    queue q;
    init(&q);
    enqueue(&q, root);

    // Run Breadth First Search.
    while (!empty(&q)) 
    {
        temp = dequeue(&q);
        if (root->data==value)
            return 1; 
        // Enqueue neighbors, first going left, then right.
        if (temp->left != NULL) enqueue(&q, temp->left);
        if (temp->right != NULL) enqueue(&q, temp->right);
    }
    printf("\n");
    return 0;
}

// Returns the height of the tree with root root.
int height(btreenode* root) 
{
    // Height of an empty tree.
    if (root == NULL) return -1;

    // Find out heights of left and right sides.
    int leftSide = height(root->left);
    int rightSide = height(root->right);

    // Choose the bigger one and add one.
    if (leftSide > rightSide)
        return leftSide+1;
    else
        return rightSide+1;

}

// Returns the number of nodes in the tree rooted at root with exactly 1 child.
int numNodesOneChild(btreenode* root) 
{
    // No nodes in the tree at all...
    if(root == NULL) return -1;
    
    int total=0;
    
    // Increase the value of total if this node has only one child.
    if((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL))
        total++;
    total = total + numNodesOneChild(root -> left) + numNodesOneChild(root -> right);
    // Then add up all the nodes on the left and the right.

    // Here is our answer.
    return total;
}

// Returns the number of nodes in the tree rooted at root with exactly 1 child.
int numNodesOneChildNonRecursive(btreenode* root) 
{
    btreenode *temp;
    int total = 0;
    queue q;
    init(&q);
    if (root == NULL)
        return 0;
    enqueue(&q, root);
    while(!empty(&q))
    {
        temp = dequeue(&q);
        if((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL))
            total++;
        if(temp->left)
            enqueue(&q, temp->left);
        if(temp->right)
            enqueue(&q, temp->right);
    }
    
    return total;
}

// Prints all the items in the tree rooted at root via an in order traversal.
void inOrder(btreenode* root) {
    if(root != NULL)
    {
        inOrder(root -> left);
        printf("%d ", root -> data);
        inOrder(root -> right);
    }
}

// Prints all the items in the tree rooted at root via an pre order traversal.
void preOrder(btreenode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}


// Prints all the items in the tree rooted at root via an post order traversal.
void postOrder(btreenode* root) 
{
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

// Frees all nodes in the tree rooted at root.
void freeTree(btreenode* root) 
{
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int add(btreenode* root)
{
    if(root != NULL)
        return root -> data + add(root -> left) + add(root -> right);
    else return 0;
}

// Initializes the queue pointed to by q to be empty.
void init(queue* q) {
    q->front = NULL;
    q->back = NULL;
}

// Returns 1 iff q is empty.
int empty(queue* q) {
    return q->front == NULL;
}

//passing queue to access front and back
//passing the btreenode that needs to be inserted in the link list
void enqueue(queue* q, btreenode* item) {

    // Creating the node format that would be inserted in the link list
    node* tmp = malloc(sizeof(node));
    tmp->nodePtr = item;
    tmp->next = NULL;

    // Special case - enqueuing into an empty queue.
    if (q->front == NULL) {
        q -> front = tmp;
        q -> back = tmp;
    }

    // Just link back to tmp and move back.
    else {
        q -> back -> next = tmp;
        q -> back = tmp;
    }
}

btreenode* dequeue(queue* q) 
{
    node* temp;
    // Indicates empty queue.
    if (q->front == NULL) return NULL;
    // Save the return value.
    btreenode * retval = q->front->nodePtr;

    // Special case: removing one node.
    if (q->front == q->back) 
    {
        temp = q -> front;
        free(temp);
        q->front = NULL;
        q->back = NULL;
    }
    // Normal case.
    else 
    {
        // Save the node to free.
        temp = q -> front;
        // Update the front.        
        q -> front = q -> front -> next;
        // Now free it.
        free(temp);
    }
    return retval;
    // Now return the btreenode ptr.

}
/*
enque
printf
insert left or right

1. use a temp pointer variable and a queue of node pointers
2. insert the root node pointer into the queue
3. while the queue is not empty:
    a. dequeue the top node pointer and put it in temp
    b. process the node.
    c. add the node's children to queue if they are not NULL
*/