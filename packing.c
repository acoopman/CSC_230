/*10.12	(Packing Characters into an Integer) The left-shift operator can be used to pack
four character values into a four-byte unsigned int variable.
 Write a program that inputs four characters from the keyboard and passes them to function
 packCharacters. To pack four characters into an unsigned int variable, assign the first character
 to the unsigned int variable, shift the unsigned int variable left by 8 bit positions
 and combine the unsigned variable with the second character using the bitwise inclusive
 OR operator. Repeat this process for the third and fourth characters.
 The program should output the characters in their bit format before and after
 they’re packed into the unsigned int to prove that the characters are in fact packed correctly 
in the unsigned int variable.
*/

#include <stdio.h>

int packCharactors(char in1, char in2, char in3, char in4)
{
  
  //promote it to a larger type - 4 bytes so you can shift
  unsigned int byte0 = in1;
  unsigned int byte1 = in2;
  unsigned int byte2 = in3;
  unsigned int byte3 = in4;
  
  //shifted inside the byte
  byte0 = byte0<<0;
  byte1 = byte1<<8;
  byte2 = byte2<<16;
  byte3 = byte3<<24;
  
  unsigned int out = byte0 | byte1 | byte2 | byte3;
  
  return out;
}
void print_bits_byte(char in)
{

  printf("binary for %c is:\n", in);
  for(int i =0; i < 8; i++)
  {
    int bit = in & 1;
    in >>= 1;
    printf("%i", bit);
  }

  printf("\n");

}

void print_bits_int(int in)
{

  printf("binary for %i is:\n", in);
  for(int i =0; i < 32; i++)
  {
    int bit = in & 1;
    in >>= 1;
    printf("%i", bit);
  }

  printf("\n");

}

int main()
{
  int a = 0;
  
  //this is a single byte
  char in1;
  char in2;
  char in3;
  char in4;
  char endline;
  
  printf("Input char #1\n");
  scanf("%c", &in1);
  scanf("%c", &endline);
  printf("Input char #2\n");
  scanf("%c", &in2);
  scanf("%c", &endline);
  printf("Input char #3\n");
  scanf("%c", &in3);
  scanf("%c", &endline);
  printf("Input char #4\n");
  scanf("%c", &in4);
  scanf("%c", &endline);
      
  printf("Before -----\n");

  printf("in1 = %i, in1 = 0x%0x\n", in1 , in1);
  printf("in2 = %i, in2 = 0x%0x\n", in2 , in2);
  printf("in3 = %i, in3 = 0x%0x\n", in3 , in3);
  printf("in4 = %i, in4 = 0x%0x\n", in4 , in4);

  printf("After -----\n");
  unsigned int out =  packCharactors(in1, in2, in3, in4);
  
  printf("out = 0x%0x\n", out);  

  //--------------------------------------------
  print_bits_byte(in1);
  print_bits_byte(in2);
  print_bits_byte(in3);
  print_bits_byte(in4);
  print_bits_int(out);
  return 0;
}
