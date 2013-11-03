/*	Program39.c:	Program to group variables together in a struct.
					Creates a linked list of structs.
					Allows user to list all elements of list, add new
					elements, and delete existing elements.
					
					List is loaded from file on startup, and saved to file
					on close. So list is kept persistent.
	Authors: Patrick Moorehouse
			 Rob Quigly(Provided linked lists example to work from)
	Last Modified: 24/12/2012
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//creates a structure with a number of char arrays as its contents
//uses typedef to simplify typing of code later.
typedef struct sPOINT {
	char name[30];
	char phonenumber[20];
	char studentnum[20];
	struct sPOINT* next;//this pointer will be used for list
} point;				//to point to next element

point *create_element(void);//create node for new element
point *add_point(point *start);//adding new element
point *remove_point(point *start);//deletes a node
point *element_at_index(point *e, int index);
point *read_data_from_file(point *start);//reads the list from file
//adds each element from file to a new node in list
point *add_point_file(point *start, FILE *fp1);

void input(point *p);//allows user to enter new entries
void display(point *p);//displays a node
void display_all(point *p);//displays all nodes in the list
void write_all_to_file(point *p);//writes the whole list to file
void read_from_file(point *p);//reads from file
int data_count ();//function to count number of data entries in file.
void inputfromfile(point *p, FILE *fp1);	//function to read in from the file to the stuct


int main(void)
{
	int i;
	char tmp[3];
	char option;
	point *start=NULL;
	
	//reads all data from file to initialise and populate
	//the list of nodes
	start = read_data_from_file(start);
	
	
	do
	{
		//Display user menu
		printf("\n0 - quit\n");
		printf("1 - add\n");
		printf("2 - remove\n");
		printf("3 - display all\n");
		printf("Enter option: ");
		fflush(stdout);

		fgets(tmp, 3, stdin);
		sscanf(tmp, "%c", &option);
		
		//Process option
		if(option == '1')
		{
			start = add_point(start);//add new entry
		}
		else if(option == '2')
		{
		start = remove_point(start);//delete an entry
		}
		else if(option == '3')
		{
		display_all(start);//list all entries
		}
		else{
		printf("You have entered an invalid option.\n");
		}
		
	}while (option != '0');
	
	//writes list to file before program closes to maintain persistence
	write_all_to_file(start);

	return 0;
}

//This function just allocates a single element, and initialises its values
point *create_element(void)
{
	point *p = (point*) malloc(sizeof(point));
	p->next=NULL;
	p->name[0] = '\0';
	p->phonenumber[0] = '\0';
	p->studentnum[0] = '\0';
	return p;
}

//Adds a new point to the array. start may be NULL.
point* add_point(point *start)
{
	point *last;
	point *n = create_element();

	input(n);
	
	//Add n to the end of the list
	if (start != NULL) 
	{
		for (last = start; last->next != NULL; last = last->next);
		last->next = n;
	}
	else start=n; //this element is the new start

	return start;
}

//return a pointer to the element at the specified index
point *element_at_index(point *e, int index)
{
	for (; index > 0 && e != NULL; index--, e=e->next);
	return e;
}

point *remove_point(point *start)
{
	point *rem, *previous;
	int index,count;

	if (start == NULL)
	{
		printf("No elements to remove\n");
		return start;
	}

	printf("Which element index do you want to remove? (starting from 0)\n");
	scanf("%9d", &index);
	fflush(stdin);

	//The first element is a special case as the 2nd element will become the start
	if (index == 0)
	{
		point *next = start->next;
		free(start);
		return next;
	}
	
	//find the element to remove and the previous element
	rem = element_at_index(start, index);
	previous = element_at_index(start, index-1);

	if (rem == NULL)
	{
		printf("Invalid index: %d\n", index);
		return start;
	}

	//set the previous element to point to the one after the
	//one being removed
	previous->next = rem->next;

	free(rem);
	return start;
}

//input values into element
void input(point *p)
{
	//read and process user input
	printf("\nEnter name: ");
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
	printf("\n");
	display(p);
}

//display a single element
void display(point *p)
{
	printf("=-=-= User details =-=-=\n");
	printf("Name: %s\n", p->name);
	printf("Phone: %s\n", p->phonenumber);
	printf("StudentID: %s\n\n", p->studentnum);
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

	printf("\n\nAll data entries in the list:\n\n");
	for (; p != NULL; p = p->next)
	{
		printf("%d: Element\n", count++);
		display(p);
	}
	printf("\n");
}

//write all elements to file
void write_all_to_file(point *p)
{
	FILE *fp1;
	char fname[] = "user_info.txt";
	
	if ( (fp1 = fopen(fname, "w" )) == NULL )
	{
		printf("cannot open file %s for reading\n", fname);
		exit(1);
	}
		
	if (p == NULL)
	{
		printf("No elements in the list!\n\n");
		return;
	}

	printf("\n\nData has been written to file.\n");
	for (; p != NULL; p = p->next)
	{
		fprintf(fp1, "%s %s %s\n", p->name, p->phonenumber, p->studentnum);
	}
	printf("\n");
	fclose(fp1);
}

point* read_data_from_file(point *start)  //function to count the data in a file and to transfer it to the linked list
{
	int datacount;		//initialise count variable
	int i = 0;			//intialise loop counter
	
	datacount = data_count();		//run function to count the amount of data entries, return that value to the variable datacount
	FILE *fp1;
	char fname[] = "user_info.txt";
	
	if ( (fp1 = fopen(fname, "r" )) == NULL )
	{
		printf("cannot open file %s for reading\n", fname);
		exit(1);
	}
	
	while (i < datacount)			//loop to create the same amount of elements in the linked list as there are in the file
	{
		start = add_point_file(start, fp1);		//function to create elements in the linked list and read in the data from a file
		i++;									//increase loop counter
	}
	fclose(fp1);			//close file
	return start;			//return the first element in the list
}

int data_count () 			//function to count the amount of data contained in a file
{
	int line = 0;			//intialise vaiable of type int to be used in counting the amount of data within the file
	char c;					//character variable, used in reading characters from file
	FILE *fp1;
	char fname[] = "user_info.txt";
	
	if ( (fp1 = fopen(fname, "r" )) == NULL )
	{
		printf("cannot open file %s for reading\n", fname);
		exit(1);
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
	return line;		//return the amount of data entries in the file
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

void inputfromfile(point *p, FILE *fp1)			//function to read data from file
{
	fscanf(fp1,"%s %s %s\n", &p->name, &p->phonenumber, &p->studentnum);
}
