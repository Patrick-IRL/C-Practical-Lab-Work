/*	Program24.c: Program that reverses the words in a sentence
					with a function call.
	Authors: Patrick Moorehouse
	Last Modified: 24/11/2012
	code online http://pastebin.com/22eVCvpq
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap_chars_in_word(char *words, int start_of_word);

int main(void)
{

/* Initialising variables. */
char *sentence; //string (char array)
int i,length;

sentence = (char*)malloc(100);

printf("Enter a sentence:\n"); //asks for sentence
fgets(sentence, 100, stdin); //user inputs sentence

//setting the \n to be a space instead, makes testing conditions
//easier later when looping through "sentence", only need to test
//for space, not for space OR newline.
length = strlen(sentence);
printf("String Length: %d\n", length);
sentence[length-1] = ' ';

for(i = 0; i < length; i++)//continue until end of string is reached
{
//Tests whether current location is the start of a new word.
//First element is assumed to be start of a word, and if the element
//before the current location is a space, then we are at start of new word.
if ((i==0)||(sentence[i-1] == ' '))
{
//If we are at the start of a word, call function to swap chars,
//passing to it as parameters the string "sentence" and the current
//position in "sentence" where the word begins.
swap_chars_in_word(sentence, i);
}

//continues through string doing nothing until a new word begins.
else{
}

}

//Prints out "sentence" with its words reversed.
printf("%s", sentence);

//release memory allocated and set pointer to NULL
free(sentence);
sentence = NULL;
return 0;
}

void swap_chars_in_word(char *words, int start_of_word){
int j;
int p = 0;
int word_length = 0;//used to measure length of each word
char swapped[100];//used to hold the word from main string,
	//only in reverse order. Then its copied back to string.

//loop reads through the word, determining how long it is.
for (j = start_of_word; words[j] != ' '; j++){				
word_length = word_length + 1;
}
printf("length of word = %d\n", word_length);

//stores chars of word into temporary array, but in reverse order
for(j = start_of_word; words[j] != ' ' ; j++){
swapped[j] = words[start_of_word+word_length-1-p];
p++;
}

//copies the reversed word in temp array back into the main string
for(j = start_of_word; words[j] != ' ' ; j++){
words[j] = swapped[j];
}

}//end of swap_chars_in_word




