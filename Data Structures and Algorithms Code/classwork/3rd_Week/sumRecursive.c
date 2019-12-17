#include <stdio.h>

int sum(int n)
{
    if(n==0)
        return;
    else
        return n+sum(n-1);
    
}



int main(){
    
    int n = 4;
    
    printf("%d\n", sum(n));
    
    
    return 0;
}