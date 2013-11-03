/*	Program15.c: Char variable, 10000 loops adding 1, test output.
	Authors: Patrick Moorehouse
	Last Modified: 11/11/2012
*/

#include <stdio.h>

/* Main function of the program */
int main(void)
{
	/* Initialising variables. */
	char x = 0; //char variable assigned value = 0
	int i = 0;
	
	
	while (i<10000){
	printf("%d\n", x); //output char value
	x = x+1; //incrementing char value by 1

	i = i + 1; //progresses the while loop
	}
	
	/*	Value output loops through the range of a byte repeatedly.
		Continues to loop from 0 to 127, then from -128 to -1, and
		repeats intil the end of the while loop.
		
		Final value is x = 15, as this was the value happened upon when
		the loop stopped repeating and ended.
	*/
	
	return 0;
}