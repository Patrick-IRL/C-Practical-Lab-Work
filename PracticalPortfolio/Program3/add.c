/*	add.c: 		Program that reads in two numbers from user,
				then adds their values and prints the result.
	Authors: Patrick Moorehouse
	Last Modified: 02/11/2012
*/

//Includes header file which contains functions
//for input and output of information 
#include <stdio.h>

/* Main function of the program */
int main(void)
{

	/* Declaring vairiables and initialising their values. */
	int x = 2;
	int y = 3;
	/* Declaring the third variable and equating it to x+y */
	int z = x + y;

	/*	print funtion using format specifier %d to
		output the variable value	*/
	printf("%d\n", z);
	return 0;
}