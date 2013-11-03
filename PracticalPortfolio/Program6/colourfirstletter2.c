/*	colourfirstletter2.c:	Program that takes users favourite colour,
			stores into	a char array, then prints the first char to
			screen.
				
			This is the alternative method discussed in comments
			for "colourfirstletter1.c" which sets the second
			character in the array to '\0', which causes the print
			statement to terminate when this character is reached.
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
	/* Alter array to make the second element = \0
		which is the end of string character. */
	colour[1]='\0';
	/* Report to user on their choice. */
	printf("You said: %s\n", colour);
	
	return 0;
}