#include <stdio.h>

int multiply(int first, int second)
{
    if((first==0)||(second==0))
        return 0;
    else 
        return first+multiply(first,second-1);
}

int exponent(int first, int second)
{
    if((first==1)||(second==0))
        return 1;
    else if(first==0)
        return 0;
    else
        return first*exponent(first,second-1);
}
    
int main()
{
    int first=6,second=4;
    printf("%d\n",multiply(first,second));
    first = 2;
    second = 5;
    printf("%d\n",exponent(first,second));
    
    return 0;
}