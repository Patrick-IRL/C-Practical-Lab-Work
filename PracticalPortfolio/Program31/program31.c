/*	Program31.c: Program that takes a word, compares against a secret
					word stored in a file. Tells user if guess
					was right or wrong.
	Authors: Patrick Moorehouse
	Last Modified: 05/12/2012
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
	int i=0;		//int, will be used in for loop to specify element.
	char filename[] = "secret.txt";//char array to hold file name
	FILE *fp; //declares pointer to file
	
	//Combines opening the file with testing that it opened correctly
	if ( (fp = fopen(filename, "r" )) == NULL )
	{
		printf("cannot open file %s for reading\n", filename);
		exit(1);
	}
	//reads the word from the file and stores it in char array
	fscanf(fp, "%s" , &secret);
	fclose(fp);//closes file now that we are finished with it.
	
for(i = 0;i < 3;i++){

printf("Enter a word: ");	//Asks user for a Word
scanf("%29s", guess);		//User enters a word.

//if guess is correct, notify user and break from loop to end program.
if(strcmp(secret,guess)==0){
printf("Correct guess! Well Done! %s is the secret word!\n",guess);
break;
}

//if gues is incorrect, notify user, loop will move on to next iteration.
else{
printf("Sorry, %s is not the secret word. Try again...\n",guess);
}

}//end of for loop

	return 0;
}