#include <stdio.h>

/* Main function of the program */
int main(void)
{
	/* Initialising variables. */
	int a;
	int b;
	int c;
	
	
	/* Ask user to input the first number. */
	printf("Enter a number, x:\n");
	/* Read in value from user */
	scanf("%d", &a);
	
	/* Ask user to input the second number. */
	printf("Enter a number, y:\n");
	/* Read in value from user */
	scanf("%d", &b);

	/* Ask user to input the second number. */
	printf("Enter a number, y:\n");
	/* Read in value from user */
	scanf("%d", &c);

	
	/* Perform comparisson with if statements */
	if(a > b && a > c){
	printf("The largest number is = %d\n", a);
	}
	else if(b > a && b > c){
	printf("The largest number is = %d\n", b);
	}
	else {
	printf("The largest number is = %d\n", c);
	}
		
	
	return 0;
}