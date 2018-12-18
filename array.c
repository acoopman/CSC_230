#include <stdio.h>

int sum_ref(int * in, int N)
{
  int total = 0;
  for(int i = 0; i < N; i++)
    {
      total += in[i];
      in[i] = 7;
    }
  return total;
}

int sum(int in[], int N)
{
  int total = 0;
  for(int i = 0; i < N; i++)
    {
      total += in[i];
      in[i] = 10;
    }
  return total;
}

int main()
{
#define N 5
  int array[N] ={1,2,3,4,5};


  printf("Input is \n");
  for(int i =0; i < N; i++)
    printf("%i,", array[i]);
  printf("\n");

  int sum1 = sum(array,N);
  printf("output is \n");
  for(int i =0; i < N; i++)
    printf("%i,", array[i]);
  printf("\n");

    int sum2 = sum_ref(array, N);
  printf("output is \n");
  for(int i =0; i < N; i++)
    printf("%i,", array[i]);
  printf("\n");
  
  return 0;
}
