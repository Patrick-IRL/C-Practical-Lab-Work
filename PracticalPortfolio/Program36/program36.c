/*	Program36.c:	Program to count the number of {, ( and [ brackets,
					and the number of }, ) and ] brackets in a .c source
					file and check if the numbers match.
					Can be used to help locate errors in source code.
	Authors: Patrick Moorehouse
	Last Modified: 09/12/2012
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Main function of the program */
int main(int argc, char *argv[])
{
	//sets int equal length of argument, so can set char array
	//of length equal to the file name.
	int arg_length = strlen(argv[1]);
	
	//Declaring and initialising ints to be used as counters for
	//various bracket types.
	int curly_bracket_open = 0, curly_bracket_close = 0;
	int round_bracket_open = 0, round_bracket_close = 0;
	int square_bracket_open = 0, square_bracket_close = 0;
	int newline_count = 1;//will ciount number of lines.
	
	//Sets array for file name equal to length of argument for file name
	//and declares a char variable, c.
	char fname[arg_length], c;
	FILE *fp1; //file pointer.

	
	//processes argument to extract file name and transfer it to char array.
	sscanf(argv[1], "%s", &fname);

	//opens and tests if opened successfully in one step.
	if ( (fp1 = fopen(fname, "r" )) == NULL )
	{
		printf("cannot open file %s for reading\n", fname);
		exit(1);
	}
	
	//Let user know that the file is now being processed.
	printf("\nAnalysing file %s:\n\n", fname);

	//get first char of file.
	c = getc(fp1);
	//begin loop and run until end of file has been reached.
	while (c != EOF)
	{
		//Sets out all the conditional statements that will increment
		//the counter for each of the bracket types when its
		//corresponding bracket type has been encountered in the file.
		
		//Curly brackets, {}
		if (c == '{')
		{
			curly_bracket_open += 1;
		}
		else if (c == '}')
		{
			curly_bracket_close += 1;
		}
		
		//Round brackets ()
		else if (c == '(')
		{
			round_bracket_open += 1;
		}
		else if (c == ')')
		{
			round_bracket_close += 1;
		}
		
		//Square brackets []
		else if (c == '[')
		{
			square_bracket_open += 1;
		}
		else if (c == ']')
		{
			square_bracket_close += 1;
		}
		
		//Counts number of lines.
		else if (c == '\n')
		{
			newline_count += 1;
		}
		
		else{
		} //empty else statement, ignores other char types.
		
		//get next char
		c = getc(fp1);4
		
	}//end of while loop
	
	//setting out conditions to report any discrepancies in the number
	//of brackets in the source code.
	
	//Curly brackets
	//More opening than closing
	if (curly_bracket_open > curly_bracket_close)
	{
		printf("Number of opening and closing curly brackets does not match.\n");
		printf("You are missing %d closing bracket(s).\n\n", (curly_bracket_open - curly_bracket_close) );
	}
	//More closing than opening
	if (curly_bracket_open < curly_bracket_close)
	{
		printf("Number of opening and closing curly brackets does not match.\n");
		printf("You have %d more closing bracket(s) than opening brackets.\n\n", (curly_bracket_close - curly_bracket_open) );
	}
	
	//round brackets
	//More opening than closing
	if (round_bracket_open > round_bracket_close)
	{
		printf("Number of opening and closing round brackets does not match.\n");
		printf("You are missing %d closing bracket(s).\n\n", (round_bracket_open - round_bracket_close) );
	}
	//More closing than opening
	if (round_bracket_open < round_bracket_close)
	{
		printf("Number of opening and closing round brackets does not match.\n");
		printf("You have %d more closing bracket(s) than opening brackets.\n\n", (round_bracket_close - round_bracket_open) );
	}
	
	//Square brackets
	//More opening than closing
	if (square_bracket_open > square_bracket_close)
	{
		printf("Number of opening and closing square brackets does not match.\n");
		printf("You are missing %d closing bracket(s).\n\n", (square_bracket_open - square_bracket_close) );
	}
	//More closing than opening
	if (square_bracket_open < square_bracket_close)
	{
		printf("Number of opening and closing square brackets does not match.\n");
		printf("You have %d more closing bracket(s) than opening brackets.\n\n", (square_bracket_close - square_bracket_open) );
	}
	
	//final set of statements to print the actual numbers of each bracket type.
	printf("Curly Brackets: There are %d opening, %d closing.\n", curly_bracket_open, curly_bracket_close);
	printf("Round Brackets: There are %d opening, %d closing.\n", round_bracket_open, round_bracket_close);
	printf("Square Brackets: There are %d opening, %d closing.\n", square_bracket_open, square_bracket_close);
	printf("There are %d lines of code in %s\n", newline_count, fname);//prints number of lines of code in the source
	
	//closes file.
	fclose(fp1);
	return 0;
}