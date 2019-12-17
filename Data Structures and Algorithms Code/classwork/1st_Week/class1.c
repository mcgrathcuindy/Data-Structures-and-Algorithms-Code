/*
chris mcgrath
in class example struct
8/28/19
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct person{
    int age;
    float weight;
    char name[30];
}person;


int main(void){

    person *ptr;
    int numPersons;
    
    printf("How many person records do you want to enter?\n");
    scanf("%d", &numPersons);
    
    
    ptr = (person*) malloc(numPersons * sizeof(person));
    
    
    
    return 0;
    
}

