#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define capacity 100
#define INT_MAX 9999
#define INT_MIN -9999

int harr[capacity];
int heap_size=0;

void swap(int *x, int *y);
void minHeapify(int i); 
int parent(int i);
int leftChild(int i);
int rightChild(int i);
int extractMin(); 
int getMin();
void deleteKey(int i);
void decreaseKey(int i, int new_val); 
void insertKey(int k);

int parent(int i) 
{ 
    return (i-1)/2; 
} 

// to get index of left child of node at index i 
int leftChild(int i) 
{ 
    return (2*i + 1); 
} 

// to get index of right child of node at index i 
int rightChild(int i) 
{ 
    return (2*i + 2); 
} 

// Returns the minimum key (key at root) from min heap 
int getMin() 
{ 
    return harr[0];
} 

// Inserts a new key 'k' 
void insertKey(int k) 
{ 
	if (heap_size == capacity) 
	{ 
		printf("\nOverflow: Could not insertKey\n"); 
		return; 
	} 

	// First insert the new key at the end 
	heap_size++; 
	int i = heap_size - 1; 
	harr[i] = k; 

	// Fix the min heap property if it is violated 
	while (i != 0 && harr[parent(i)] > harr[i]) 
	{ 
		swap(&harr[i], &harr[parent(i)]); 
		i = parent(i); 
	} 
} 

// Decreases value of key at index 'i' to new_val. It is assumed that 
// new_val is smaller than harr[i]. 
void decreaseKey(int i, int new_val) 
{ 
	harr[i] = new_val; 
	while (i != 0 && harr[parent(i)] > harr[i]) 
	{ 
		swap(&harr[i], &harr[parent(i)]); 
		i = parent(i); 
	} 
} 

// Method to remove minimum element (or root) from min heap 
int extractMin() 
{ 
	if (heap_size <= 0) 
		return INT_MAX; 
	if (heap_size == 1) 
	{ 
		heap_size--; 
		return harr[0]; 
	} 

	// Store the minimum value, and remove it from heap 
	int root = harr[0]; 
	harr[0] = harr[heap_size-1]; 
	heap_size--; 
	minHeapify(0); 

	return root; 
} 


// This function deletes key at index i. It first reduced value to minus 
// infinite, then calls extractMin() 
void deleteKey(int i) 
{ 
	decreaseKey(i, INT_MIN); 
	extractMin(); 
} 

// A recursive method to heapify a subtree with the root at given index 
// This method assumes that the subtrees are already heapified 
void minHeapify(int i) 
{ 
	int l = leftChild(i); 
	int r = rightChild(i); 
	int smallest = i; 
	if (l < heap_size && harr[l] < harr[i]) 
		smallest = l; 
	if (r < heap_size && harr[r] < harr[smallest]) 
		smallest = r; 
	if (smallest != i) 
	{ 
		swap(&harr[i], &harr[smallest]); 
		minHeapify(smallest); 
	} 
} 

// A utility function to swap two elements 
void swap(int *x, int *y) 
{ 
	int temp = *x; 
	*x = *y; 
	*y = temp; 
} 

// Driver program to test above functions 
int main() 
{ 
	 
	insertKey(3); 
	insertKey(2); 
	//deleteKey(1); 
	insertKey(15); 
	insertKey(5); 
	insertKey(4); 
	insertKey(45); 
	printf(" %d\n",extractMin());
	printf(" %d \n",getMin()); 
	//decreaseKey(2, 1);
	printf(" %d \n",getMin());
	return 0; 
}