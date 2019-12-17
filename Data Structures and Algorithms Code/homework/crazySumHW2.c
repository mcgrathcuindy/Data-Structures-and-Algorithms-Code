/*
Chris McGrath
CSCI 240 HW2 crazySum
9/16/19
*/
#include <stdio.h>
#include <stdlib.h>

int Power(int base, int pow)
{
	if (pow==0) 
	    return 1;
    else if (pow==1)
        return base;
	else
		return base*Power(base, pow-1);
}

int crazySum(int n)
{
    if(n<2)
        return 1;
    else 
        return Power(n,n) + crazySum(n-1); 
}

int main(void)
{
    int n = 5;
    if((n>=1)&&(n<=9))
        printf("%d\n", crazySum(n));
    else 
        printf("Enter a number between 1 and 9\n");
    return 0;
}