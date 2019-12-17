#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define NOT_FOUND -1

int LinearSearch(int A[], int n, int TARGET);
int BinarySearch(int A[], int n, int TARGET);
void printArray(int A[], int n);
void randArray(int A[], int size, int maxval); 
void selectionSort(int A[], int n);
void insertionSort(int A[], int n);
void bubbleSort(int A[], int n);
void swap(int *a, int *b);
int menu();

int main() 
{
    int ans,result, val, n=10;
    int arr[n];
    srand(time(0));
    do
    {
        ans = menu();
        switch(ans)
        {
            case 1 :
                randArray(arr, n, 100);
                printArray(arr, n);                
                printf("Sorting array elements using Insertion sort.\n");
                insertionSort(arr, n);
                printArray(arr, n);
                break;
            
            case 2 :
                randArray(arr, n, 100);
                printArray(arr, n);             
                printf("Sorting array elements using Selection sort.\n");
                selectionSort(arr, n);
                printArray(arr, n);
                break;
                
            case 3 :
                randArray(arr, n, 100);
                printArray(arr, n);             
                printf("Sorting array elements using Bubble sort.\n");
                bubbleSort(arr, n);
                printArray(arr, n);
                break;
            
            case 4 :
                randArray(arr, n, 100);
                printArray(arr, n);                
                printf("Enter the value to do linear search.\n");
                scanf("%d", &val);
                result=LinearSearch(arr, n, val);
                if (result != NOT_FOUND)
                   printf("Your value was found in index %d of the array.\n", result);
                else
                   printf("Your value wasn't found.\n");
                break;
            
            case 5 :
                randArray(arr, n, 100);
                insertionSort(arr, n);//without this line binary search wouldn't work since it only works on sorted array
                printArray(arr, n);                
                printf("Enter the value to do binary search.\n");
                scanf("%d", &val);
                result=BinarySearch(arr, n, val);
                if (result != NOT_FOUND)
                   printf("Your value was found in index %d of the array.\n", result);
                else
                   printf("Your value wasn't found.\n");
                break;
            
            case 6 :
                // Print all values
                printArray(arr, n);
                break;
                
            case 7:
                exit(0);
        }
    }while(1);
    return 0;
}

int menu() 
{
  int ans;
  printf("Here are your choices.\n");
  printf("1. Insertion sort.\n");
  printf("2. Selection sort.\n");
  printf("3. Bubble sort.\n");
  printf("4. Linear search.\n");
  printf("5. Binary search.\n");  
  printf("6. Print array.\n");
  printf("7. Quit.\n");
  scanf("%d", &ans);
  return ans;
}  


// Post-condition: A is filled with random integers in the range [1,maxval] 
// from index 0 to index size-1.
void randArray(int A[], int size, int maxval) 
{
    int i;
    // Fill each array slot in question with a random value in the designated range.     
    for (i=0; i<size; i++) 
        A[i] = rand()%maxval + 1;
} 

int LinearSearch(int A[], int n, int TARGET) 
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(A[i] == TARGET)
            return i;
    }
    return NOT_FOUND;
}

int BinarySearch(int A[], int n, int TARGET) 
{
    // Set the left and rightmost boundaries in which to search.   
    int L = 0, Mid, R = n-1;
    printf("We are searching for %d.\n", TARGET);
    printf("Here is the array: ");
    printArray(A, n);
    // Keep on looking so long as there is a search space.
    while (L <= R) 
    {
        Mid = (L + R -1) / 2;
        if(A[Mid] == TARGET)
            return Mid;
        else if(A[Mid] < TARGET)
            L = Mid + 1;
        else
            R = Mid - 1;
    }
    return NOT_FOUND;
}

void printArray(int A[], int n) 
{
     int i;
     for (i = 0; i<n; i++)
         printf("%d ", A[i]);
     printf("\n");
}

void selectionSort(int A[], int n) 
{
    int i = 0, j, smallest;
    for(i = 0; i < n; i++)
    {
        smallest = i;
        for(j = i+1; j < n; j++)
        {
            if(A[j] < A[smallest])
                smallest = j;
        }
        swap(&A[i],&A[smallest]);
    }
}

// Sorts the first length elements of vals in ascending order.
void insertionSort(int A[], int n) 
{
    int i,j;

    for(i=1;i<n;i++)
    {
        j=i;
        while(j > 0 && A[j] < A[j-1])
        {
            swap(&A[j],&A[j-1]);
            j--;
        }
    }
}

void bubbleSort(int A[],int n)
{
    int i,j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n-1; j++)
        {
            if(A[j] > A[j+1])
                swap(&A[j], &A[j+1]);
        }
    }
}

// Swaps the integers pointed to by a and b.
void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}