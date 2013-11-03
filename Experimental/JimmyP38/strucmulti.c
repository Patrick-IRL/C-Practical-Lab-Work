/* Strucmulti.c enter more than one student record, based on program 
* Author: Jimmy Loughran
* Last Modified: 23/Dec/2012
***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** Fill in struct **/

typedef struct sPerson { // Defines a struct as its own variable type

	int studentNo;
	char name[20]; // The variables within this struct
	char phone[15];

} Person; // The name of the new type

/** Function Prototype **/

void InputStudent (Person *MyPointer); // Will be used to input data in a struct

void read(FILE *fp); // Will be used to dislpay contents of a struct Person entry

void write(Person *MyPointer);

FILE *fp; 

/** Main **/

int main(void)
{
	
	Person a[100]; // Struct Person, record a
	
	
	char filename[40];
	char choice;
	int arraycount;
	
	printf("Type r to read or w to write: ");		/* prompt user for filename */
	choice = getchar();
	
	if (choice == 'r')
	
		{ 
		
			fp = fopen( "file.txt", "r"); // Open file for reading
			while ( fp  ==  NULL)				/* check if file opened correctly & if not prompt for another 			filename */
			{
				printf("Cannot open %s for reading \n", filename );
				printf("\n\nEnter filename :" );
				fgets( filename, 40, stdin );
				filename[strlen(filename)-1] = '\0';
				fp = fopen (filename, "r") ;
			}
			
		read(fp); // reads the output

		
		}
		
	if (choice == 'w')
		
		{
		
		InputStudent(&a[0]); // Pass the entire struct definition on to the function by memory address
		
		printf("Do you want to enter another record?");	
		
		scanf("%c", &choice);
	
		if (choice == 'y')

		
		 {
		
		 
			arraycount++;
			printf("Enter name: ");
			scanf("%19s", a[arraycount].name); // Enters the values passed by the pointer
	
			printf("Enter phone: ");
			scanf("%14s", a[arraycount].phone);
	
			printf("Enter student number: ");
			scanf("%d", &a[arraycount].studentNo);	
			
			 
		 }	
			
		}
		
		

	
	
	fclose(fp);


	return 0;

}

/** Function Method **/


void InputStudent (Person *MyPointer)
{
	
	
	printf("Enter name: ");
	scanf("%19s", MyPointer->name); // Enters the values passed by the pointer
	
	printf("Enter phone: ");
	scanf("%14s", MyPointer->phone);
	
	printf("Enter student number: ");
	scanf("%d", &MyPointer->studentNo);	
	
	write(MyPointer);
	


}

void read(FILE *fp)
{        

	 int c;
     while (c != EOF)
	
			{
			
				putchar( c ) ;
				c = getc( fp );
					
	
			}
			
	printf("\n");

}

void write(Person *MyPointer)
{
	char filename[40];
	fp = fopen( "file.txt", "w"); // Open file for reading
			while ( fp  ==  NULL)				/* check if file opened correctly & if not prompt for another 			filename */
			{
				printf("Cannot open %s for reading \n", filename );
				printf("\n\nEnter filename :" );
				fgets( filename, 40, stdin );
				filename[strlen(filename)-1] = '\0';
				fp = fopen (filename, "r") ;
			}

	fprintf(fp, "%s \n", MyPointer->name);
	fprintf(fp, "%s \n", MyPointer->phone);
	fprintf(fp, "%d \n", MyPointer->studentNo);
	

}