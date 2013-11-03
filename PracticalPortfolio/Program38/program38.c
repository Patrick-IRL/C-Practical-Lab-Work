/*	Program38.c:	Program to group variables together in a struct
					with functions for reading data from file into struct,
					saving data in struct to file, allowing user to input
					info into struct, and a function to print struct data
					to screen.
					Handles multiple users via array of structs.
	Authors: Patrick Moorehouse
	Last Modified: 20/12/2012
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//creates a structure with a number of char arrays as its contents
struct s_user_info {
char name[30];
char phonenumber[20];
char studentnum[20];
};

//typedef is used to rename the type, so that one can type user_info
//in their code rather than typing struct s_user_info user_info
typedef struct s_user_info user_info;

//function which handles user data entry
//The op parameter allows the function to call
//the write, or append function, depending on the users desires.
void input_string(char *op, user_info *p);
//Function for creating a new file, overwriting the old, with new
//data submitted by the user.
void write_to_file(user_info *p);
//Function that appends the data submitted by the user to the end of
//the existing file, keeping existing data intact.
void append_to_file(user_info *p);
//Function to display the contents of the currently selected
//element of the struct array.
void output_string(user_info *p);
//Function that reads all user data from the file and inserts each
//into its own stuct array element.
void read_from_file(FILE *fp1, user_info *p);

//function will count how many user data entries there are in the file
int data_count();

int main(void)
{

//retrieves the number if data entries in the file
int i = data_count();
int j;
FILE *fp1;
char fname[] = "user_info.txt";
	
//declares an array of srtucts, with number of elements
//equal to number data entries in the file,
//so an element in the array for each data entry
user_info users[i];
user_info *p; //declares pointer to struct of type user_info
p = &users[0]; //sets address of pointer to the first element of struct array

char tmp[3];//temp array used to read in user choices
char op;//char which user choice is processed and inserted into

//Asks user to enter their choice on what operation to perform.
printf("Would you like to read user data or write new information?\n");
printf("r - read data from file.\n");
printf("w - write new data to a new file, overwriting existing file.\n");
printf("a - write new data and append to current file.\n");
//using fgets() to read in choice and sscanf() to process and insert into "op"
fgets(tmp, 3, stdin);
sscanf(tmp, "%c", &op);


//if user wishes to read from file...
if (op == 'r' || op == 'R')
{
FILE *fp1;
char fname[] = "user_info.txt";
	
if ( (fp1 = fopen(fname, "r" )) == NULL )
{
	printf("cannot open file %s for reading\n", fname);
	exit(1);
}

//Number of data entries was counted at the beginning of the program.
//Loops through file, transferring each data entry into its own struct.
for(j=0;j<i;j++)
{
	//sets address of pointer to the address of current array element
	p = &users[j];
	//reads data from the file into the struct array element
	read_from_file(fp1, p);
}

fclose(fp1);
}//end of reading from file if condition


//If user wishes to write to file...
else if (op == 'a' || op == 'A' || op == 'w' || op == 'W')
{
//calls input function, passing the type of write operation
//to be performed as well as the struct
input_string(&op, p);
}

//if user enters wrong choice
else
{
printf("You did not specify a valid option.\n");
}

return 0;
}

//function for user to input data into struct

void input_string(char *op, user_info *p)
{
//read and process user input
printf("Enter name: ");
fflush(stdout);
fgets(p->name, 30, stdin);
//sets last char of input to be end string char
p->name[strlen(p->name)-1] = '\0';

//read and process user input
printf("Enter phone number: ");
fflush(stdout);
fgets(p->phonenumber, 20, stdin);
//sets last char of input to be end string char
p->phonenumber[strlen(p->phonenumber)-1] = '\0';

//read and process user input
printf("Enter student number: ");
fflush(stdout);
fgets(p->studentnum, 20, stdin);
//sets last char of input to be end string char
p->studentnum[strlen(p->studentnum)-1] = '\0';

//if user wishes to write new file
if(*op == 'w')
{
//calls function to write new file, overwriting existing file
write_to_file(p);
}

//if user wishes to append data to end of file
else if(*op == 'a')
{
//calls function to append data to end of existing file,
//keeping existing data intact.
append_to_file(p);
}

//prints current struct data to screen
output_string(p);
}//end input function

void output_string(user_info *p)
{
printf("\n=-=-= User details =-=-=\n");
printf("Name: %s\n", p->name);
printf("Phone: %s\n", p->phonenumber);
printf("StudentID: %s\n", p->studentnum);
}

//Function writes a new file to hold new data
void write_to_file(user_info *p)
{
	FILE *fp1;
	char fname[] = "user_info.txt";
	
	if ( (fp1 = fopen(fname, "w" )) == NULL )
	{
		printf("cannot open file %s for reading\n", fname);
		exit(1);
	}
	
	fprintf(fp1, "%s %s %s\n", p->name, p->phonenumber, p->studentnum);
	printf("\nThe following information has been written to disk.\n");
	fclose(fp1);
}

//function opens existing file and append new data to the end of it.
void append_to_file(user_info *p)
{
	FILE *fp1;
	char fname[] = "user_info.txt";
	
	if ( (fp1 = fopen(fname, "a" )) == NULL )
	{
		printf("cannot open file %s for reading\n", fname);
		exit(1);
	}
	
	fprintf(fp1, "%s %s %s\n", p->name, p->phonenumber, p->studentnum);
	printf("\nThe following information has been written to disk.\n");
	fclose(fp1);
}

//Function that reads data from the file and transfers to
//cerrently selected element of the array of structs.
void read_from_file(FILE *fp1, user_info *p)
{
	fscanf(fp1, "%s %s %s", &p->name, &p->phonenumber, &p->studentnum);
	output_string(p);
}

int data_count() //function to count the amount of data contained in a file
{
	int data_count = 0;	//sets counter to 0 before any data has been read
	FILE *fp1;
	char fname[] = "user_info.txt";
	user_info user;
	user_info *p;//declares pointer to struct of type user_info
	p = &user;//sets pointer to point to address of struct user.
	//checking that file has opened correctly
	if ( (fp1 = fopen(fname, "r" )) == NULL )
	{
		printf("cannot open file %s for reading\n", fname);
		exit(1);
	}

	//this loop reads a data entry, and for each entry read, adds
	//to counter, up until the end of the file has been reached.
	//This serves dual purpose of reading the data from file,
	//while counting it at the same time
	while(fscanf(fp1, "%s %s %s", &p->name, &p->phonenumber, &p->studentnum) != EOF)
	{
		data_count++;
	}
	
	fclose(fp1);//close file
	return data_count;//return the amount of data entries in the file
}