/*	Program22.c:	Program to replace vowels with a $ symbol.
	Author(s):		Patrick Moorehouse
	Last Modified:	12/11/2012
*/

#include <stdio.h>

int main(void)
{

/* Declaring variables */
char sentence[80];
int i = 0;

//gets sentence from user
printf("Enter a sentence:\n");
fgets(sentence, 80, stdin);

//while loop will continue looping until it reaches the end of the string
while(!(sentence[i] == '\0'))
{

//specifies code to execute if the current element of sentence is a vowel.
if 	((sentence[i] == 'a')||(sentence[i] =='e')
	||(sentence[i] =='i')||(sentence[i] =='o')
	||(sentence[i] =='u'))
{
//replaces the value of char with a $ symbol.
//Due to conditions for this code to execute, result will be that
//all vowels in the string get replaced by the $ symbol
//but consonants are ignored.
sentence[i] = '$';
i++;//increment i to examine next char in sentence.
}


else	//for any other character besides vowels
{		//do nothing, only increment i and move on to next element
i++;
}
}//end of while loop, due to end of string reached.

printf("%s",sentence);	//prints the initial statement but with all
						//vowels replaced

return 0;
}