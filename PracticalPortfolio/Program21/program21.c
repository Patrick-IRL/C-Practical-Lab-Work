/*	Program21.c: Program that reverses the words in a sentece,
				but keeps words in the same position in the sentence.
				Example: Hello World -> olleH dlroW
	Authors: Patrick Moorehouse
	Last Modified: 12/11/2012
*/

#include <stdio.h>

int main(void)
{
/* Initialising variables. */
char sentence[200]; //string (char array)
int i = 0; //used to step through string in while loop
char word[20]; //used to hold a word which is to be reversed.
int j = 0; //keeps track of position in word[]
int pos = 0; //keeps track of the starting position of a word in
			 //sentence[], initialised to 0 for first word.
int k = 0;

printf("Enter a sentence:\n"); //asks for sentence
fgets(sentence, 200, stdin); //user inputs sentence

while(!(sentence[i] == '\0'))//continue until end of string is reached
{

//if not a space or newline, this code is executed.
if (!((sentence[i] == ' ')||(sentence[i] =='\n')))
{
//puts current char of sentence into word corresponding position in word
//one character at a time.
word[j] = sentence[i];
j++;	//increments both j and i to next step
i++;
}


else //at a space or a newline, triggers reversal loop
{
//sets k equal to start position of word, loops up until the current
//position in the main loop, which is where the word ends.
for (k = pos; k<i; k++){
//as j remembers position in word[], setting sentence[k] equal to
//word[j-1] sets first letter in current word in sentence[] equal to the
//last letter in word[]. as k increases, and j decreases, the letters of
//word[] are copied back one at a time into sentence, starting with the
//last and iterating backwards until the first letter of word[] has been
//placed back into sentence[].
sentence[k] = word[j-1];
j--; //decrementing j in order to work backwards through word[].
}//end of reversal loop.

j = 0;//return to 0 start again for the next word in sentence[]
i++;//even for space or newline, must increment to read next char
pos = i;
}

}//end of while loop

//prints out the string when all words have been reversed.
printf("%s", sentence);
return 0;
}

/*
A visual aid to help demonstrate the procedure occurring in the program

First as we pass through main string, sentence[], each of its chars is
passed to temporary array word[], one char at a time.

Note, here _ is used as a space character.

sentence[i]
0 1 2 3 4 5
h e l l o _
|
V
h
0 1 2 3 4 5
word[j]

i++, j++

sentence[i]
0 1 2 3 4 5
h e l l o _
| |
V V
h e
0 1 2 3 4 5
word[j]

i++, j++

sentence[i]
0 1 2 3 4 5
h e l l o _
| | | 
V V V
h e l
0 1 2 3 4 5
word[j]

i++, j++

sentence[i]
0 1 2 3 4 5
h e l l o _
| | | |
V V V V
h e l l
0 1 2 3 4 5
word[j]

i++, j++

sentence[i]
0 1 2 3 4 5
h e l l o _
| | | | | 
V V V V V
h e l l o
0 1 2 3 4 5
word[j]

i++, j++

sentence[i]
0 1 2 3 4 5
h e l l o _
main string now holds a space at index sentence[5].
This triggers the reversal loop.
Begins copying the letters from word[] back into
sentence[] in reverse order.

word[j-1]
0 1 2 3 4 5
h e l l o
       /
      /
     /
    /
   /
  /
 /
V
o e l l o
0 1 2 3 4 5
sentence[k]

j--
k++

word[j-1]
0 1 2 3 4 5
h e l l o
     /
    /
   /
  V
0 l l l o
0 1 2 3 4 5
sentence[k]

j--
k++

word[j-1]
0 1 2 3 4 5
h e l l o
    |
	|
    V
o l l l o
0 1 2 3 4 5
sentence[k]

j--
k++

word[j-1]
0 1 2 3 4 5
h e l l o
   \
    \
     \
      V
o l l e o
0 1 2 3 4 5
sentence[k]

j--
k++

word[j-1]
0 1 2 3 4 5
h e l l o
 \
  \
   \
    \
     \
      \
       \
        V
o l l e h
0 1 2 3 4 5
sentence[k]

the word "hello" has now been copied back into
sentence[] in reverse order, "olleh"

This process is repeated for each word in sentence[]
until all words are reversed, but maintain their original
position in the string.

*/