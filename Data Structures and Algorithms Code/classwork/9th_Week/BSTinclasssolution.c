#include <stdio.h>
#include <stdlib.h>


struct tree_node 
{
  int data;
  struct tree_node *left;
  struct tree_node *right;
};

struct tree_node *create_node(int val);
void inorder(struct tree_node *current_ptr);
struct tree_node* insert(struct tree_node *root, struct tree_node *element);

struct tree_node* parent(struct tree_node *root, struct tree_node *node);
struct tree_node* minVal(struct tree_node *root);
struct tree_node* maxVal(struct tree_node *root);
int isLeaf(struct tree_node *node);
int hasOnlyLeftChild(struct tree_node *node);
int hasOnlyRightChild(struct tree_node *node);
struct tree_node* findNode(struct tree_node *current_ptr, int value);
struct tree_node* delete(struct tree_node* root, int value);

//These 4 are extra functions
int add(struct tree_node *current_ptr);
int find(struct tree_node *current_ptr, int val);
int numnodes(struct tree_node* root); 
int findKthSmallest(struct tree_node* root, int k);

int menu();

void main()
{
    struct tree_node *my_root=NULL, *temp_node;
    int k, done = 0, ans=1, val;
    do
    {
        ans = menu();
        switch(ans)
        {
            case 1 :
                // Get value to insert.
                printf("What value would you like to insert?");
                scanf("%d", &val);
                temp_node = create_node(val); // Create the node.
            
                // Insert the value.
                my_root = insert(my_root, temp_node);
                break;
            
            case 2 :

                break;
            
            case 3 :
                printf("What value would you like to search for?\n");
                scanf("%d", &val);
                if (find(my_root, val))
                    printf(" Found %d in the tree.\n", val);
                else
                    printf(" Did not find %d in the tree.\n", val); 
                break;
            
            case 4 :
                printf("The sum of the nodes in your tree is %d.\n", add(my_root));
                break;
            
            case 5:
                // Print the resulting tree.
                printf("Here is an inorder traversal of your tree: ");
                inorder(my_root);
                printf("\n");
                break;
            
            case 6:
                printf("Enter the value of k to find the kth smallest element in your tree: ");
                scanf("%d", &k);
                printf("The sum of the nodes in your tree is %d.\n", findKthSmallest(my_root, k));
                break;
            
            case 7 :
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
  printf("4. Print the sum of the nodes in your tree.\n");
  printf("5. Print out an inorder traversal of your tree.\n");
  printf("6. Print out the kth smallest value in your tree.\n");
  printf("7. Quit.\n");
  scanf("%d", &ans);
  return ans;
}  

struct tree_node* create_node(int val) 
{
    // Allocate space for the node, set the fields.
    struct tree_node* temp;
    temp = (struct tree_node*)malloc(sizeof(struct tree_node));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp; // Return a pointer to the created node.
}

void inorder(struct tree_node *current_ptr) {

  // Only traverse the node if it's not null.
  if (current_ptr != NULL) {
    inorder(current_ptr->left); // Go Left.
    printf("%d ", current_ptr->data); // Print the root.
    inorder(current_ptr->right); // Go Right.
  }
}

//version 1
struct tree_node* insert(struct tree_node *root, struct tree_node *element) 
{
  // Inserting into an empty tree.
    if (root == NULL) 
        return element;
    else 
    {
        // element should be inserted to the right.
        if (element->data > root->data) 
        {
            // There is a right subtree to insert the node.
            if (root->right != NULL)
                root->right = insert(root->right, element);
            // Place the node directly to the right of root.
            else
                root->right = element;
        }
        // element should be inserted to the left.
        else 
        {
            // There is a left subtree to insert the node.
            if (root->left != NULL)
                root->left = insert(root->left, element);
            // Place the node directly to the left of root.
            else
                root->left = element;
        } 
        // Return the root pointer of the updated tree.
        return root;
    }
}

/*
//version 2
struct tree_node* insert(struct tree_node *root, struct tree_node *element) 
{
  // Inserting into an empty tree.
    if (root == NULL) 
        root= element;
    else 
    {
        // element should be inserted to the right.
        if (element->data > root->data) 
        {
            root->right = insert(root->right, element);
        }
        // element should be inserted to the left.
        else 
        {
            root->left = insert(root->left, element);
        } 
    }
    return root;
}

*/

// Returns the number of nodes in the tree pointed to by root.
int numnodes(struct tree_node* root) 
{
    if (root == NULL) return 0;
        return 1 + numnodes(root->left) + numnodes(root->right);
}

// Guaranteed that k is in between 1 and the number of nodes in the tree 
// pointed to by root.
int findKthSmallest(struct tree_node* root, int k) 
{
    int numNodesLeft =  numnodes(root->left);
    if (numNodesLeft >= k) 
        return findKthSmallest(root->left, k);
    else if (numNodesLeft == k-1)
        return root->data;
    else
        return findKthSmallest(root->right, k-numNodesLeft-1);
}

int find(struct tree_node *current_ptr, int val) 
{
    // Check if there are nodes in the tree.
    if (current_ptr != NULL) 
    {
        // Found the value at the root.
        if (current_ptr->data == val)
            return 1;
        // Search to the left.
        if (val < current_ptr->data) 
            return find(current_ptr->left, val);
        // Or...search to the right.
        else 
            return find(current_ptr->right, val);
    }
    else
        return 0;
}

int add(struct tree_node *current_ptr) 
{
    if (current_ptr != NULL)
        return current_ptr->data+add(current_ptr->left)+add(current_ptr->right);
    else
        return 0;
}

// Returns the parent of the node pointed to by node in the tree rooted at
// root. If the node is the root of the tree, or the node doesn't exist in
// the tree, null will be returned.
struct tree_node* parent(struct tree_node *root, struct tree_node *node) 
{

}

// Returns a pointer to the node storing the minimum value in the tree
// with the root, root. Will not work if called with an empty tree.
struct tree_node* minVal(struct tree_node *root) 
{

}


// Returns a pointer to the node storing the maximum value in the tree
// with the root, root. Will not work if called with an empty tree.
struct tree_node* maxVal(struct tree_node *root) 
{

}

// Returns 1 if node is a leaf node, 0 otherwise.
int isLeaf(struct tree_node *node) 
{

}

// Returns 1 iff node has a left child and no right child.
int hasOnlyLeftChild(struct tree_node *node) 
{

}

// Returns 1 iff node has a right child and no left child.
int hasOnlyRightChild(struct tree_node *node) 
{

}

// Returns a pointer to a node that stores value in it in the subtree
// pointed to by current_ptr. NULL is returned if no such node is found.
struct tree_node* findNode(struct tree_node *current_ptr, int value) 
{

}

// Will delete the node storing value in the tree rooted at root. The
// value must be present in the tree in order for this function to work.
// The function returns a pointer to the root of the resulting tree.
struct tree_node* delete(struct tree_node* root, int value) 
{

  
    // Take care of the case where the node to delete is a leaf node. 
        //3 cases
        // Deleting the only node in the tree.
       
        // Deletes the node if it's a left child.
        
        // Deletes the node if it's a right child.
    
    // Take care of the case where the node to be deleted only has a left child.
        //3 cases
        // Deleting the root node of the tree.
       
        // Deletes the node if it's a left child of its parent
        
        // Deletes the node if it's a right child of its parent
    

    // Takes care of the case where the deleted node only has a right child.
        //3 cases
        // Deleting the root node of the tree.
       
        // Deletes the node if it's a left child of its parent
        
        // Deletes the node if it's a right child of its parent
    
    
    // Find the new physical node to delete.
    // Restore the data to the original node to be deleted.
    
    return root;
}