#include <stdio.h>
#include <stdlib.h>
int Multiply(int first, int second); 
int Multiply1(int first, int second); 

void main()
{
    printf("%d\n", Multiply(6,4));
    printf("%d\n", Multiply1(6,4));
    return;
}
int Multiply(int first, int second) 
{
	if (( second == 0 ) || ( first == 0 )) 
		return 0;
	else
		return (first + Multiply(first, second-1));
}

int Multiply1(int first, int second) 
{
	if (second == 1) 
		return first;
	else
		return (first + Multiply1(first, second-1));
}