// a set of instructions examining pointers

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	// declare two character arrays

	char *array, *another_array;
	int i, x;
	
	// print their locations in memory
	printf("Two arrays have been declared. Their memory addresses are \n");
	printf("%u %u\n\n", array, another_array);
	
	// assign some memory to the first pointer and print the locations in memory of both arrays
	array=malloc(80);
	printf("allocate some memory to the first array. The address of both arrays is now\n");
	printf("%u %u\n\n", array, another_array);
	
	// assign some characters to one of the array and print out the addresses of both arrays
	strcpy(array, "hello world");
	printf("The string 'hello world' has been assigned to the first of the two arrays.\n");
	printf("The memory addresses of the two arrays remain unchanged\n");
	printf("%u %u\n\n", array, another_array);
	
	// line 34 assigns the memory address of 'array' to 'another_array' and prints out the addresses of both
	// line 34 is actually creating a third array with the address of 'array' and the name 'another_array'
	// the array at the original location of 'another_array' still exists,
	// but can no longer be accessed as it's name has been assigned to the new array.
	// therefore we are not allowed to use this method of assigning string values to arrays and must use the strcpy function 
	another_array=array;
	printf("The second array has been assigned the value of the first\n");
	printf("This changes the second arrays memory location to be the same as the first array's.\n");
	printf("Their addresses are now\n");
	printf("%u %u\n\n", array, another_array);
	
	// mess around with the memory location data by using just one of the array names
	another_array[2]='T';
	printf("One of the characters in the second array has been changed to a 'T'\n\n");
	
	x=strlen(another_array);
	
	// print out both arrays
	printf("The second array now contains the following characters\n\n");
	for (i=0; i<x; i++)
	{
		printf("%c\n",another_array[i]);
	}
	
	printf("\n\nAs both arrays use the same memory address the first array contains the following identical characters\n\n");
	for (i=0; i<x; i++)
	{
		printf("%c\n",array[i]);
	}
	
	// free the arrays memory and print out the addresses of both and what they contain
	free(array);
	free(another_array);
	printf("The memory addresses of both arrays have now been freed\n\n");
	printf("The first array now contains the following characters\n\n");
	for (i=0; i<x; i++)
	{
		printf("%c\n",array[i]);
	}
	
	printf("\n\nAs both arrays use the same memory address the second array contains the following identical characters\n\n");
	for (i=0; i<x; i++)
	{
		printf("%c\n",another_array[i]);
	}
	
	printf("\nThe addresses of both arrays remain\n");
	printf("%u %u\n", array, another_array);
	
	return 0;
}