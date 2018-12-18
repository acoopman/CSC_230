//4.10	(Average a Sequence of Integers) Write a program that calculates and prints the average of several integers. Assume the last value read with scanf is the sentinel 9999. A typical input sequence might be
//10 8 11 7 9 9999

#include <stdio.h>

//this function returns the average of an array passed in
//the average could be have a decimal, hence the need for float
float ave_array(int * in, int N);

int main()
{
  //define the array to a large size because we dont know
  //how much the user is going to input
#define MAX_ARRAY_SIZE  10000
  int array[MAX_ARRAY_SIZE];
  int input;
  int count;
  
  //prompt the user to enter numbers in
  printf("Enter in numbers (end with a 9999)\n");
  for(int i =0; i < MAX_ARRAY_SIZE; i++)
    {
      //user enters in numbers and ends loops with a 9999
    scanf("%d", &input);
    if(input == 9999)
      break;

    //put the inputed values into the array
    array[i] = input;
    //add up how many times a number was entered (not counting 9999)
    count++;
    }

  //call the average funtion
  float ave = ave_array(array, count);

  //tell the user the average value
  printf("The average value = %f\n", ave);

  
  return 0;
}


//this function returns the average of an array passed in
//the average could be have a decimal, hence the need for float
float ave_array(int * in, int N)
{
  //set the total to 0
  int total = 0;
  //go through the array and add all the elements up
  for(int i = 0; i < N; i++)
    total += in[i];
  
  //return the average
  return (total/(float)N);
}
