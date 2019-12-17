#include <stdio.h>
#include <stdlib.h>
int Fib(int n);

void main()
{
    printf("%d\n", Fib(7));
    return;
}
int Fib(int n) 
{
	if (n<2) 
		return 1;
	else
		return (Fib (n-1) + Fib(n-2));
}
