/*	Program27.c: 	Program to demonstrate declaration of a pointer to
					a data type, and allocating memory to store data at
					that address.
	Authors: Patrick Moorehouse
	Last Modified: 27/11/2012
*/

#include <stdio.h>


int main(void)
{

/* Initialising variables. */
char *memory; //Pointer to a char
memory = (char*)malloc(50);//allocates memory to hold char values.

printf("Enter a sentence (max 50 chars): \n");
fgets(memory, 50, stdin);
printf("The character array starting from memory location %u, contains: %s\n", memory, memory);
//memory was declared as a pointer, so using format specifier %u returns the value of
//the pointer, that is, the address it points to in memory.
return 0;
}