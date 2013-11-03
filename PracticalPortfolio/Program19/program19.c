/*	Program19.c: Program that takes a word, compares against a secret
					word stored as a constant. Tells user if guess
					was right or wrong. Only 3 guesses permitted.
	Authors: Patrick Moorehouse
	Last Modified: 11/11/2012
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Main function of the program */
int main(void)
{
	/* Initialising variables. */
	const char secret[] = "defilade";	//creates the string, or char array.
	char guess[30];		//int, will be used for counting letters.
	int i=0;		//int, will be used in for loop to specify element.
	
//Will run loop 3 times, giving the user 3 opportunities to guess the word.
for(i = 0;i < 3;i++){

printf("Enter a word: ");	//Asks user for a Word
scanf("%29s", guess);		//User enters a word.

//if guess is correct, notify user and break from loop to end program.
if(strcmp(secret,guess)==0){
printf("Correct guess! Well Done! %s is the secret word!",guess);
break;
}

//if gues is incorrect, notify user, loop will move on to next iteration.
else{
printf("Sorry, %s is not the secret word. Try again...\n",guess);
}

}//end of for loop

	return 0;
}