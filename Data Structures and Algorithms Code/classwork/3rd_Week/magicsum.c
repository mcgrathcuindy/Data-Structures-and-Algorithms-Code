#include <stdio.h>
#include <stdlib.h>

int magicsum(int arr[], int n)
{
   
    if(n==0)
        return 0;
    if(n==1)
        return arr[0];
    int first, second;
    first=magicsum(arr,n/2);
    second=magicsum(arr+n/2,n-n/2);
    return first+second;
    
   
    //Magic sum version 1
    /*
    int front,total;
    if (n==0)
        return 0;
    if (n==1)
        return arr[0];
    front=magicsum(arr, n-1);
    total=front+arr[n-1];
    return total;
    */
    
    //Magic sum version 2
    /*
    int rear,total;
    if (n==0)
        return 0;
    if (n==1)
        return arr[0];
    rear=magicsum(arr+1, n-1);
    total=arr[0]+rear;
    return total;
    */
    

    //Magic sum version 3

}
void main()
{
    const int n = 5;
    int arr[5] = { 10, 100, 42, 72, 16}, s;
    s=magicsum(arr,n);
    printf("The total is %d\n", s);
    return;
}