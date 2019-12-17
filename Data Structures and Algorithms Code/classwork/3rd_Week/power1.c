#include <stdio.h>
#include <stdlib.h>
int Power(int base, int pow);


int Power(int base, int pow)
{
	if (pow==0) 
		return 1;
    else if (pow==1)
        return base;
	else
		return base*Power(base, pow-1);
}


int main(void)
{
    printf("%d\n", Power(3,4));
    return 0;
}