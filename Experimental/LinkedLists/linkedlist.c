/*		Program 39 - linkedlist.c 
* Program that uses linked lists to store students data.
* The data can be read from and written to a file.
* Author: Daniel Sinnott
* Last Modified: 16/12/12
*****/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sPOINT {									//initialise and create struct. Typedef used to rename stuct sPoint to point
	char firstname[100], surname[100], phonenumber[100], studentnumber[100];			//character arrays within the struct
	struct sPOINT* next;								//pointer to next struct in the linked list
} point;

//initialise all functions used
int data_count ();						//function to count the amount of data contained in a file
char *filenotfound (char *filename);	//function to enter a filename if the supplied file is not found
point *add_point_file(point *start, FILE *fp1);	//function to create stucts in the linked list and read in the data from a file
point *create_element(void);				//function to create an element in the list
void inputfromfile(point *p, FILE *fp1);	//function to read in from the file to the stuct
void display(point *p);						//finction to display an element in the list
void display_all(point *p);					//function to display all elements in the list
point* add_point(point *start);			//add an element to the list (not from file)
void input(point *p);					//read input from user into an element in the struct
point* read_data_from_file(point *start);	//function to count the data in a file and to transfer it to the linked list

int main (void)
{
	point *start = NULL;				//create first element in linked list
	char option;						//character variable to used by user to select option
	
	start = read_data_from_file(start);		//check file to see if it contains data, read each entry into a new element in the linked list
	
	while(option != 'Q'||option != 'q')		//run until user decides to quit
	{
		//Print user menu
		printf("\nA or a - Add Student\n");
		printf("S or s - Show all Students\n");
		printf("Q or q - Quit\n\n");
		printf("Enter option: ");
		fflush(stdout);

		option = getchar();			//get option from user
		while(option == '\n')		//prevents '\n' from preventing program from reading user input
		{
			option = getchar();
		}
		
		//Process option
		if (option == 'A'||option == 'a')		//add new point to linked list and enter data
		{	
			start = add_point(start);
		}
		else if (option == 'S'||option == 's')		//display all points contained within the linked list
		{
			display_all(start);
		}
		else if (option == 'Q'||option == 'q')		//quit the program
		{
			break;
		}
		else		//if input not an available option, asks user to select again
		{
			printf("\n\n%c is not an available option, please select again\n\n");
		}
	}
	return 0;
}

int data_count () 			//function to count the amount of data contained in a file
{
	FILE *fp1;				//initialise file point
	int line = 0;			//intialise vaiable of type int to be used in counting the amount of data within the file
	char c;					//character variable, used in reading characters from file
	char *filename;			//variable to hold the name of the file if "studentlist.txt" is not found
	filename = (char*)malloc(30);		//give memory for 30 characters to filename
	strcpy(filename, "studentslist.txt");		//copies studentlist.txt to the filename vatiable
	
	fp1 = fopen(filename, "r");			//opens file for reading
	if (fp1 == NULL)					//if file not found
	{
		filename = filenotfound(filename);		//run function that allows user to input a filename, let that input be the variable filename
		fp1 = fopen(filename, "r");				//open file for reading using the variable filename
	}
	c = getc(fp1);		//read character from file
	while (c != EOF)		//read until reaches the end of the file
	{
		if (c == '\n')		//count of how many data entries are in the file and how many elements in the list will have to be created
		{
			line++;
		}
		c = getc(fp1);
	}
	fclose(fp1);		//close file
	free(filename);		//release memory
	return line;		//return the amount of data entries in the file
}

char *filenotfound (char *filename) 		//function that allows user to enter the name of the file to be read
{
	printf("The file '%s' is not found",filename);
	printf("please enter a filename: ");
	fgets(filename, 30, stdin);
	filename[strlen(filename)-1] = '\0';			//removal of '/n' from the filename
	return filename;								//return the name of the file
}

point* add_point_file(point *start, FILE *fp1)		//creation of a point in the list to be populated by each entry in the file
{
	point *last;
	point *n = create_element();

	inputfromfile(n, fp1);						//read data from file and put into the linked list
	
	//Add n to the end of the list
	if (start != NULL) 			//making the final elements pointer NULL
	{
		for (last = start; last->next != NULL; last = last->next);
		last->next = n;
	}
	else start=n; //this element is the new start

	return start;		//return first element of the linked list
}

point *create_element(void)			//function to create an element
{
	point *p = (point*) malloc(sizeof(point));		//allocate memory for the linked list
	p->firstname;
	p->surname;
	p->phonenumber;
	p->studentnumber;
	p->next=NULL;
	return p;
}

void inputfromfile(point *p, FILE *fp1)			//function to read data from file
{
	fscanf(fp1,"%s %s %s %s", &p->firstname, &p->surname, &p->phonenumber, &p->studentnumber);
}

//display a single element
void display(point *p)
{
	printf("Name: %s %s\nPhonenumber: %s \nStudentnumber: %s \n\n", p->firstname, p->surname, p->phonenumber, p->studentnumber);
}

//display all elements
void display_all(point *p)
{
	int count=0;
	if (p == NULL)
	{
		printf("No elements in the list!\n");
		return;
	}

	printf("\n\nAll points in the list:\n\n");
	for (; p != NULL; p = p->next)
	{
		printf("%d:\n", count++);
		display(p);
	}
	printf("\n\n");
}

point* add_point(point *start)		//function to add a element to the linked which is to be populated by the user, and writes that input to the file
{
	point *last;
	point *n = create_element();

	input(n);					//populate element using user input
	
	//Add n to the end of the list
	if (start != NULL) 
	{
		for (last = start; last->next != NULL; last = last->next);
		last->next = n;
	}
	else start=n; //this element is the new start

	return start;
}

void input(point *p)			//function to read user input, populate the stuct with that info and also write the info to file
{
	printf("\nEnter firstname, surname, phonenumber and studentnumber (e.g. Daniel Sinnott 0877914732 08375810): ");
	scanf("%s %s %s %s", &p->firstname, &p->surname, &p->phonenumber, &p->studentnumber);   //scan in user input
	display(p);
	
	FILE *fp1;
	char *filename;
	filename = (char*)malloc(30);
	strcpy(filename, "studentslist.txt");
	
	fp1 = fopen(filename, "a");			//open file for appending
	if (fp1 == NULL)
	{
		filename = filenotfound(filename); //if file not found, run function
		fp1 = fopen(filename, "a");
	}
	fprintf(fp1, "%s %s %s %s\n", &p->firstname, &p->surname, &p->phonenumber, &p->studentnumber);  //write data to file
}

point* read_data_from_file(point *start)  //function to count the data in a file and to transfer it to the linked list
{
	int datacount;		//initialise count variable
	int i = 0;			//intialise loop counter
	
	datacount = data_count();		//run function to count the amount of data entries, return that value to the variable datacount
	FILE *fp1;
	char *filename;
	filename = (char*)malloc(30);
	strcpy(filename, "studentslist.txt");
	
	fp1 = fopen(filename, "r");		//open file for reading
	if (fp1 == NULL)
	{
		filename = filenotfound(filename);
		fp1 = fopen(filename, "r");
	}
	
	while (i < datacount)			//loop to create the same amount of elements in the linked list as there are in the file
	{
		start = add_point_file(start, fp1);		//function to create elements in the linked list and read in the data from a file
		i++;									//increase loop counter
	}
	fclose(fp1);			//close file
	return start;			//return the first element in the list
}
	