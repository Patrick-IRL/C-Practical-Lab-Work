/*	filename.c:		Program description.
	Authors: Patrick Moorehouse
	Last Modified: 21/12/2012
*/

//including some standard header files.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//declaring the function that will display file contents
//one line at a time
void display_lines(FILE *fp1);

int main(void)
{
	FILE *fp1;
	char fname[] = "input.txt";
	int word_count = 0;
	
	if ( (fp1 = fopen(fname, "r" )) == NULL )
	{
		printf("cannot open file %s for reading\n", fname);
		exit(1);
	}
	
	printf("\n\n1: Displaying contents of %s\n\n", fname);
	display_lines(fp1);

	fclose(fp1);
	return 0;
}

void display_lines(FILE *fp1)
{
	char string[BUFSIZ];
	//reads and then prints each line of the file
	//until it reaches the end of the file.
	while (fgets(string, sizeof string, fp1) != NULL)
	{
		fputs(string, stdout);
	}
}