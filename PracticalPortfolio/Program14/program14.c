/*	Program14.c: Assigning a negative to an unsigned int
	to investigate what result is returned.
	Authors: Patrick Moorehouse
	Last Modified: 10/11/2012
*/

#include <stdio.h>

/* Main function of the program */
int main(void)
{
	/* Initialising variables. */
	unsigned int x = 1; //unsigned int assigned value = 1
	printf("x = %u\n", x);
	
	x = x-2; //Turns unsigned int into -1

	//Must use %u, format specifier for unsigned int.
	//%d, signed int, will return a -1 even for an unsigned int.
	printf("x = %u", x);
	
	/*	1 - 2 = -1. A signed int would use last bit to indicate the sign
		However, unsigned int uses last bit for the number value
		Thus, -1 in binary = 1111 1111, 1111 1111, 1111 1111, 1111 1111
		unsigned int will interpret this as 4,294,967,295
		Running program to verify if this is correct.
	*/
	
	/*	Program was run, value predicted was returned.
		Note: must use %u as %d will return a -1,
		even on unsigned int.
	*/
	
	return 0;
}