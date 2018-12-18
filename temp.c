//9.10	(Temperature Conversions) Write a program that converts
//integer Fahrenheit temperatures from 0 to 212 degrees to floating-point
//Celsius temperatures with 3 digits of precision. Perform the calculation using the formula

//formula : celsius = 5.0 / 9.0* (fahrenheit - 32);

#include <stdio.h>

float temp_conversion(float fahrenheit)
{
  float celsius = 5.0 / 9.0* (fahrenheit - 32);
  
  return celsius;
}

int main()
{
  //create variables for the inputed temperature and the converted tempature
  float input_temp;
  float celsius;

  int in_range = 1;
  while(in_range)
    {
      //ask the user to enter in a temperature
      printf("Enter in a tempature in fahrenheit from 0 to 212 degrees\n");
      scanf("%f", &input_temp);

      //make sure their inputed temperature is in the range 0 - 212
      if((input_temp >= 0) && (input_temp <= 212))
	in_range = 0;
      else
	printf("Input must be between 0 and 212 degrees!\n");
    }
  
  celsius = temp_conversion(input_temp);
  
  printf("%.3f fahrenheit is equal to %.3f celsius\n", input_temp, celsius);
  
  return 0;
}
