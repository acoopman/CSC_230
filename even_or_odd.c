//Written by Aidan Coopman for CSC230
#include <stdio.h>

int main()
{
  int a;
  
  printf("Enter in an interger\n");
  scanf("%d", &a);

  printf("You have entered %d \n", a );
  
  if((a %2) == 0)
    printf("The number entered is even\n");
  else
    printf("The number entered is odd\n");
	
  return 0;
}
  
