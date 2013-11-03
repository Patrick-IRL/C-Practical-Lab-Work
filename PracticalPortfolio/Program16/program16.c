/*	Program16.c: Program that takes a word, counts characters.
	Authors: Patrick Moorehouse
	Last Modified: 11/11/2012
*/

#include <stdio.h>

/* Main function of the program */
int main(void)
{
	/* Initialising variables. */
	char word[30];	//creates the string, or char array.
	int x=0;		//int, will be used for counting letters.
	int i=0;		//int, will be used for while loop to specify element.
	
printf("Enter a word: ");	//Asks user for a Word
scanf("%29s", word);		//User enters a word.


/*	int i = 0, so word[i] = first character. each time the loop is
	executed, i is incremented, so the next character of string is
	used to test condition of while loop, i.e. that the character
	selected is not equal to zero. When the end of the string is reached,
	word[i] will equal \0, so no further count is added and the loop ends.
*/	
while(word[i] != '\0'){

x = x + 1; //Adding 1 to count for each character of the string.

i = i + 1;	//Adds 1 to int i so that on next iteration of loop
			//the next character of string is tested.
}

printf("You entered the word: %s \n", word);
//Prints word input by user.
printf("%s has %d characters.\n", word, x);
//States how many letters in word.
	return 0;
}