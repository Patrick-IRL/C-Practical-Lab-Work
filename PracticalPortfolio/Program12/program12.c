/*	program12.c:
				Program that asks the user to enter a math operator,
				(+, -, *, /), corresponding to which mathematical
				operation they wish to perform. The user then enters
				two numbers for the operation to be performed on.
				
				Makes use of the while loop safety precaution utilised
				in "program11.c" to ensure the proper operator is
				accepted and a newline character does not get submitted
				erroneously in its place.
	Authors: Patrick Moorehouse
	Last Modified: 06/11/2012	*/

//Includes required header files.
#include <stdio.h>

/* Main function of the program */
int main(void)
{
	/* Declaring variables. */
	int numbers[2]; //Will hold the two numbers to be operated on.
	int answers[4]; //Will hold all possible operation results.
	char operator;  //Holds the operator.
	
	//Asks user to choose the math operation they wish to perform.
	printf("Enter a math operation, +, -, * or /\n");
	operator = getchar();//Getting operator.
	//Safety precaution to ensure operator is accepted properly.
	while (operator == '\n'){
	operator = getchar();
	}
	
	/* Ask user to input the first number. */
	printf("Enter a number, x:\n");
	/* Read in value from user */
	scanf("%d", &numbers[0]);
	
	/* Ask user to input the first number. */
	printf("Enter a number, y:\n");
	/* Read in value from user */
	scanf("%d", &numbers[1]);
		
	/* Calculating all possible operation results in
		preparation for return to user. */
	answers[0] = numbers[0] + numbers[1];
	answers[1] = numbers[0] - numbers[1];
	answers[2] = numbers[0] * numbers[1];
	answers[3] = numbers[0] / numbers[1];
	
	/* Perform the math operations and report the results to user
	separating the different operators with conditional statements*/
	
	if (operator=='+'){
	/* Result of adding the numbers */
	printf("The sum of x + y = %d\n", answers[0]);
	}
	
	else if (operator == '-') {
	/* Result of subtracting the numbers */
	printf("The sum of x - y = %d\n", answers[1]);
	}
	
	else if (operator == '*') {
	/* Result of multiplying the numbers */
	printf("The sum of x * y = %d\n", answers[2]);
	}
	
	else if (operator == '/') {
	/* Result of dividing the numbers */
	printf("The sum of x / y = %d\n", answers[3]);
	}
	
	//This statement accounts for the potential for users to
	//input the wrong operator type, and reports to them if they
	//have done so.
	else{
	printf("You have not entered a valid math operator.");
	}
	
	return 0;
}