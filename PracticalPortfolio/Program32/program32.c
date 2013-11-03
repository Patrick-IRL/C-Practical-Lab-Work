/*	Program32.c: Program to copy files, whose names are supplied
					on the command line as arguments to main().
	Authors: Patrick Moorehouse
	Last Modified: 06/12/2012
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Main function of the program */
int main(int argc, char *argv[])
{
	//sets two ints equal to the length of agruments supplied
	//on command line, corresponding to the two file names supplied.
	int arg1_length=strlen(argv[1]);
	int arg2_length=strlen(argv[2]);
	
	//using ints above to declare char arrays that are equal in length
	//to the length of the file names that will be stored in them.
	char file1[arg1_length], file2[arg2_length], c;
	FILE *fp1, *fp2;//file pointers
	
	//passing arguments supplied on command line, which are the desired
	//filenames, into char array variables.
	sscanf(argv[1], "%s", &file1);
	sscanf(argv[2], "%s", &file2);
	
	//opening file1 and testing successful open in one step
	if ( (fp1 = fopen(file1, "r" )) == NULL )
	{
		printf("cannot open file %s for reading\n", file1);
		exit(1);
	}
	//opening file2 and testing successful open in one step
	else if ( (fp2 = fopen(file2, "w" )) == NULL )
	{
		printf("cannot open file %s for writing\n", file1);
		exit(1);
	}
	
	//If both files open successfully, move on to performing
	//file copy operation.
	else
	{
	
	//Lets user know operation is underway and the program is
	//running as intended.
	printf("Copying File %s to File %s\n", file1, file2);
	
	//gets first char of file to be copied.
	c = getc(fp1);
	while (c != EOF)//loops until end of the file.
	{
		putc(c, fp2);//copies the char to the second file
		c = getc(fp1);//gets next char from file 1.
	}
	//when this loop concludes, each char in file 1 will have been
	//copied one at a time into the new file, effectively producing
	//a copy of the first file.
	
	//closing both files when operation complete.
	fclose(fp1);
	fclose(fp2);
	
	//Lets user know that the operation was completed successfully.
	printf("File successfully copied.\n");
	}
	
	return 0;
}