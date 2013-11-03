/*	sizes.c:	Program to display the size of various variable types.
	Authors: Patrick Moorehouse
	Last Modified: 02/11/2012
*/

//Includes required header files.
#include <stdio.h>

/* Main function of the program */
int main(void)
{

	/* Initialise variable to store size of int */
	int size_of_int = sizeof(int);
	/* Initialise variable to store size of char */
	int size_of_char = sizeof(char);
	/* Initialise variable to store size of float */
	int size_of_float = sizeof(float);
	/* Initialise variable to store size of double */
	int size_of_double = sizeof(double);
	
	/* creating an array of ints */
	int int_array[3];
	/* Initialise variable to store size of int array */
	int size_int_array = sizeof(int_array);
	
	/* creating an array of chars */
	char char_array[4];
	/* Initialise variable to store size of char array */
	int size_char_array = sizeof(char_array);
	
	/* creating an array of floats */
	float float_array[5];
	/* Initialise variable to store size of float array */
	int size_float_array = sizeof(float_array);
	
	/* creating an array of doubles */
	double double_array[6];
	/* Initialise variable to store size of double array */
	int size_double_array = sizeof(double_array);

	/* print funtion using %d to output the variable value */
	printf("Size of int:\t\t%d bytes\n", size_of_int);
	printf("Size of Char:\t\t%d bytes\n", size_of_char);
	printf("Size of float:\t\t%d bytes\n", size_of_float);
	printf("Size of Double:\t\t%d bytes\n", size_of_double);
	printf("Size of int array:\t%d bytes\n", size_int_array);
	printf("Size of char array:\t%d bytes\n", size_char_array);
	printf("Size of float array:\t%d bytes\n", size_float_array);
	printf("Size of double array:\t%d bytes\n", size_double_array);

	return 0;
}