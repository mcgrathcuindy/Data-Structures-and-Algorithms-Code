
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

int countCharInString(char ch, char * str);

void main()
{
    char s[MAX],ch;
    printf("Please enter the string\n");
    
    //gets(s); Cloud 9 doesn't support gets() since it can cause buffer overflow
    //As an alternate I am using fgets ()
    //for better clarification see https://www.geeksforgeeks.org/fgets-gets-c-language/
    fgets (s, MAX, stdin);
    printf("Please enter the char to find in the string\n");
    scanf("%c",&ch);
    printf("%d\n", countCharInString(ch, s));
    return;
}
int countCharInString(char ch, char *str)
{
	if (str[0]=='\0') 
		return 0;
	else if (str[0]==ch) 
		return 1+countCharInString(ch, str+1);
	else //means when (str[0]!=ch) 
		return countCharInString(ch, str+1);
}