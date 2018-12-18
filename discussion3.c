//8.6 (Displaying Strings in Uppercase and Lowercase)
//Write a program that inputs a line of text into char array s[100].
//Output the line in uppercase letters and in lowercase letters.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
  char s[100];
  char lower_s[100];\
  char upper_s[100];

  int length = 0;
  
  printf("Enter in a sentence\n");
  
  scanf("%[^\n]s", s);

  //does not include NULL character
  length = strlen(s);
  
  //copy the string to lower_s and upper_s
  strcpy(lower_s, s);
  strcpy(upper_s, s);

  //change the sentence to uppercase
  for(int i = 0; i < length; i++)
    {
      upper_s[i] = toupper(upper_s[i]);
    }

  //change the sentence to lowercase
  for(int i = 0; i < length; i++)
    {
      lower_s[i] = tolower(lower_s[i]);
    }

  //output the results
  printf("You entered this string: %s with the length of: %i\n", s, length);
  printf("Lowercase = %s\n", lower_s);
  printf("Uppercase = %s\n", upper_s);

  return 0;
}
