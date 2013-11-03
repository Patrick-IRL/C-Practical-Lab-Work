/*	colour.c:	Program that takes users favourite colour, stores into
				a char array, then prints the array to display users
				selected colour on the screen.
	Authors: Patrick Moorehouse
	Last Modified: 02/11/2012
*/

//Includes required header files.
#include <stdio.h>

/* Main function of the program */
int main(void)
{
	/* Decaring char array.
	Allowing for a maximum of 30 characters
	to cover all possible colour names */
	char colour[30];
	/* Ask user to input their favourite colour */
	printf("What is your favourate colour?\n");
	/*	Take input from user. %29s limits the number
		of characters aknowledged by the program.	*/
	scanf("%29s", colour);
	/* Report to user on their choice. */
	printf("You said: %s\n", colour);
	
	return 0;
}