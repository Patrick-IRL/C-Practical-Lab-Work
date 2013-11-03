/*	Program37.c:	Program to group variables together in a struct
					with functions for reading data from file into struct,
					saving data in struct to file, allowing user to input
					info into struct, and a function to print struct data
					to screen.
	Authors: Patrick Moorehouse
	Last Modified: 17/12/2012
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

//Declaring functions to perform tasks with struct.
//All functions take a pointer to a struct as parameter, enabling them
//to alter the struct data.

//takes input from user and inserts into a struct
void input_string(user_info *p);
//prints the current values of struct data to screen
void output_string(user_info *p);
//writes the current values of struct data to file
void write_to_file(user_info *p);
//reads data values from file and inserts into struct
void read_from_file(user_info *p);

int main(void)
{
user_info user; //declare struct "user" of type "user_info"
user_info *p; //pointer to struct of type "user_info"
p = &user; //sets pointer to point to addres of delared struct.
char tmp[3]; //temp array used to read in user choices
char op; //char which user choice is processed and inserted into

printf("Would you like to read user data or write new information?\n");
printf("To read, type r, to write, type w: \n");
//using fgets() to read in choice and sscanf() to process and insert into "op"
fgets(tmp, 3, stdin);
sscanf(tmp, "%c", &op);

//if user wishes to read from file...
if (op == 'r' || op == 'R')
{
//call function to read data from file and insert into struct
read_from_file(p);
//call function to display the information that was inserted into struct
output_string(p);
}

//if user wishes to write new info
else if (op == 'w' || op == 'W')
{
//calls function to read in info from user and assign it to the struct
//NOTE: within input_string the write function is called to save to file
input_string(p);
}

//Accounts for users entering wrong operator type
else
{
printf("You did not specify a valid option.\n");
}

return 0;
}

//function for user to input data into struct
void input_string(user_info *p)
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

//after user has input the data, write function and output functions
//are called, to write to file and to then display what was written.
write_to_file(p);
output_string(p);
}

//function to print contents of struct to screen
void output_string(user_info *p)
{
printf("\n=-=-= User details =-=-=\n");
printf("Name: %s\n", p->name);
printf("Phone: %s\n", p->phonenumber);
printf("StudentID: %s\n", p->studentnum);
}

//Function that writes the contents of struct to file.
void write_to_file(user_info *p)
{
	FILE *fp1;
	char fname[] = "user_info.txt";
	
	if ( (fp1 = fopen(fname, "w" )) == NULL )
	{
		printf("cannot open file %s for reading\n", fname);
		exit(1);
	}
	
	//fprintf prints values into the file.
	fprintf(fp1, "%s %s %s %d", p->name, p->phonenumber, p->studentnum);
	printf("\nThe following information has been written to disk.\n");
	fclose(fp1);
}

//function to read data from file and transfer it into the struct.
void read_from_file(user_info *p)
{
	FILE *fp1;
	char fname[] = "user_info.txt";
	
	if ( (fp1 = fopen(fname, "r" )) == NULL )
	{
		printf("cannot open file %s for reading\n", fname);
		exit(1);
	}
	
	//fscanf reads file info and transfers info into struct.
	fscanf(fp1, "%s %s %s %d", &p->name, &p->phonenumber, &p->studentnum);
	fclose(fp1);
}