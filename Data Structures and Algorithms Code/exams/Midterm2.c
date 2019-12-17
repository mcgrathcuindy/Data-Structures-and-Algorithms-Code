#include <stdio.h>
#include <stdlib.h>

typedef struct bintreenode 
{
    int count;
    int price;
    struct bintreenode* left;
    struct bintreenode* right;
}btreenode;

btreenode* create(int price, int count)
{
    btreenode* newnode = (btreenode*)malloc(sizeof(btreenode));
    newnode -> price = price;
    newnode -> count = count;
    newnode -> right = NULL;
    newnode -> left = NULL;
    return newnode;
}

int priceOfAllHouses(btreenode* root)
{
    if(root == NULL)
        return 0;
    return (root -> price * root -> count) + priceOfAllHouses(root -> left) + priceOfAllHouses(root -> right);
}


void inorder(btreenode* root)
{
    if(root != NULL)
    {
        inorder(root -> left);
        printf("%d, ", root -> price);
        inorder(root -> right);
    }
}

int inleftsubtree(btreenode* root,int k)
{
    int tempval = 0;
    if(root != NULL)
    {
        
        if(k == root -> price)
        {
            printf(" k is in left subtree ");
            tempval = 1;
        }
        inleftsubtree(root -> left,k);
        inleftsubtree(root -> right,k);
    }
    return tempval;
}

int inrightSubtree(btreenode* root, int k)
{
    int tempval = 0;
    if(root != NULL)
    {
        
        if(k== root -> price)
        {
            printf(" k is in right subtree ");
            tempval = 1;
        }
        inrightSubtree(root -> left,k);
        inrightSubtree(root -> right,k);
    }
    return tempval;
}

btreenode* lca(btreenode* root, int k1, int k2)
{
    if(inleftsubtree(root,k1) && inrightSubtree(root,k2) || inleftsubtree(root,k2)&& inrightSubtree(root, k1))
    {
        printf("lca found\n");
        return root;
    }
    if(inleftsubtree(root, k1) && inleftsubtree(root, k2))
        lca(root -> left,k1,k2);
    if(inrightSubtree(root,k1)&& inrightSubtree(root,k2))
        lca(root -> right,k1,k2);
}

int main(void)
{
    btreenode* root = create(100,3);
    root -> right = create(120, 5);
    root -> left = create(90,2);
    root -> left -> right = create(95, 4);
    root -> left -> right -> left = create(94,1);
    root -> left -> left = create(80,5);
    root -> right -> left = create(110,2);
    root -> right -> right = create(130,3);
    
    printf("%d\n", priceOfAllHouses(root));
    inorder(root);
    printf("\n");
    
    //btreenode* temp = lca(root, 80, 95);
    //printf("%d", temp -> price);
    return 0;
}