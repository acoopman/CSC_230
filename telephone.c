//Written by Aidan Coopman for CSC230 problem # 11.13
/*
11.13 (Telephone-Number Word Generator) Standard telephone keypads contain the digits 0–9. 
The numbers 2–9 each have three letters associated with them, as is indicated by the following table:

Digit 	Letter 	Digit 	Letter
2 	A B C 	6 	M N O
3 	D E F 	7 	P R S
4 	G H I 	8 	T U V
5 	J K L 	9 	W X Y

Many people find it difficult to memorize phone numbers, so they use the correspondence between
 digits and letters to develop seven-letter words that correspond to their phone numbers. For example, a person whose telephone number is 686-2377 might use the correspondence indicated in the above table to develop the seven-letter word “NUMBERS.”

Businesses frequently attempt to get telephone numbers that are easy for their clients to remember. If a business can advertise a simple word for its customers to dial, then, no doubt, the business will receive a few more calls.

Each seven-letter word corresponds to exactly one seven-digit telephone number. The restaurant wishing to increase its take-home business could surely do so with the number 825-3688 (i.e., “TAKEOUT”).

Each seven-digit phone number corresponds to many separate seven-letter words. Unfortunately, most of these represent unrecognizable juxtapositions of letters. It’s possible, however, that the owner of a barber shop would be pleased to know that the shop’s telephone number, 424-7288, corresponds to “HAIRCUT.” The owner of a liquor store would, no doubt, be delighted to find that the store’s telephone number, 233-7226, corresponds to “BEERCAN.” A veterinarian with the phone number 738-2273 would be pleased to know that the number corresponds to the letters “PETCARE.”

Write a C program that, given a seven-digit number, writes to a file every possible seven-letter word corresponding to that number. There are 2187 (3 to the seventh power) such words. Avoid phone numbers with the digits 0 and 1.
*/

#include <stdio.h>
#include <string.h>

//return 1 if the phone number has a 0 or 1 in it
//otherwise return 0 meaning no errors
int gen_words(char in[], char table[8][3], FILE *fptr)
{

  //check if the input has a 1 or 0 and if so return an error
  for(int i = 0; i < 7; i++)
    {
      if( (in[i] == 0) || in[i] == 1)
	return 1;
    }
    
  
  char letters[7][3]; //7 numbers with 3 possible letters

  //make up a table of possible letters
  for(int i = 0; i < 7; i++)
    {
      int idx = in[i]-2; //nunmber starts at 2 but array starts are 0	  
      letters[i][0] = table[idx][0];
      letters[i][1] = table[idx][1];
      letters[i][2] = table[idx][2];
    }

  //make an array for the phone number
    char word[8];   
    word[7] = '\0';

    //go thru each row
    for(int row0 = 0; row0 < 3; row0++)
      for(int row1 = 0; row1 < 3; row1++)
	for(int row2 = 0; row2 < 3; row2++)
	  for(int row3 = 0; row3 < 3; row3++)
	    for(int row4 = 0; row4 < 3; row4++)
	      for(int row5 = 0; row5 < 3; row5++)
		for(int row6 = 0; row6 < 3; row6++)
		  {
		    //set the word equal to the letters 
		    word[0] = letters[0][row0];
		    word[1] = letters[1][row1];
		    word[2] = letters[2][row2];
		    word[3] = letters[3][row3];
		    word[4] = letters[4][row4];
		    word[5] = letters[5][row5];
		    word[6] = letters[6][row6];

		    //write the word to file
		    fprintf(fptr,"%s\n", word);		    
		  }
    return 0;
}

//---------------------------------------------------------------------

int main()
{
  FILE *fptr = NULL;
  fptr = fopen("phone_words.txt","w");
  if(fptr == NULL)
    {
      printf("File did not open \n");
      return 1;
    }
    
  //test number for TAKEOUT
  char num[7] = {8,2,5,3,6,8,8};

  char table[8][3] = {'A','B','C',  //table[0][]
		      'D','E','F',  //table[1][]
		      'G','H','I',
		      'J','K','L',
		      'M','N','O',
		      'P','R','S',
		      'T','U','V',
		      'W','X','Y'
                      };
  
  if(gen_words(num, table, fptr) == 1)
    {
      //Avoid phone numbers with the digits 0 and 1.
      printf("The phone number contained a 0 or a 1\n");
    }

  fclose(fptr);
  return 0;
}
