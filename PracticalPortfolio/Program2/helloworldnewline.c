/*	helloworldnewline.c: 	
		The classic first program oone writes when learning
		a new language. Using \n to drop "world" to the next line
	Authors: Patrick Moorehouse
	Last Modified: 02/11/2012
*/

//Includes header file which contains functions
//for input and output of information 
#include <stdio.h>

//main() is where the program begins execution of code
//"int" means it will return an integer value, while "void"
//declares that main() does not take any parameters when executed
int main(void)
{	
	//printf outputs the text to the console (screen).
	printf("Hello,\nworld!\n");
	return 0;	//returning the int value as required by main
				//declaration type
}