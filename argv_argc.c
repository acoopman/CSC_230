//Written by Aidan Coopman for CSC230. Homework exercise 14.4 on page 548
/*
14.4 (Sorting Integers) Write a program that sorts an array of integers 
into ascending or descending order. Use command-line arguments to pass 
either argument -a for ascending order or -d for descending order. 
[Note: This is the standard format for passing options to a program in UNIX.]
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort_list(int * in, int do_ascending, int N);

int main(int argc, char *argv[])
{
  //set the time seed
  srand(time(NULL));

  //declare list
  const int N = 16;
  int list[N];

  //set the list's elements to a number between 0-100
  for(int i = 0; i < N; i++)
    {
      list[i] = rand() % 100 + 1;
    }

  //print out the list unsorted
  printf("The list unsorted is:\n");
  for(int i = 0; i < N; i++)
    {
      printf(" %i",list[i]);
    }
  printf("\n");

  //set do_ascending to 0, so descending is default
  int do_ascending = 0;

  //make sure the user entered in something
  if(argc < 2)
      printf("No order was entered, defaulting to descending order\n");

  //search for a '-a' or '-d'
  for(int i = 0; i < argc; i++)
    {
      char * input = argv[i];
      printf("%s\n", input);

      //if '-a' is found, set do_ascending to 1
      if((input[0] == '-')&&(input[1] == 'a'))
	do_ascending = 1;

      //if '-d' is found, set do_ascending to 0
      if((input[0] == '-')&&(input[1] == 'd'))
	do_ascending = 0;
    }

  if(do_ascending)
    {
      printf("going to sort the list in ascending order\n");
    }
  else
    {
      printf("going to sort the list in descending order\n");
    }

  //run the soritng function
  sort_list(list, do_ascending, N);

  if(do_ascending)
      printf("List sorted in ascending order:\n");
  else
    printf("List sorted in descending order:\n");

  //print out the list in whatever sorted order
  for(int i = 0; i < N; i++)
	{
	  printf(" %i",list[i]);
	}
      printf("\n");
    
      return 0;
}

//---------------------------------------------------------
void sort_list(int * in, int do_ascending, int N)
{
  int temp;

  //bubble sort method, for ascending order
  for(int j = 0; j < N-1; j++)
    {
      for(int i = 0; i < N- j- 1; i++)
	{
	  if(in[i] > in[i+1])
	    {
	      temp = in[i];
	      in[i] = in[i+1];
	      in[i+1] = temp;
	    }
	}
    }

  //if user inputed descending order then flip the list elements around
  if(!do_ascending)
    {
      for(int i =0; i< (N/2); i++)
	{
	  temp = in[i];
	  in[i] = in[N-i-1];
	  in[N-i-1] = temp;
	}
    }
    
}
