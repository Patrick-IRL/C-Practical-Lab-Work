/*	Program35.c: Program to display contents of file, 20 lines at a time.
					User has option to quit before file has been fully read.
	Authors: Patrick Moorehouse
	Last Modified: 08/12/2012
*/

#include <stdio.h>
#include <stdlib.h>

//funtion to wait on user input.
void wait_for_user(char *operator, int *number);

/* Main function of the program */
int main(void)
{
	char c, operator = 'a', fname[] = "doc.txt";
	int line_count = 0;
	FILE *fp1;//file pointer.
	
	//Opening and testing file opened in one step.
	if ( (fp1 = fopen(fname, "r" )) == NULL )
	{
		printf("Cannot open file %s for reading\n", fname);
		exit(1);
	}
	
	//Get first char from file.
	c = getc(fp1);
	//begin a loop that will run to the end of the file.
	while(c != EOF){
	
	//print each char of file one at a time after they are read.
	printf("%c", c);
	
	//Counts number of newline characters to determine how many
	//lines have been read so far.
	if (c == '\n')
	{
		line_count = line_count + 1;
	}
	
	//when 20 lines printed, call function for user to input
	//their choice to proceed or quit.
	if (line_count == 20){
	wait_for_user(&operator, &line_count);
	}
	
	//if user chooses to quit, break loop and end program
	if (operator=='q'){
	printf("\nQuiting program...\n");
	break;
	}
	
	//if they choose to continue, just allow loop to continue
	else{
	}
	
	//gets the next char in the file.
	c = getc(fp1);
	}//end of while loop
	
	//notifies the user file has ended and program ends.
	if (c == EOF){ printf("\nEnd of file has been reached.\n"); }
	
	//close file.
	fclose(fp1);
	return 0;
}

void wait_for_user(char *operator, int *number)
{
	//resets the line count so that it begins from 0 again.
	*number = 0;
	
	char op[2];
	printf("Press Enter to continue, or press q to quit.\n");
	//fgets() and sscanf() used to read in and process user input.
	fgets(op, 2, stdin);
	sscanf(op, "%c", operator);
}