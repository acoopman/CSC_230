//Writen by Aidan Coopman for CSC230
//Problem # 12.10 on page 513
//Nov 15, 2018
/*
Instructions:
12.10 (Reversing the Words of a Sentence) Write a program that 
inputs a line of text and uses a stack to print the line reversed.
*/

#include <stdio.h>
#include <string.h>

char* stack[50];
int stack_ptr;

void init_stack()
{
  stack_ptr = 0;
}
//--------------------------------

void push_stack(char * word)
{
  stack[stack_ptr++] = word;
}
//--------------------------------

char * pop_stack()
{
  stack_ptr--;
  return stack[stack_ptr];
}
//--------------------------------

int stack_empty()
{
  if(stack_ptr == 0)
    return 1;
  else
    return 0; 
}
//--------------------------------

int main()
{
  //found and modified this code online, just to input a sentence
  char input_sentence[256];
  char reverse_sentence[256];
  
  printf("Enter in a sentence:\n");
  scanf("%[^'\n']s",input_sentence);
  
  printf("Input sentence   : ");
  printf("%s\n",input_sentence);
  
  //this extracts the words from sentences
  //init the stack
  init_stack();
  char * word;
  stack_ptr = 0;
  //strtok breaks up the sentence by delimiters such as spaces, tabs, commas, etc
  word = strtok (input_sentence," ,.");
  while (word != NULL)
    {
      push_stack(word);
      word = strtok (NULL, " ,.");
    }
  
  //must put a null charactor to make an empty string
  reverse_sentence[0] = '\0';
  while(!stack_empty())
    {
      char * temp = pop_stack();
      strcat(reverse_sentence, temp);
      strcat(reverse_sentence, " ");
    }
  printf("Sentence reversed: %s\n", reverse_sentence);  
  
  return 0;
}
