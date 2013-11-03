/*	Program28.c: 
	Authors: Patrick Moorehouse
	Last Modified: 27/11/2012
*/

#include <stdio.h>

int main(void)
{

/* Initialising variables. */
char input[50]; //string (char array)

printf("Please enter a sentence (max 50 chars): \n");
fgets(input, 50, stdin);
printf("The character array starting from memory location %u, contains: %s\n", input, input);

//This program produces the same effect as "program27.c"
//This is because although we have declared an array this time and
//not a pointer as before, arrays behave like pointers.
//An array variable is effectively a pointer to the first element
//of the array.

return 0;
}