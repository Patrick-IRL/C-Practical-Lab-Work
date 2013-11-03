/*	Program20b.c: Program that takes a word using scanf().
	Authors: Patrick Moorehouse
	Last Modified: 12/11/2012
*/

#include <stdio.h>

/* Main function of the program */
int main(void)
{
	/* Initialising variables. */
	char sentence[30];	//creates the string, or char array.

printf("Enter a sentence:\n");	//Asks user for a sentence
scanf("%s",sentence);
printf("You input: %s\n", sentence);

/*	Upon running two programs, each reading in a single word, then
	printing the word back to the user, one program using fgets()
	and the other scanf, it was noted that the fgets program printed
	the statement with an extra empty line after it.
	
	This is because both functions read a string, and stop reading
	when they reach a newline statement, \n, when the user hits the
	return key.
	
	The difference is that scanf stops at the newline character, but
	does not include it in the string. fgets() stops reading when it
	reaches a newline, but it considers it a valid character and
	includes it in the string.
	
	As there was a \n within the printf statement for both, there
	was a single blank line after the scanf program and 2 lines
	after the fgets version.
	
	It is worth also noting that scanf can will only read in one word
	when a single %s format specifier is supplied, so if a user
	enters more than one word, scanf() will stop reading at a space
	character. So a user cannot enter a single string which contains
	multiple words when using scanf(). In that case, fgets() would
	have to be used.
*/

	return 0;
}