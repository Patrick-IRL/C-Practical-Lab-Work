/*	colouroverflow.c:
				Program that takes users favourite colour, stores into
				a char array, then prints the first char to screen.
				
				Purposely setting array length to be too short to force
				the program to crash. This demonstrates the dangers of
				writing into memory beyond the range which has been
				allowed for the program to write to.
	Authors: Patrick Moorehouse
	Last Modified: 05/11/2012
*/

//Includes required header files.
#include <stdio.h>

/* Main function of the program */
int main(void)
{
	/* Declaring char array.
	Allowing for a maximum of 3 characters */
	char colour[3];
	/* Ask user to input their favourite colour */
	printf("What is your favourate colour?\n");
	/* Take input from user. Intention is to input well beyond the range of the
		char array, so that the program writes into unreserved memory and crashes.*/
	scanf("%s", colour);
	/* Report to user on their choice. */
	printf("You said: %c\n", colour[0]);
	
	return 0;
}