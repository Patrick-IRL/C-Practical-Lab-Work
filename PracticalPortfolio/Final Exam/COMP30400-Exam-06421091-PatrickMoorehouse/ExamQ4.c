/*	filename.c:		Program description.
	Authors: Patrick Moorehouse
	Last Modified: 21/12/2012
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_file(FILE *fp1);
void reverse(char* temp, int count);

int main(void)
{
	FILE *fp1;
	char fname[] = "input.txt";
	
	if ( (fp1 = fopen(fname, "r" )) == NULL )
	{
		printf("cannot open file %s for reading\n", fname);
		exit(1);
	}
	
	printf("\n\n1: Displaying contents of %s in reverse.\n\n", fname);
	read_file(fp1);
	
	fclose(fp1);
	return 0;
}

void read_file(FILE *fp1)
{
	char c;
	char temp[1000];
	int count = 0;
	
	c = getc(fp1);
	while (c != EOF)
	{
		temp[count] = c;
		c = getc(fp1);
		count += 1;
	}
	reverse(temp, count);
}

void reverse(char* temp, int count)
{
	int k;
	for (k = count; k>=0; k--){				
	printf("%c",temp[k]);
	}
}