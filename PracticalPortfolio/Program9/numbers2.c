/*	numbers2.c:	Program that takes two numbers from the user and
				calculates the sum(+) and subtraction(-) of the two
				numbers, displaying the results to the user on screen.
				
				Based on "numbers.c" but uses arrays of integers
				instead of individually declared variables.
	Authors: Patrick Moorehouse
	Last Modified: 06/11/2012	*/

//Includes required header files.
#include <stdio.h>

/* Main function of the program */
int main(void)
{
	/* Declaring array of integers. */
	int numbers[2];
	
	/* Ask user to input the first number. */
	printf("Enter a number, x:\n");
	/* Read in value from user into array */
	scanf("%d", &numbers[0]);
	
	/* Ask user to input the first number. */
	printf("Enter a number, y:\n");
	/* Read in value from user into array */
	scanf("%d", &numbers[1]);
		
	/* Perform the math operations and report the results to user */
	/* Adding the numbers */
	int answers[2];	//Declaring array to store answers
	answers[0] = numbers[0] + numbers[1];
	printf("The sum of x + y = %d\n", answers[0]);
	
	/* Subtracting the numbers */
	answers[1] = numbers[0] - numbers[1];
	printf("The sum of x + y = %d\n", answers[1]);
	
	return 0;
}