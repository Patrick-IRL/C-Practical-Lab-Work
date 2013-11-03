#include <stdio.h>

/* Main function of the program */
int main(void)
{
	/* Initialising char array.
	Allowing for a maximum of 2 characters */
	char colour[2];
	/* Ask user to input their favourite colour */
	printf("What is your favourate colour?\n");
	/* Take input from user. Intention is to input beyond the range of the char array,
		so that the program writes into unreserved memory but hopefully wont crash yet.*/
	scanf("%s", colour);
	/* Report to user on their choice. Will try to retrieve data outside allocated memory,
		so that the program crashes. colour[0] finishes ok, will colour[5]? */
	printf("You said: %c\n", colour[0]);
	
	/* up to 13 characters, the program executes addressing colour[0], 14 characters and
		the program executes, but repeats itself without end.  15 characters and
		the program crashses immediately. */
	
	
	return 0;
}