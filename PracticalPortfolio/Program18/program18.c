/*	Program18.c: Program that takes a word, compares against a secret
					word stored as a constant. Tells user if guess
					was right or wrong.
	Authors: Patrick Moorehouse
	Last Modified: 11/11/2012
*/

#include <stdio.h>
#include <string.h>

/* Main function of the program */
int main(void)
{
	/* Initialising variables. */
	const char secret[] = "defilade";	//Secret word contant.
	char guess[30];		//string used for guess input.
	int i=0;		//int, if guess is correct, i=i+1 to exit loop.
	
printf("Enter a word: ");	//Asks user for a Word
scanf("%29s", guess);		//User enters a word.


/*	int i = 0, so loop will continue indefinitely. However, if guess
	is correct, i is set to 1, which terminates the while loop and
	displays a message to the user that their guess was right.
*/	
while(i < 1){

if(strcmp(secret,guess)==0){ //tests if guess was right via string compare
printf("Correct guess! Well Done! %s is the secret word!\n",guess);
i=1; //if correct, i set to 1 to exit loop.
}

else{
printf("Sorry, %s is not the secret word. Try again...\n\n",guess);
printf("Enter a word: ");	//Asks user for a Word
scanf("%29s", guess);		//User enters a word.
}

}//end of while loop

	return 0;
}