/*(Airline Reservations System) A small airline has just purchased a computer for its new automated reservations system. The president has asked you to program the new system. You’ll write a program to assign seats on each flight of the airline’s only plane (capacity: 10 seats).

Your program should display the following menu of alternatives:


Please type 2 for "economy"

If the person types 1, then your program should assign a seat in the first class section (seats 1–5). If the person types 2, then your program should assign a seat in the economy section (seats 6–10). Your program should then print a boarding pass indicating the person's seat number and whether it’s in the first class or economy section of the plane.

Use a one-dimensional array to represent the seating chart of the plane. Initialize all the elements of the array to 0 to indicate that all seats are empty. As each seat is assigned, set the corresponding element of the array to 1 to indicate that the seat is no longer available.

Your program should, of course, never assign a seat that has already been assigned. When the first class section is full, your program should ask the person if it’s acceptable to be placed in the economy section (and vice versa). If yes, then make the appropriate seat assignment. If no, then print the message "Next flight leaves in 3 hours."
*/
#include <stdio.h>

#define SEAT_EMPTY  0
#define SEAT_FULL   1

//--------------------------------------------------------
void print_seats(int * seats, int N, int first_class_seats)
{
  //first class seats print out
  for(int i = 0; i < first_class_seats; i++)
    {
      if(seats[i] == SEAT_EMPTY)
	printf("First class seat #%i:    empty \n", i+1);
      else
	printf("First class seat #%i:    full \n", i+1);
    }

  printf("\n");

  //economy class seats print out
  for(int i = first_class_seats; i < N; i++)
    {
      if(seats[i] == SEAT_EMPTY)
	printf("Economy class seat #%i:  empty \n", i+1);
      else
	printf("Economy class seat #%i:  full \n", i+1);
    }
  
  printf("\n");
}

//--------------------------------------------------------
int seats_full(int * seats, int N)
{
  int count = 0;
  for(int i = 0; i < N; i++)
    if(seats[i] == SEAT_EMPTY)
      count++;

  if(count > 0)
    return 0;
  else
    return 1;
}
//--------------------------------------------------------
void init_seats(int * seats, int N)
{
  for(int i = 0; i < N; i++)
      seats[i] = SEAT_EMPTY;
}

//--------------------------------------------------------
void choose_seats(int * seats, int N, int count)
{
  int seat_requested;
  
  scanf("%i", &seat_requested);
  printf("seat_requested is %i\n", seat_requested);

  if(seat_requested == 1)
    {

    }
  seats[count] = seat_requested;
  printf("Enter a '1' for first class seating and '2' for economy seating\n");
}
//--------------------------------------------------------

int main()
{

  const int FIRST_CLASS = 1;
  const int ECONOMY_CLASS = 2;
  const int NUM_FIRST_CLASS_SEATS = 5;
  const int NUM_ECONOMY_CLASS_SEATS = 5;
  const int NUM_SEATS = NUM_FIRST_CLASS_SEATS + NUM_ECONOMY_CLASS_SEATS;

  int seats[NUM_SEATS];
  int full;
  int count = 0;

  //set and define the counts for both the first and economy class to 0
  int first_class_count = 0;
  int economy_class_count = 0;
  int seat_requested;

  char response;

  
  //set the seats to 0 to start
  init_seats(seats, NUM_SEATS);

  for(int i = 0; i < NUM_SEATS; i++)
    printf("%i, ", seats[i]);
    printf("\n");

    full = seats_full(seats, NUM_SEATS);


    while(full == 0)
	{

	  //choose_seats(seats, NUM_SEATS, count);
	  printf("Enter a '1' for first class seating and '2' for economy seating\n");	
	  scanf("%i", &seat_requested);

	  //make sure the user enters in a valid number
	  while( (seat_requested != FIRST_CLASS) && (seat_requested != ECONOMY_CLASS))
	    {
	      printf("Invalid seat_requested\n");
	      printf("Enter a '1' for first class seating and '2' for economy seating\n");
	      scanf("%i", &seat_requested);
	    }

FIRST_CLASS_LABEL:	  
	  //if the user enters a "1" or first class, put them in the first class section
	  if(seat_requested == FIRST_CLASS)
	    {
	      if(first_class_count < NUM_FIRST_CLASS_SEATS)
		{
		  seats[first_class_count++] = FIRST_CLASS;
		  printf("Your seat is seat #%i in the First Class section\n", first_class_count);
		  printf("\n");
		}
	      else
		{
		  printf("No seats avaliable in first class\n");
		  printf("is it acceptable to be placed in the economy section? <y> <n>\n");
		  scanf("%s", &response);
		  printf("Response = %c\n", response);
		  if(response == 'y')
		    {
		      seat_requested = ECONOMY_CLASS;
		      goto ECONOMY_CLASS_LABEL;	  
		    }
		    else
		    {
		    printf("Next flight leaves in 3 hours\n");
		    continue;
		    }
		}
	    }

ECONOMY_CLASS_LABEL:	  
	   if(seat_requested == ECONOMY_CLASS)
	    {
	      if(economy_class_count < NUM_ECONOMY_CLASS_SEATS)
		{
		  seats[NUM_FIRST_CLASS_SEATS + economy_class_count++] = ECONOMY_CLASS;
		  printf("Your seat is seat #%i in the Economy Class section\n", (NUM_FIRST_CLASS_SEATS+economy_class_count));
		    printf("\n");
		}
	      else
		{
		  printf("No seats avaliable in economy class\n");
		  printf("is it acceptable to be placed in the first class section? <y> <n>\n");
		  scanf("%s", &response);
		  printf("Response = %c\n", response);
		  if(response == 'y')
		    {
		      seat_requested = FIRST_CLASS;
		      goto FIRST_CLASS_LABEL;	  
		    }
		  else
		    {
		      printf("Next flight leaves in 3 hours\n");
		      continue;
		    }
		}
	    }

	  
	   print_seats(seats, NUM_SEATS, NUM_FIRST_CLASS_SEATS);	
       
	   full = seats_full(seats, NUM_SEATS);
	   count++;

	}

    printf("The plane is now full, wait 3 hours for the next flight\n");
    
  return 0;
}
