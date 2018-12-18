//4.11 (Find the Smallest) Write a program that finds the smallest of several integers. Assume that the first value read specifies the number of values remaining.
#include <stdio.h>

//this function returns the min value of an array passed in
int min_array(int * in, int N)
{
  //set the min equal to the first element
  int min = in[0];
  //go through the array and find the min value
  for(int i = 1; i < N; i++)
    if(min > in[i])
	 min = in[i];

  //return min value
  return min;
}

int main()
{
#define N 5
  int array[N] ={50,43,91,23,49};

  //display the array to the user
  printf("Input is \n");
  for(int i =0; i < N; i++)
    printf("%i,", array[i]);
  printf("\n");

  //find the min value of the array
  int min = min_array(array, N);

  //tell the user the min value
  printf("The min value = %i\n", min);

  
  return 0;
}
