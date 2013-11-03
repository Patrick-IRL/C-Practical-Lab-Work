/*	program11.c:
				Program that takes a string and a char from user.
				Upon entry of the string, hitting return leaves the \n
				character in the buffer. This means that getchar() will
				pick this up from the buffer without allowing the user
				to enter their character.
				
				A solution is implemented which involves starting a while
				loop, which will repeat as long as char c equals \n, and
				will ask user to enter char with getchar.
				
				This means that when the \n (newline char) is icked up from
				the buffer, the user will get the opportunity to reassign
				char c to the correct character.
	Authors: Patrick Moorehouse
	Last Modified: 06/11/2012	*/

//Includes required header files.
#include <stdio.h>

int main(void)
{
//Declaring a char array, and a char.
char word[10];
char c;

//asks user to enter word and takes input with scanf().
printf("Enter a word: ");
scanf("%9s", word);

//asks user to enter character using getchar().
printf("Enter a Character: ");
//Note, this statement will be passed over if there is a
//newline character left in the buffer from scanf() statement above.
c = getchar();
//Starting while loop which will ask the user to assign the char
//using getchar() as long as c equals '\n'
while(c =='\n'){
c = getchar();
}

//This code executes in the absence of the above while loop,
//as the newline character is erroneously picked up from previous
//user input. This statement no longer executes as the while
//loop above solves that error.
if (c == '\n') printf("Warning: char c contains a newline\n");
printf("You entered: word: %s, char: %c\n", word, c);

return 0;
}