#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define MAX 15
struct tree_node
{
   char key[MAX];
   struct tree_node *left;  
   struct tree_node *right;
}*node;

int preOrder(FILE *fout, struct tree_node *ptr)
{
   if (node == NULL)
   {
       fprintf(fout, "Tree is empty");
       return 0;
   }
   if (ptr != NULL)
   {
       fprintf(fout, "%s ", ptr->key);
       preOrder(fout,ptr->left);
       preOrder(fout,ptr->right);
   }
}

void inOrder(FILE *fout, struct tree_node *ptr)
{
   if (node == NULL)
   {
       fprintf(fout, "Tree is empty");
       return;
   }
   if (ptr != NULL)
   {
       inOrder(fout,ptr->left);
       fprintf(fout, "%s ", ptr->key);
       inOrder(fout,ptr->right);
   }
}

void postOrder(FILE *fout, struct tree_node *ptr)
{
   if (node == NULL)
   {
       fprintf(fout, "Tree is empty");
       return;
   }
   if (ptr != NULL)
   {
       postOrder(fout,ptr->left);
       postOrder(fout,ptr->right);
       fprintf(fout, "%s ", ptr->key);
   }
}

void bothChildEmpty(struct tree_node *parentOfNode, struct tree_node *currNode)
{
   if (parentOfNode == NULL)
       node = NULL;
   else
       if (currNode == parentOfNode->left)
           parentOfNode->left = NULL;
       else
           parentOfNode->right = NULL;
}

void oneChildEmpty(struct tree_node *parentOfNode, struct tree_node *currNode)
{
   struct tree_node *child;
   if (currNode->left != NULL)
       child = currNode->left;
   else
       child = currNode->right;
   if (parentOfNode == NULL)
       node = child;
   else
       if (currNode == parentOfNode->left)
           parentOfNode->left = child;
       else
           parentOfNode->right = child;
}

void noChildEmpty(struct tree_node *parentOfNode, struct tree_node *currNode)
{
   struct tree_node *ptr, *temporaryPtr, *next, *prev;
   temporaryPtr = currNode;
   ptr = currNode->right;
   while (ptr->left != NULL)
   {
       temporaryPtr = ptr;
       ptr = ptr->left;
   }
   next = ptr;
   prev = temporaryPtr;
   if (next->left == NULL && next->right == NULL)
       bothChildEmpty(prev, next);
   else
       oneChildEmpty(prev, next);
   if (parentOfNode == NULL)
       node = next;
   else
       if (currNode == parentOfNode->left)
           parentOfNode->left = next;
       else
           parentOfNode->right = next;
   next->left = currNode->left;
   next->right = currNode->right;
}

void searchkey(char key[], struct tree_node **parentOfNode, struct tree_node **currNode)
{
   struct tree_node *ptr, *temporaryPtr;
   if (node == NULL)
   {
       *currNode = NULL;
       *parentOfNode = NULL;
       return;
   }
   if (strcmp(key, node->key) == 0)
   {
       *currNode = node;
       *parentOfNode = NULL;
       return;
   }
   if (strcmp(key, node->key) < 0)
       ptr = node->left;
   else
       ptr = node->right;

   temporaryPtr = node;
   while (ptr != NULL)
   {
      if (strcmp(key, ptr->key) == 0)
       {
           *currNode = ptr;
           *parentOfNode = temporaryPtr;
           return;
       }
       temporaryPtr = ptr;
       if (strcmp(key, ptr->key) <= 0)
           ptr = ptr->left;
       else
           ptr = ptr->right;
   }
   *currNode = NULL;
   *parentOfNode = temporaryPtr;
}

void insert(FILE *fout, char key[])
{
   struct tree_node *parentOfNode, *currNode, *temporary;
   searchkey(key, &parentOfNode, &currNode);
   if (currNode != NULL)
   {
       fprintf(fout, "The key already present in BST.");
       return;
   }
   temporary = (struct tree_node*) malloc(sizeof(struct tree_node));
   strcpy(temporary->key, key);
   temporary->left = NULL;
   temporary->right = NULL;
   if (parentOfNode == NULL)
       node = temporary;
   else
       if (strcmp(key, parentOfNode->key) <= 0)
           parentOfNode->left = temporary;
       else
           parentOfNode->right = temporary;
}



int deletekey(FILE *fout, char key[])
{
   struct tree_node *parentOfNode, *currNode;
   if (node == NULL)
   {
       fprintf(fout, "Tree empty");
       return 0;
   }
   searchkey(key, &parentOfNode, &currNode);
   if (currNode == NULL)
   {
       fprintf(fout,"\nName not found in tree, therefore nothing is deleted");
       return 0;
   }
   if (currNode->left == NULL && currNode->right == NULL)
       bothChildEmpty(parentOfNode, currNode);
   if (currNode->left != NULL && currNode->right == NULL)
       oneChildEmpty(parentOfNode, currNode);
   if (currNode->left == NULL && currNode->right != NULL)
       oneChildEmpty(parentOfNode, currNode);
   if (currNode->left != NULL && currNode->right != NULL)
       noChildEmpty(parentOfNode, currNode);
   fprintf(fout, "\n%s: deleted", currNode->key);
   free(currNode);
}



int main()
{
   
   FILE *fin = fopen("in.txt", "r");
   FILE *fout = fopen("out.txt", "w");
   int N, S, D, i;
   char key[MAX];
   node = NULL;
   
   
   if (fin == NULL)
   {
       fprintf(fout, "Error: Could not open in.txt file");
       return 0;
   }
   if(fout == NULL)
   {
        fprintf(fout, "Error: Could not open out.txt file");   
        return 0;
   }
   fscanf(fin, "%d %d %d", &N, &S, &D);
   
   for (i = 1; i <= N; i++)//Run a loop to insert N words
   {
       fscanf(fin, "%s", key);
       insert(fout, key);
   }
   

   fprintf(fout, "Pre Order: ");
   preOrder(fout,node);
   fprintf(fout, "\nIn Order: ");
   inOrder(fout,node);
   fprintf(fout, "\nPost Order: ");
   postOrder(fout,node);
   fprintf(fout, "\n\nSearch Phase:");
   
   for (i = 1; i <= S; i++)//Run a loop to search for S words
   {
      struct tree_node *temporary = node;
      fscanf(fin, "%s", key);
      int flag = 0, counter = 0;;
      while (temporary != NULL)
      {
         counter++;
         if (strcmp(key, temporary->key) == 0)
         {
            fprintf(fout, "\n%s: Found, Items before: %d", node,counter);
            flag = 1;
            break;
         }
         if (strcmp(key, temporary->key) <= 0)
            temporary = temporary->left;
         else
            temporary = temporary->right;
       }
       if (flag == 0)
           fprintf(fout, "\n%s: Not Found, items before: %d", key, 0);
   }
   fprintf(fout, "\n\nDelete Phase:");
   for (i = 1; i <= D; i++)//Run a loop to delete D words
   {
       fscanf(fin, "%s", key);
       deletekey(fout, key);
   }
   fprintf(fout, "\n\nPre Order: ");
   preOrder(fout, node);
   fprintf(fout, "\nIn Order: ");
   inOrder(fout, node);
   fprintf(fout, "\nPost Order: ");
   postOrder(fout, node);
   fprintf(fout, "\n");
   
   //close the files
   fclose(fin);
   fclose(fout);
   return 0;
}