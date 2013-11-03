/*	Program25.c: Program that counts the use of each letter in a sentence.
	Authors: Patrick Moorehouse
	Last Modified: 20/11/2012
*/

#include <stdio.h>

/* Initialising variables. */

int main(void)
{
/* Initialising variables. */
char sentence[200]; //string (char array)
int i = 0; //used to step through string in loop

//sets an int array of length 26
//to provide a counter for each letter
int letters[26];

//initialises an array of chars, with a char for each
//letter of alphabet. This is used so that the user can identify
//which numbers correspond to which letters when the count results
//are printed later.
char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

printf("Enter a sentence:\n"); //asks for sentence
fgets(sentence, 200, stdin); //user inputs sentence

//loops through all elements of array, initialising counter
//for each letter to 0, before file reading begins, to ensure
//and accurate count.
for (i=0;i<26;i++){
letters[i] = 0;
}

i=0;//resets value of i so it can be reused in while loop.
while(!(sentence[i] == '\0'))//continue until end of string is reached
{
//conditional statements, which increment a counter for each individual
//letter of the alphabet, every time an instance of that character is
//encountered.
if ((sentence[i]=='a')||(sentence[i]=='A')){letters[0]+=1;}
else if ((sentence[i]=='b')||(sentence[i]=='B')){letters[1]+=1;}
else if ((sentence[i]=='c')||(sentence[i]=='C')){letters[2]+=1;}
else if ((sentence[i]=='d')||(sentence[i]=='D')){letters[3]+=1;}
else if ((sentence[i]=='e')||(sentence[i]=='E')){letters[4]+=1;}
else if ((sentence[i]=='f')||(sentence[i]=='F')){letters[5]+=1;}
else if ((sentence[i]=='g')||(sentence[i]=='G')){letters[6]+=1;}
else if ((sentence[i]=='h')||(sentence[i]=='H')){letters[7]+=1;}
else if ((sentence[i]=='i')||(sentence[i]=='I')){letters[8]+=1;}
else if ((sentence[i]=='j')||(sentence[i]=='J')){letters[9]+=1;}
else if ((sentence[i]=='k')||(sentence[i]=='K')){letters[10]+=1;}
else if ((sentence[i]=='l')||(sentence[i]=='L')){letters[11]+=1;}
else if ((sentence[i]=='m')||(sentence[i]=='M')){letters[12]+=1;}
else if ((sentence[i]=='n')||(sentence[i]=='N')){letters[13]+=1;}
else if ((sentence[i]=='o')||(sentence[i]=='O')){letters[14]+=1;}
else if ((sentence[i]=='p')||(sentence[i]=='P')){letters[15]+=1;}
else if ((sentence[i]=='q')||(sentence[i]=='Q')){letters[16]+=1;}
else if ((sentence[i]=='r')||(sentence[i]=='R')){letters[17]+=1;}
else if ((sentence[i]=='s')||(sentence[i]=='S')){letters[18]+=1;}
else if ((sentence[i]=='t')||(sentence[i]=='T')){letters[19]+=1;}
else if ((sentence[i]=='u')||(sentence[i]=='U')){letters[20]+=1;}
else if ((sentence[i]=='v')||(sentence[i]=='V')){letters[21]+=1;}
else if ((sentence[i]=='w')||(sentence[i]=='W')){letters[22]+=1;}
else if ((sentence[i]=='x')||(sentence[i]=='X')){letters[23]+=1;}
else if ((sentence[i]=='y')||(sentence[i]=='Y')){letters[24]+=1;}
else if ((sentence[i]=='z')||(sentence[i]=='Z')){letters[25]+=1;}
else {}
i++;
}//end of while loop


printf("\nThe count of letters present in the string are as follows.\n\n");

//loopd through alphabet, displaying the number of instances
//of each letter in the input string.
for (i=0;i<26;i++){
printf("%c = %d\n",alphabet[i],letters[i]);
}

return 0;
}