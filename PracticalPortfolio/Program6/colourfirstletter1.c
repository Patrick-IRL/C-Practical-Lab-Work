/*	colourfirstletter1.c:	Program that takes users favourite colour, 
			stores into	a char array, then prints the first char to
			screen using the %c format specifier.
				
			This is one method. An alternative method is investigated
			in the source file "colourfirstletter2.c" which sets the
			second character in the array to '\0', which causes the
			print statement to terminate when this character is reached.
	Authors: Patrick Moorehouse
	Last Modified: 02/11/2012
*/

//Includes required header files.
#include <stdio.h>

/* Main function of the program */
int main(void)
{
	/* Initialising char array.
	Allowing for a maximum of 30 characters
	to cover all possible colour names */
	char colour[30];
	/* Ask user to input their favourite colour */
	printf("What is your favourate colour?\n");
	/* Take input from user. */
	scanf("%29s", colour);
	/* Return first char to user. */
	printf("You said: %c\n", colour[0]);
	
	return 0;
}