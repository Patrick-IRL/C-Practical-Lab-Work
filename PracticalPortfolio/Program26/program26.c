/*	program26.c:	example of main with arguments/parameters
	Author:			Patrick Moorehouse
	Last Modified:	20/11/2012
*/

#include <stdio.h>

//This is an alternative type of main()
//It is still of type int, so will return an int value.
//However, the program can now take arguments from the command line.
//These arguments can be used for many things, inputting numerical
//values, names, various data types, or to control how the program
//will function by specifying options through arguments.
int main(int argc, char *argv[])
{
	//int argc is the number arguments supplied.
	//argv is the argument itself.
	//argv[] is an array of arguments.
	int i;
	
	printf("You supplied %d arguments\n", argc);
	
	//loops through all arguments in the argv[] array and prints
	//their values to screen.
	for(i=0; i<argc; i++){
	printf("argument %d = %s\n", i, argv[i]);
	}
	
	return 0;
}