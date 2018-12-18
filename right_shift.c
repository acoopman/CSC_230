/*
10.10	(Right Shifting Integers) Write a program that right shifts an integer variable 4 bits. The program should print the integer in bits before and after the shift operation. Does your system place 0s or 1s in the vacated bits?

 */

#include <stdio.h>

void print_bits_int(int in)
{

  printf("binary for %i is:\n", in);
  for(int i =0; i < 32; i++)
  {
    int bit = in & 0x80000000;
    in <<= 1;
    
    if(bit)
      printf("1");
    else
      printf("0");
  }

  printf("\n");

}

int main()
{
  //positive case
  int x = 979189826;
  int y = x >> 4;

  printf("x before shift = %i\n", x);
  printf("x after shift = %i\n", y);
    
  printf("binary bits before shift = ");
  print_bits_int(x);

  printf("binary bits after shift = ");
  print_bits_int(y);

  printf("the top four vacant bits get set to 0, if the number is positive\n");

  //negative case
   x = -979189826;
   y = x >> 4;

  printf("x before shift = %i\n", x);
  printf("x after shift = %i\n", y);
    
  printf("binary bits before shift = ");
  print_bits_int(x);

  printf("binary bits after shift = ");
  print_bits_int(y);

  printf("the top four vacant bits get set to 1, if the number is negative\n");
  
  return 0;
}
