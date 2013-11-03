/*	filename.c:		Program description.
	Authors: Patrick Moorehouse
	Last Modified: 21/12/2012
*/

//including required headers.
#include <stdio.h>
#include <stdlib.h>

//declaring a struct which will contain a first name,
//a last name, and a phone number for each user.
struct s_user_info {
char fname[100];
char lname[100];
char phone[100];
};
//using typedef to set the name "user_info" for the type
//"struct s_user_info", as it saves writing full name each time.
typedef struct s_user_info user_info;

//declaring function to read the user info from a file
void read_from_file(FILE *fp1, user_info *p);
//function will count how many user data entries there are in the file
int data_count();


int main(void)
{
	//retrieves the number if data entries in the file
	int i = data_count();
	int j;
	
	//declares an array of srtucts, with number of elements
	//equal to number data entries in the file,
	//so an element in the array for each data entry
	user_info users[i];
	user_info *p; //declares pointer to struct of type user_info
	p = &users[0]; //sets address of pointer to the first element of struct array
	
	FILE *fp1; //declares file pointer
	char fname[] = "input.txt";//sets filename
	//checking that file has opened correctly
	if ( (fp1 = fopen(fname, "r" )) == NULL )
	{
		printf("cannot open file %s for reading\n", fname);
		exit(1);
	}
	
	printf("\n\n1: Displaying contents of %s.\n\n", fname);
	
	//starting a loop at 0, and looping for a number of iterations equal
	//to number of elements in the struct array
	for(j=0;j<i;j++)
	{
	//sets address of pointer to the address of current array element
	p = &users[j];
	//reads data from the file into the struct array element
	read_from_file(fp1, p);
	}
	
	
	//This wasnt asked for in the question but I justs felt that
	//running a loop which displayed each element of the struct
	//array would demonstrate that each piece of data has
	//successfully been assigned to a separate struct,
	//or element of a struct array.
	for(j=0;j<i;j++)
	{
	printf("%s %s\n%s\n", users[j].fname, users[j].lname, users[j].phone);
	}
	
	//important to always close files.
	fclose(fp1);
	return 0;
}

void read_from_file(FILE *fp1, user_info *p)
{
	//Taking data from file and storing it at the memory address
	//of the relevant variable within the struct
	fscanf(fp1, "%s %s\n%s\n", &p->fname, &p->lname, &p->phone);
}

int data_count() //function to count the amount of data contained in a file
{
	int data_count = 0;	//sets counter to 0 before any data has been read
	FILE *fp1;
	char fname[] = "input.txt";
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
	while(fscanf(fp1, "%s %s\n%s\n", &p->fname, &p->lname, &p->phone) != EOF)
	{
		data_count++;
	}
	
	fclose(fp1);//close file
	return data_count;//return the amount of data entries in the file
}

