//8.9	(Comparing Strings) Write a program that uses function
//strcmp to compare two strings input by the user.
//The program should state whether the first string
//is less than, equal to or greater than the second string. 
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
  char s1[100];
  char s2[100];
  
  int length = 0;
  
  printf("Enter in a sentence\n");

  //this is how you scan in a full sentence and ignore the newline char
  scanf("%[^\n]%*c", s1);

  printf("Enter in another sentence\n");
  
  scanf("%[^\n]%*c", s2);

  printf("You have entered the string1 : %s\n", s1);
  printf("You have entered the string2 : %s\n", s2);

  int x = strcmp(s1, s2);
  printf("Comparison = %i\n", x);

  if(x == 0)
    printf("The first string is equal to the second string \n");
  else if(x < 0)
    printf("The first string is less than the second string \n");
  else
    printf("The first string is greater than the second string \n");

  return 0;
}
