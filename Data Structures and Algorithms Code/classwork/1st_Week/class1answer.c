#include <stdio.h>
#include <stdlib.h>
struct person {
   int age;
   float weight;
   char name[30];
};

/*
typedef struct person {
   int age;
   float weight;
   char name[30];
}person;
*/
int main()
{
   struct person *ptr, *ptr1, *ptr2;
   //person *ptr, *ptr1, *ptr2;
   int i, n;
   printf("Enter the number of persons: ");
   scanf("%d", &n);
   // allocating memory for n numbers of struct person
   ptr = (struct person*) malloc(n * sizeof(struct person));
   //ptr = (struct person*) calloc(n, sizeof(struct person));
   //ptr1=ptr;
   //ptr2=ptr;
   for(i = 0; i < n; i++)
   {
       printf("Enter first name and age respectively: ");
       // style 1
       scanf("%s %d", (ptr+i)->name, &(ptr+i)->age);
      
       // style 2
       //scanf("%s %d", ptr[i].name, &ptr[i].age);
       
       // style 3
       //scanf("%s %d", ptr->name, &ptr->age);
       //ptr++;
   }
   printf("Displaying Information:\n");
   // style 1
   for(i = 0; i < n; ++i)
       printf("Name: %s\tAge: %d\n", (ptr+i)->name, (ptr+i)->age);
   
   // style 2
   //for(i = 0; i < n; ++i)
     //  printf("Name: %s\tAge: %d\n", ptr[i].name, ptr[i].age);
       
   // style 3
   //for(i = 0; i < n; ++i, ptr1++)
     //  printf("Name: %s\tAge: %d\n", ptr1->name, ptr1->age);
   
   //free(ptr);
   free(ptr2);
   //free(ptr1);
   return 0;
}