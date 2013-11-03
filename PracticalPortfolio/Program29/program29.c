/*	program29.c:	calculator, with numbers and operator entered
					as command line arguments for main()
	Author:			Patrick Moorehouse
	Last Modified:	04/12/2012
*/

#include <stdio.h>

//declares math operation function, whose parameters are two numbers
//and an operator. These are given to main() as arguments, then
//passed to math_op as parameters when the function is called.
void math_op(int i, char op, int j);

int main(int argc, char *argv[])
{
	int i, num1, num2;
	char operator;
	
	printf("You supplied %d arguments\n", argc);
	
	//Listing the arguments of the program for informational purposes.
	for(i=0; i<argc; i++){
	printf("argument %d = %s\n", i, argv[i]);
	}
	
	//Setting out the set of statements to execute if there are not
	//enough arguments to perform mathematical operation.
	if(argc <= 1){
	printf("No mathematical arguments were supplied on the command line.\n");
	printf("No Mathematical operations will be performed.\n");
	}
	//When the correct number of statements are supplied, a number,
	//followed by an operator, followed by a number, the arguments are
	//processed so the operation can be performed.
	else if((argc > 1)&&(argc<=4)){
	sscanf(argv[1], "%d", &num1);
	sscanf(argv[2], "%c", &operator);
	sscanf(argv[3], "%d", &num2);
	
	//call math operation function, passing to it the arguments from main()
	math_op(num1, operator, num2);
	}
	//This warns user if there were extra arguments, stating they will
	//be ignored, but the math operation will still be performed using
	//arguments 1-3 as above.
	else{
	printf("Too many arguments were supplied to command line.\n");
	printf("The math operation will be performed, but any extra arguments will be ignored.\n");
	
	sscanf(argv[1], "%d", &num1);
	sscanf(argv[2], "%c", &operator);
	sscanf(argv[3], "%d", &num2);

	//call math operation function, passing to it the arguments from main()
	math_op(num1, operator, num2);
	}
	return 0;
}

void math_op(int i, char op, int j)
{
	//array to store all possible answers relating to the two numbers
	//supplied.
	int answers[4];

	/* Setting operator values */
	answers[0] = i + j;
	answers[1] = i - j;
	answers[2] = i * j;
	answers[3] = i / j;
	
	/* Perform the math operations and report the results to user
		separating the different operators with it statements*/
	
	if (op=='+'){
	/* Adding the numbers */
	printf("The sum of %d + %d = %d\n", i, j, answers[0]);
	}
	
	else if (op == '-') {
	/* Subtracting the numbers */
	printf("The subtraction of %d from %d = %d\n", j, i, answers[1]);
	}
	
	else if (op == 'x') {
	/* Multiplying the numbers */
	printf("The multiplication of %d x %d = %d\n", i, j, answers[2]);
	}
	
	else if (op == '/') {
	/* Dividing the numbers */
	printf("The division of %d by %d = %d\n", i, j, answers[3]);
	}
	
	else{
	printf("You have not entered a valid math operator.");
	}
}


