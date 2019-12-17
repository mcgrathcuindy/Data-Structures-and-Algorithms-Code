#include <stdio.h>
#include <stdlib.h>

/*int fact(int n)
{
    if(n==0)
        return 1;
    else
        return n*fact(n-1);
}
*/

int fact(int n)
{
    if(n==0)
        return 1;
    else 
        return n*fact(n-1);
}
    


int main(void)
{
    int n=3;
    printf("%d\n",fact(n));
    return;

}