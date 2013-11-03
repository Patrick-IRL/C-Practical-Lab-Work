/*	Program20b.c: Program that takes a sentence using fgets().
	Authors: Patrick Moorehouse
	Last Modified: 12/11/2012
*/

#include <stdio.h>

//sets a constant which determines fgets() string length.
const int SENTENCE_LENGTH=100;

/* Main function of the program */
int main(void)
{
	/* Initialising variables. */
	char sentence[SENTENCE_LENGTH];	//creates the string, or char array.

	printf("Enter a sentence:\n");	//Asks user for a sentence
	//fgets calls for input into "sentence",
	//with character limit = SENTENCE_LENGTH
	fgets(sentence, SENTENCE_LENGTH, stdin);
	printf("You input: %s\n", sentence);

	//Note: A similar program was written using scanf() instead
	//of fgets to take the input. See "program20b.c" comments
	//for details and an explanation into the different behaviours
	//of fgets() and scanf().
	return 0;
}