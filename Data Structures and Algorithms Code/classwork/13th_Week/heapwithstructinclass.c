#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

struct heapStruct{
    int* heaparray;
    int capacity;
    int count;
};

// Used to create a heap.
struct heapStruct *initHeap();
struct heapStruct * buildHeapfromArray(int* values, int length);
void heapify(struct heapStruct *h);

// key functions to implement priority queue.
int removeMax(struct heapStruct *h);
void printHeap(struct heapStruct *h);
int insert(struct heapStruct *h, int value);
void decreaseKey(struct heapStruct *h, int i, int new_val);
void heapSort(int values[], int length);

// Helper functions.
void percolateDown(struct heapStruct *h, int index);
void percolateUp(struct heapStruct *h, int index);
void swap(struct heapStruct *h, int index1, int index2);
//int minimum(int a, int indexa, int b, int indexb);
void freeHeap(struct heapStruct *h);
int leftChild(struct heapStruct *h, int index);
int rightChild(struct heapStruct *h, int index);
int parent(struct heapStruct *h, int index);
int getMax(struct heapStruct *h);
int menu();

int main() 
{
    int ans,i, val;
    struct heapStruct *heapPtr;
    int arr[] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 }; 
    int n = sizeof(arr) / sizeof(arr[0]);
    heapPtr = initHeap();
    for(i = 0; i < n; i++)
    {
        heapPtr->heaparray[i] = arr[i];
        heapPtr->count++;
    }
    do
    {
        ans = menu();
        switch(ans)
        {
            case 1 :
                // Get value to insert.
                printf("Enter a value to insert.\n");
                scanf("%d", &val);
                insert(heapPtr, val);
                break;
            
            case 2 :
                printf("The maximum value removed is: %d\n", removeMax(heapPtr));
                printHeap(heapPtr);
                break;
                
            case 3 :
                printf("The maximum value is: %d\n", getMax(heapPtr));
                break;
            
            case 4 :
                printf("Enter the index and new value for that index.\n");
                scanf("%d %d", &i, &val);
                decreaseKey(heapPtr, i, val);
                break;
            
            case 5 :
                // Heap sort
                printf("Heap before sorting: ");
                printHeap(heapPtr);
                printf("Heap after sorting: ");
                heapSort(arr, n);
                //heapSort(heapPtr->heaparray, heapPtr->count);
                break;
            
            case 6 :
                // Print all values
                printHeap(heapPtr);
                break;
                
            case 7:
                // Clean up.
                freeHeap(heapPtr);
                exit(0);
        }
    }while(1);
    return 0;
}

int menu() 
{
  int ans;
  printf("Here are your choices.\n");
  printf("1. Insert an item into your heap.\n");
  printf("2. Remove/delete the maximum item from your heap.\n");
  printf("3. Get the maximum item in your heap.\n");
  printf("4. Decrease an item key/value in your heap.\n");
  printf("5. Run Heap Sort.\n");  
  printf("6. Print heap.\n");
  printf("7. Quit.\n");
  scanf("%d", &ans);
  return ans;
}  

//returns the index of the parent of the child located at index
int parent(struct heapStruct *h, int index) 
{ 
    if(index<=0||index>=h->count)
        return -1;
    return (index-1)/2; 
} 

//returns the max value in the heap
int getMax(struct heapStruct *h)
{
    if(h->count==0)
        return -1;
    return h->heaparray[0];
}
//returns the index of the left child of the parent located at index
int leftChild(struct heapStruct *h, int index)
{
    int left=2*index+1;
    if(left>=h->count)
        return -1;
    return left;
}

//returns the index of the right child of the parent located at index
int rightChild(struct heapStruct *h, int index)
{
    int right=2*index+2;
    if(right>=h->count)
        return -1;
    return right;
}

// Initialize an empty heap with a capacity of SIZE.
struct heapStruct* initHeap() 
{
    struct heapStruct* h;
    // Allocate space for the heap and set the size for an empty heap.
    h = (struct heapStruct*)(malloc(sizeof(struct heapStruct)));
    h->capacity = SIZE;
    h->heaparray = (int*)malloc(sizeof(int)*SIZE);
    h->count = 0;
    return h;
}

// Frees the struct pointed to by h.
void freeHeap(struct heapStruct *h) 
{
     if(h==NULL)
        return;
     free(h->heaparray);
     free(h);
     h=NULL;//good practice
     return;
}

// Initializes the heap using the first length number of items in the array
// values.
struct heapStruct * buildHeapfromArray(int* values, int length) {

    int i;
    struct heapStruct* h;
    //dynamically allocate memory for heap and heaparray
    h = initHeap();
    
    // Just copy the values into our array.
    for(i = 0; i < length; i++){
        h->heaparray[i] = values[i];
    }
    
    // set the count value
    h->count = length;
    // call heapify
    heapify(h);
    return h;
}

// h points to a heap structure that has values inside of it, but isn't yet
// organized into a heap and does exactly that.
void heapify(struct heapStruct *h) 
{
    int i;
    // We form a heap by just running percolateDown on the first half of the elements, in reverse order.
    for (i=(h->count-1)/2; i>=0; i--)
        percolateDown(h, i);
    return;
}

// Runs percolate down on the heap pointed to by h on the node stored in index.
void percolateDown(struct heapStruct *h, int index) 
{
    int l,r,max=index, temp;
    l=leftChild(h, index);
    r=rightChild(h, index);
    // Find the minimum value of the two children of this node.
    if (l < SIZE && h->heaparray[l] > h->heaparray[index]) 
        max = l; 
    if (r < SIZE && h->heaparray[r] > h->heaparray[max]) 
        max = r; 
    if (max != index) 
    { 
        swap(h,index,max); 
        percolateDown(h,max); 
    }
}

// Runs percolate up on the heap pointed to by h on the node stored in index.
void percolateUp(struct heapStruct *h, int index) 
{
    // Can only percolate up if the node isn't the root.
    if (index > 0) 
    {
        if(h->heaparray[index] > h->heaparray[parent(h,index)])
        {
            swap(h, index, parent(h, index));
            percolateUp(h,parent(h,index));
        }
    }
}

// Inserts value into the heap pointed to by h. Returns 1 if the insert was
// successful, 0 otherwise.
int insert(struct heapStruct *h, int value) 
{
    // Our array is full, we need to allocate some new space!
    if (h->count == h->capacity) 
    {
        // Allocate new space for an array.
        h->heaparray = (int*)realloc(h->heaparray, sizeof(int)*(2*h->capacity));
        // Realloc failed so we quit.
        if (h->heaparray == NULL) return 0;
        // Double the capacity.
        h->capacity *= 2;
    }
    // Adjust all the necessary components of h, and then move the inserted
    // item into its appropriate location.
    h->heaparray[h->count] = value;
    h->count++;
    percolateUp(h, h->count-1);
}

int removeMax(struct heapStruct *h) {

    int retval;
    // We can only remove an element, if one exists in the heap!
    if (h->count > 0) 
    {
        // store the current max value in some variable

        // Copy the last value into this top slot.

        // Our heap will have one fewer items.

        // Need to let this value move down to its rightful spot in the heap.

        // Now we can return our value.

    }
    // No value to return, indicate failure with a -1.
    else
        return -1;
}

// For debugging purposes, lets us see what's in the heap.
void printHeap(struct heapStruct *h) 
{
    int i;
    for (i=0; i<h->count; i++)
        printf("%d ", h->heaparray[i]);
    printf("\n");
}

// Swaps the values stored in the heap pointed to by h in index1 and index2.
void swap(struct heapStruct *h, int index1, int index2) {
    int temp = h->heaparray[index1];
    h->heaparray[index1] = h->heaparray[index2];
    h->heaparray[index2] = temp;
}

// Runs a heap sort by creating a heap out of the values in the array, and then
// extracting those values one-by-one from the heap back into the array in the
// proper order.
void heapSort(int values[], int length) 
{
    struct heapStruct *h;
    int i, old_length, temp;
    // Binary Tree Representation 
	            // of input array 
	           //          1 
	            //		 /	 \ 
	           //       3	  5 
	            //	   / \	 / \ 
	            //    4	  6 13  10 
	            //   / \ / \ 
	            //  9 8 15 17 
    // Create a heap from the array of values.
    h =  buildHeapfromArray(values, length);
 	// Final Heap: 
	            //         17 
	            //		  /	 \ 
	            //      15	 13 
	            //	   / \	 / \ 
	            //    9	  6 5   10 
	            //	 / \ / \ 
	            //  4  8 3  1 
    printHeap(h);
    // Remove these values from the heap one by one and store them back in the
    // original array. inefficient/naive heap sort
    /*
    for (i=0; i<length; i++) 
    {
        values[i] = removeMax(h);
    }
    */
    //Efficient heap sort
    
    //printHeap(h);
    return;
}

// Decreases value of key at index 'i' to new_val. It is assumed that 
// new_val is smaller than harr[i]. 
void decreaseKey(struct heapStruct *h, int i, int new_val) 
{ 
	h->heaparray[i] = new_val; 
	percolateDown(h, i);
	return;
} 