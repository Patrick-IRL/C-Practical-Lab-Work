/*	program13.c:
				Program that asks the user to enter a math operator,
				(+, -, *, /, or q to quit), corresponding to which mathematical
				operation they wish to perform. The user then enters
				two numbers for the operation to be performed on.
				
				The program will repeat indefinitely until the user chosses
				to end the program by choosing the operator "q" to quit.
				
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
	//Declaring char for operator and initialising value.
	//Value must be initialised as operater will be used as condition
	//for while loop, so must set value to avoid unpredictable behaviour
	//resulting from variable taking on random data value from memory.
	char operator = 'a';
	
	//Begins the programs main loop, which will repeat until users quits.
	while(operator != 'q'){
	
	//reading in which operation the user wishes to perform.
	printf("Enter a math operation, +, -, *, / or q to quit.\n");
	operator = getchar();
	//While loop used as precaution, as explained in comments for
	//"program11.c"
	while (operator == '\n'){
	operator = getchar();
	}
	
	//If the user opts to quit...
	if (operator=='q'){
	printf("Quiting program...");
	break; //The loop is broken so the program can conclude.
	}
	else{
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
		separating the different operators with it statements*/
	
	if (operator=='+'){
	/* Adding the numbers */
	printf("The sum of x + y = %d\n", answers[0]);
	}
	
	else if (operator == '-') {
	/* Subtracting the numbers */
	printf("The subtraction of y from x = %d\n", answers[1]);
	}
	
	else if (operator == '*') {
	/* Multiplying the numbers */
	printf("The multiplication of x * y = %d\n", answers[2]);
	}
	
	else if (operator == '/') {
	/* Dividing the numbers */
	printf("The division of x by y = %d\n", answers[3]);
	}
	
	//This statement accounts for the potential for users to
	//input the wrong operator type, and reports to them if they
	//have done so.
	else{
	printf("You have not entered a valid math operator.");
	}
	
	}
	return 0;
}