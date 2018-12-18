//13.5 (Adding Two Numbers) Write a program that defines macro SUM with two arguments, x and y, and use SUM to produce the following output:
#include <stdio.h>

#define SUM (x+y)

int main()
{
  float x;
  float y;
  float sum;

  printf("Enter in num1\n");
  scanf("%f", &x);

  printf("Enter in num2\n");
  scanf("%f", &y);

  sum = SUM;
  
  printf("Sum of num1 and num2 = %.3f\n", sum);
  
  return 0;
}
