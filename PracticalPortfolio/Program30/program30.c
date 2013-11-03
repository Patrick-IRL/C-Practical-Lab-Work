/*	Program30.c:	Program that modifies characters in a string using
					a pointer and pointing to addresses in the array.
	Authors: Patrick Moorehouse
	Last Modified: 05/12/2012
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *word; //pointer to char
	char *ptr; //pointer to char
	word = (char*)malloc(50 * sizeof(char));//allocate space for word
	if (word == NULL)//warning if not enough memory
	{
		printf("ERROR: Not Enough Memory.\n");
		return 2;
	}
	
	//user input into "word"
	printf("Please enter a word:\n");
	fgets(word, 50, stdin);
	
	ptr = &word[1]; //setting address ptr points to to the address of word[1]
	*ptr = '_'; //setting value at address ptr points to to _ (underscore)
	ptr = ptr+2; //incrementing the address that ptr points to by 2 places
	*ptr = '$'; //setting value at address ptr points to to $
	printf("%s\n", word); //prints word with its modified contents.
	
	//releases memory allocated to word
	free(word);
	return 0;
}