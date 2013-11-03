/* example_funcion.c
 *
 *
 */

#include <stdio.h>

int example(char *array, int number);

int main(void)
{
	char array[] = "123word";//String of letters and numbers.
	char word[10];//empty char array
	int three = 3;//integer variable = 3.
	
	printf("example() returned: %d\n", example(array, three) );
	
	sscanf(array, "%d%s", &three, word);
	printf("Variables contain: %d %s\n", three, word);

	return 0;
}

int example(char *string, int number)
{
	printf("array contains: %s, number contains: %d\n", string, number);
	return number*2;
}