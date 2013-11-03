/*	Program33.c: Program that takes a word, compares against a secret
					word stored in a file. Tells user if guess
					was right or wrong. If guess is correct, moves on
					to next word in the file.
	Authors: Patrick Moorehouse
	Last Modified: 07/12/2012
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Main function of the program */
int main(void)
{
	/* Initialising variables. */
	char secret[30];	//creates the string, or char array.
	char guess[30];		//int, will be used for counting letters.
	//will be used to tel user how many guesses they have.
	int guesses_left = 3;
	char filename[] = "secret.txt";//char array to hold file name
	FILE *fp; declares pointer to file
	
	//Combines opening the file with testing that it opened correctly
	if ( (fp = fopen(filename, "r" )) == NULL )
	{
		printf("cannot open file %s for reading\n", filename);
		exit(1);
	}
	
	//reads the word from the file and stores it in char array
	fscanf(fp, "%s", &secret);
	
	//loop to run until guesses run out. changed from for loop
	//to while loop as deemed more appropriate, and can tell the user
	//very easily how many guesses they have left.
	while(guesses_left != 0){
	printf("Enter a word: guesses remaining = %d: \n", guesses_left);	//Asks user for a Word
	scanf("%29s", guess);		//User enters a word.

	//if guess is correct, notify user and read next word from file.
	//Also set guesses back to 3 for new word.
	if(strcmp(secret,guess)==0){
	printf("Correct guess! Well Done! %s is the secret word!\n",guess);
	guesses_left = 3;
	//If the end of the file is reached and there are no more words to read,
	//notify user there are no more words to guess and break loop to end program.
	if((fscanf(fp, "%s", &secret))!=1)
	{
		printf("You have guessed all the secret words, there are no more left to guess.\n");
		break;
	}
	}
	
	else{
	//If guess incorrect, notify user and take away one of their guesses.
	printf("Sorry, %s is not the secret word. Try again...\n",guess);
	guesses_left = guesses_left - 1;
	//If guesses run out, notify user and the program will end as loop ends.
	if (guesses_left == 0)
	{
		printf("Sorry, you have run out of guesses.\n");
	}
	}
	
	}//end of while loop
	
	//close file once guesses run out or all words guessed
	fclose(fp);
	return 0;
}