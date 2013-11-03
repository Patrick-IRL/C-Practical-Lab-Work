/*	Program34.c: Program to compare and tell if files are identical.
			3 test files included, doc1, doc2 and doc3.
			doc1 and doc2 are the same, so can test for identical files.
			doc3 is different, so can be used to test when files are not
			identical.
	Authors: Patrick Moorehouse
	Last Modified: 08/12/2012
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Main function of the program */
int main(void)
{
	//declaring variables for file names and for chars to read from file
	char fname1[40], fname2[40], fname[40], ca, cb;
	FILE *fp1, *fp2; //file pointers.
	
	//Get first file name from user.
	printf("Enter the first filename: ");
	//Note, scanf() leaves the \n after entry in the buffer.
	//Use fgets to read input, and sscanf to properly process input
	//and assign the file name to an array with no abnormal behaviour,
	//such as skipping over the following user input.
	fgets(fname, 40, stdin);
	sscanf(fname,"%s",&fname1);
	
	//Get second file name from user.
	printf("Enter the second filename: ");
	//As mentioned above, fgets() and sscanf() used as they are safer than
	//scanf() alone, which can cause erroneous abnormal behaviour.
	fgets(fname, 40, stdin);
	sscanf(fname,"%s",&fname2);
	
	//Opens file and tests if opened successfully in one step.
	if ( (fp1 = fopen(fname1, "r" )) == NULL )
	{
		printf("Cannot open file %s for reading\n", fname1);
		exit(1);
	}
	
	//Opens file and tests if opened successfully in one step.
	else if ( (fp2 = fopen(fname2, "r" )) == NULL )
	{
		printf("cannot open file %s for writing\n", fname2);
		exit(1);
	}
	
	//When both files open successfully.
	else
	{
	//Lets user know program is performing operation.
	printf("Comparing files %s and %s\n", fname1, fname2);
	
	//Loops until one of the files ends or a difference in
	//the files is detected.
	while ( (ca != EOF) && (cb != EOF) && (ca==cb) )
	{
		ca = getc(fp1);
		cb = getc(fp2);
	}
	
	//If both files end and the last char is the same, files identical.
	if (ca==cb)
	{
		printf("Files %s and %s are identical.\n", fname1, fname2);
	}
	//If one file ends before the other, or a difference was found,
	//they cannot be identical.
	else if (ca != cb)
	{
		printf("Files %s and %s are NOT identical.\n", fname1, fname2);
	}
	
	//closes files when they are no longer needed.
	fclose(fp1);
	fclose(fp2);
	}
	return 0;
}