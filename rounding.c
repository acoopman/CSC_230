//For each value read, your program should print the original value, the number rounded to the nearest integer, the number rounded to the nearest tenth, the number rounded to the nearest hundredth, and the number rounded to the nearest thousandth.

#include <stdio.h>
#include <math.h>

//this function takes in a number and rounds it to the nearest integer
float roundToInteger(float number);

//this function takes in a number and rounds it to the nearest tenths
float roundToTenths(float number);

//this function takes in a number and rounds it to the nearest hundredths
float roundToHundreths(float number);

//this function takes in a number and rounds it to the nearest thousandths
float roundToThousandths(float number);



int main()
{
  float a = 2.7819;
  float b = roundToInteger(a);
  float c = roundToTenths(a);
  float d = roundToHundreths(a);
  float e = roundToThousandths(a); 

  printf("Checking a positive number \n");
  printf("Starting number             = %f\n", a);
  printf("Rounding to an integer      = %f\n", b);
  printf("Rounding to the tenths      = %f\n", c);
  printf("Rounding to the hundreths   = %f\n", d);
  printf("Rounding to the thousandths = %f\n", e);

  
   a = -2.7819;
   b = roundToInteger(a);
   c = roundToTenths(a);
   d = roundToHundreths(a);
   e = roundToThousandths(a);
  
  printf("Checking a negative number \n");
  printf("Starting number             = %f\n", a);
  printf("Rounding to an integer      = %f\n", b);
  printf("Rounding to the tenths      = %f\n", c);
  printf("Rounding to the hundreths   = %f\n", d);
  printf("Rounding to the thousandths = %f\n", e);


  return 0;
}


//-----------------------------------------------
float roundToInteger(float number)
{
  return (floor(number+0.5));
}
//-----------------------------------------------
float roundToTenths(float number)
{
  float x = 10*number;
  x = floor(x+0.5);
  x = x/10.0;
  return x;
}
//-----------------------------------------------
float roundToHundreths(float number)
{
 float x = 100*number;
  x = floor(x+0.5);
  x = x/100.0;
  return x;
}
//-----------------------------------------------
float roundToThousandths(float number)
{
 float x = 1000*number;
  x = floor(x+0.5);
  x = x/1000.0;
  return x;
}
