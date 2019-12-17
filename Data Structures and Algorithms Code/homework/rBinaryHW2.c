/*
Christopher McGrath
CSCI 240 HW2 binary search using recursion
9/18/19
*/
#include <stdio.h>
#include <stdlib.h>

int RbinarySearch(int target, int A[], int left, int right) {
    
    if(right>=1)
    {
        int mid; 
        mid = (left+right)/2;
    
        if(A[mid]==target)
            return mid;
            
        else if(A[mid]>target)
            RbinarySearch(target, A, left, right-1);
            
        else if(A[mid]<target)
            RbinarySearch(target, A, left+1, right);
    } 
    else
        return -1;
}

int main(void) 
{ 
    int arr[] = { 2, 3, 4, 10, 40 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int x = 40; 
    int result = RbinarySearch(x,arr, 0, n - 1); 
    
    if(result==-1)
        printf("%d is not an element in the array\n", x);
    
    else 
        printf("%d is at index %d\n",x,result);
    
    return 0; 
}