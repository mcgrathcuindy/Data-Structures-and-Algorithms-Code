#include <stdio.h>

int main(){
    int i = 5;
    int j = 2;
    junk(&i,j);
    printf("\n%d %d", i, j);
    
    float a = 13.5;
    float *b, *c;
    b = &a;
    c = b;
    printf("\n%u %u %u\n", &a, b, c);
    printf("\n%f %f %f %f %f\n", a, *(&a), *&a, *b, *c);
    
}

junk(int *i, int j){
    *i = *i * *i;
    j = j *j;
    
}