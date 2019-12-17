#include <stdio.h>
#include <stdlib.h>

int main()
{
    int data[] = {87, 99, 75, 88, 93};
    int *p;
    int i;
    for(i = 0; i<5; i++)
        printf("address: %p, value: %d, test: %d\n", data+i, *(data+i), *data+i);

    printf("--------using p-------------\n");
    p = data;
    //printf("address: %p, value: %d \n", p, *p);

    for(i = 0; i<5; i++)
    {
        printf("address: %p, value: %d \n", p, *p);
        p++;
    }


    return 0;
}

/*output:
address: 0x7ffd8ec91e10, value: 87, test: 87
address: 0x7ffd8ec91e14, value: 99, test: 88
address: 0x7ffd8ec91e18, value: 75, test: 89
address: 0x7ffd8ec91e1c, value: 88, test: 90
address: 0x7ffd8ec91e20, value: 93, test: 91
--------using p-------------
address: 0x7ffd8ec91e14, value: 87
address: 0x7ffd8ec91e18, value: 99
address: 0x7ffd8ec91e1c, value: 75
address: 0x7ffd8ec91e20, value: 88
address: 0x7ffd8ec91e24, value: 93 */