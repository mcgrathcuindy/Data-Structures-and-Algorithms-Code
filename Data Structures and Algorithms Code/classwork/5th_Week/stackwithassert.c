#include <assert.h>
#include <stdio.h>
#define elements int
#define stacksize 5

typedef struct
{
  int top;
  elements items[stacksize];
} stack;

int empty (stack s);
/* postcondition: empty(s) == 1 if s is empty,
                           == 0 otherwise */

int full ( stack s );
/* postcondition: full(s) == 1 if s is full,
                          == 0 otherwise */

elements pop (stack *s);
/* precondition: not empty(*s);
   postcondition: push(*s,pop(*s)) == *s */

void push ( stack *s, elements e );
/* precondition: full(*s) == 0;
   postcondition: push(*s,e); pop(*s) == e */

int empty ( stack s )
{
   return (s.top < 0 ? 1 : 0);
}

int full ( stack s )
{
   return (s.top >= (stacksize-1) ? 1 : 0);
}

elements pop ( stack *s )
{
   assert(empty(*s) == 0);        
   return s->items[s->top--];
}

void push ( stack *s, elements e )
{
   assert(full(*s) == 0); 
   s->items[++(s->top)] = e;
}

int main ( void )
{
   stack s;
   char action;
   elements item;

   s.top = -1;
   if (empty(s) == 1) printf("\nThe stack is empty.\n");

   do
   {
      printf("\nChoose one of the following :\n");
      printf("  0. leave this program\n");
      printf("  1. push item on stack\n");
      printf("  2. pop item from stack\n");
      printf("Make your choice : ");
      scanf(" %c", &action);

      switch(action)
      {
         case '0': printf("\nbye bye\n\n");
                   break;
         case '1': printf("\n  Give integer : ");
                   scanf("%d", &item);
                   push(&s,item);
                   break;
         case '2': item = pop(&s);
                   printf("\n  Item popped : %d\n", item);
                   break;
         default:  printf("\n  Invalid choice, try again...\n");
      }
   }
   while (action != '0');

   return 0;
}
