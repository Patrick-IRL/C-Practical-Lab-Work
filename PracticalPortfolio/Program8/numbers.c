/*	numbers.c:	Program that takes two numbers from the user and
				calculates the sum(+) and subtraction(-) of the two
				numbers, displaying the results to the user on screen.
	Authors: Patrick Moorehouse
	Last Modified: 06/11/2012	*/

//Includes required header files.
#include <stdio.h>
	
/* Main function of the program */
int main(void)
{
	/* declaring two integer variables. */
	int x,y;
	
	/* Ask user to input the first number. */
	printf("Enter a number, x:\n");
	/* Read in value from user */
	scanf("%d", &x);
	
	/* Ask user to input the first number. */
	printf("Enter a number, y:\n");
	/* Read in value from user */
	scanf("%d", &y);
		
	/* Perform the math operations and report the results to user */
	/* Adding the numbers */
	int a = x + y;
	printf("The sum of x + y = %d\n", a);
	
	/* Subtracting the numbers */
	int b = x - y;
	printf("The subtraction of y from x = %d\n", b);
	
	return 0;
}