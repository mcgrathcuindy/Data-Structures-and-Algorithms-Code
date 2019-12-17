#include <stdio.h>
#include <stdlib.h>
//#include <math.h>

void find_Prime (int prime);
void main()
{
  int prime;
  printf("Please enter the number you want to check for prime\n");
  scanf("%d", &prime);
  find_Prime(prime);
  return;
}
void find_Prime (int prime){
  int flag=0,i;
  //double m;
  //m=sqrt(prime);
  for (i=2; i <prime; i++){
    //for (i = 2; i < m; i++)
    if((prime%i)==0)
    {
      flag = 1;
    }
  }
  if (flag==0){
    printf("Prime\n");
  }
  else{
    printf("Not Prime\n");
    return;
  }
}
