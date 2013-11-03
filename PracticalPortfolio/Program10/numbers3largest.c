/*	numbers3largest.c:
				Program that takes three numbers from the user and
				determines which is the largest and reports result
				to the user.
	Authors: Patrick Moorehouse
	Last Modified: 06/11/2012	*/

//Includes required header files.
#include <stdio.h>

/* Main function of the program */
int main(void)
{
	/* Declaring int array to hold the 3 numbers. */
	int numbers[3];
	
	/* Ask user to input the first number. */
	printf("Enter a number, x:\n");
	/* Read in value from user */
	scanf("%d", &numbers[0]);
	
	/* Ask user to input the second number. */
	printf("Enter a number, y:\n");
	/* Read in value from user */
	scanf("%d", &numbers[1]);

	/* Ask user to input the second number. */
	printf("Enter a number, y:\n");
	/* Read in value from user */
	scanf("%d", &numbers[2]);

	
	/* Perform comparisson with conditional statements */
	//If 1st number is bigger than 2nd and 3rd, return 1st number
	if(numbers[0] > numbers[1] && numbers[0] > numbers[2]){
	printf("The largest number is = %d\n", numbers[0]);
	}
	//If 2nd number is bigger than 1st and 3rd, return 2nd number
	else if(numbers[1] > numbers[0] && numbers[1] > numbers[2]){
	printf("The largest number is = %d\n", numbers[1]);
	}
	//If neither of above is true, only remaining possibility is
	//that the 3rd number is bigger than 1st and 2nd,
	//so 3rd number returned.
	else {
	printf("The largest number is = %d\n", numbers[2]);
	}
	
	return 0;
}