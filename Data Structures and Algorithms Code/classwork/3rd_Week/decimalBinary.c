/*
Chris McGrath
CSCI 240 LAB 1
DECIMAL TO BINARY WITH RECURSION
9/11/19
*/

#include <stdio.h>

recursive_decimal_to_binary(int n)
{
    if(n<2)
        printf("%d",n);
    else {
        recursive_decimal_to_binary(n/2);
        printf("%d", n%2);
    }
}

int main(){
    
    int n = 15;
    recursive_decimal_to_binary(n);
    printf("\n");
    
    return 0;
}

/*
notes for hw2

n^n(do exponent function you wrote) + f(n-1)
divide the problem every iteration by half, noly true if it's an ordered array, no repetition and nondecreasing
RbinarySearch takes 4 inputs, int target, int array[], int left, int right
left == 0, right == end index, 5-6 lines, think and trace
(l+r)/2, compare target to mid, if equal return index to mid, 
if target > mid, then left value is one more than index of middle element, and right value is the same
if target < mid, then left value is the same and the right value is one less than the index of the mid
if target value = a[mid] then return mid
if left value becomes greater than the right value then stop
1. Find mid value, check if target value = mid, else call the function recursively with target array and changed value of left and right 
if smaller then change right value, if greater then change left value

If assignment is too trivial then try the bonus
*/