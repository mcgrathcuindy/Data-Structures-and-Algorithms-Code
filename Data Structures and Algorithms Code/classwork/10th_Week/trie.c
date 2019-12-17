#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define next size
#define CHAR_SIZE 26

struct Trie* getNewTrieNode();
void insert(struct Trie* tree, char word[], int k);
void nonRecursiveInsert(struct Trie *head, char* str);

int search(struct Trie* tree, char word[], int k) ;
int nonRecursiveSearch(struct Trie* head, char* str);

void printAll(struct Trie* tree, char cur[]) ;
void freeDictionary(struct Trie* tree);


// A Trie node
struct Trie
{
	int isWord;	// 1 when node is a leaf node
	struct Trie* next[CHAR_SIZE];
};

// Function that returns a new Trie node
struct Trie* getNewTrieNode()
{
	struct Trie* node = (struct Trie*)malloc(sizeof(struct Trie));
	node->isWord = 0;
    int i;
    
	for (i = 0; i < CHAR_SIZE; i++)
		node->next[i] = NULL;

	return node;
}

// Prints out the menu of choices for the user and returns their choice.
int menu() 
{
  int ans;
  printf("Here are your choices.\n");
  printf("1. Insert an item into your tree (recursive).\n");
  printf("2. Insert an item into your tree (nonrecursive).\n");
  printf("3. Search for an item in your tree (recursive).\n");
  printf("4. Search for an item in your tree (Non recursive).\n");
  printf("5. Print tree. (Inorder)\n");
  printf("6. Quit.\n");
  scanf("%d", &ans);
  return ans;
}  

// Iterative function to insert a string in Trie
void nonRecursiveInsert(struct Trie *head, char* str)
{
	// start from root node
	struct Trie* curr = head;
	while (*str)
	{

	}
	// mark current node as end of word

}

// Iterative function to search a string in Trie. It returns 1
// if the string is found in the Trie, else it returns 0
int nonRecursiveSearch(struct Trie* head, char* str)
{
	// return 0 if Trie is empty
	if (head == NULL)
		return 0;
	struct Trie* curr = head;
	while (*str)
	{

	}
	// if current node is end of word and we have reached the
	// end of the string, return 1

}

void insert(struct Trie* head, char word[], int k) 
{
    // Down to the end, insert the word.
    if (k == strlen(word)) {
        head->isWord = 1;
        return;
    }
    // See if the next place to go exists, if not, create it.
    int nextIndex = word[k] - 'a';
    if (head->next[nextIndex] == NULL)
        head->next[nextIndex] = getNewTrieNode();

    insert(head->next[nextIndex], word, k+1);
}

int search(struct Trie* head, char word[], int k) {

    // Down to the end, insert the word.
    if (k == strlen(word))
        return head->isWord;

    // If the next place doesn't exist, word is not a word.
    int nextIndex = word[k] - 'a';
    if (head->next[nextIndex] == NULL)
        return 0;

    return search(head->next[nextIndex], word, k+1);
}

// Just frees all the memory pointed to by tree (directly and indirectly)
void freeDictionary(struct Trie* head) 
{
    int i;
    for (i=0; i<CHAR_SIZE; i++)
        if (head->next[i] != NULL)
            freeDictionary(head->next[i]);
    free(head);
}

// Prints all words stored in the Trie in alphabetical order.
void printAll(struct Trie* head, char cur[]) {

    // Stop!
    if (head == NULL) return;

    // Print this node, if it's a word.
    if (head->isWord)
        printf("%s\n", cur);

    // Safer if we store this.
    int len = strlen(cur);
    // Recursively print all words in each subtree,
    // in alphabetical order.
    int i;
    for (i=0; i<CHAR_SIZE; i++) {
        cur[len] = (char)('a'+i);
        cur[len+1] = '\0';
        printAll(head->next[i], cur);
    }
}

int main() 
{
    struct Trie* head = getNewTrieNode();
    // Read in number of words.
    char word[100];
    int i, n, ans=1;
    FILE* ifp = fopen("dictionary.txt", "r");
    fscanf(ifp, "%d", &n);

    // Read in each word and insert it.
    for (i=0; i<n; i++) 
    {
        fscanf(ifp, "%s", word);
        insert(head, word, 0);
    }
    
    do
    {
        ans = menu();
        switch(ans)
        {
            case 1 :
                // Get value to insert.
                printf("Enter a word to insert recursively.\n");
                scanf("%s", word);
                insert(head, word, 0);
                break;
            
            case 2 :
                // Get value to insert.
                printf("Enter a word to insert nonrecursively.\n");
                scanf("%s", word);
                nonRecursiveInsert(head, word);
                break;
                
            case 3 :
                printf("Enter a word to search recursively.\n");
                scanf("%s", word);
                if (search(head, word, 0))
                    printf ("Found\n");
                else
                    printf ("Not Found\n"); 
                break;
            
            case 4 :
                printf("Enter a word to search nonrecursively.\n");
                scanf("%s", word);
                if (nonRecursiveSearch(head, word))
                    printf ("Found\n");
                else
                    printf ("Not Found\n");
                break;
            
            case 5 :
                // Print all words
                word[0] = '\0';
                printAll(head, word);
                break;
            
            case 6:
                // Clean up.
                fclose(ifp);
                freeDictionary(head);
                exit(0);
        }
    }while(1);
    return 0;
}