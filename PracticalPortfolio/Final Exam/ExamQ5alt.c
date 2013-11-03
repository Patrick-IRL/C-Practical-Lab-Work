#include <stdio.h>
#include <stdlib.h>

struct s_user_info {
char fname[100];
char lname[100];
char phone[100];
};

typedef struct s_user_info user_info;

//point *create_element(void);
//point *add_point(point *start);
//point *read_data_from_file(point *start);
//point *add_point_file(point *start, FILE *fp1);

//void display(point *p);
//void display_all(point *p);
//void read_from_file(point *p);
int data_count ();
//void inputfromfile(point *p, FILE *fp1);	//function to read in from the file to the stuct


int main(void)
{
	user_info user;
	user_info *p;
	p = &user;
	int option, i;
	
	
	printf("%d\n", data_count());
	//start = read_data_from_file(start);
	
	/*
	do
	{
		//Display user menu
		printf("0 - quit\n");
		printf("1 - add\n");
		printf("2 - remove\n");
		printf("3 - display all\n");
		printf("Enter option: ");
		fflush(stdout);

		scanf("%2d", &option);

		//Process option
		switch (option)
		{
			case 1: start = add_point(start);
				break;
			case 2: start = remove_point(start);
				break;
			case 3: display_all(start);
				break;
		}
	}while (option != 0);
	*/
	//write_all_to_file(start);

	return 0;
}
/*
//This function just allocates a single element, and initialises its values
point *create_element(void)
{
	point *p = (point*) malloc(sizeof(point));
	p->next=NULL;
	p->x = 0;
	p->y = 0;
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



//display a single element
void display(point *p)
{
	printf("x: %d, y: %d\n", p->x, p->y);
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

	printf("\n\nAll points in the list:\n");
	for (; p != NULL; p = p->next)
	{
		printf("%d: ", count++);
		display(p);
	}
	printf("\n\n");
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
*/
int data_count () 			//function to count the amount of data contained in a file
{
	int data_count = 0;			//intialise vaiable of type int to be used in counting the amount of data within the file
	char c;					//character variable, used in reading characters from file
	FILE *fp1;
	char fname[] = "input.txt";
	user_info user;
	user_info *p;
	p = &user;
	
	if ( (fp1 = fopen(fname, "r" )) == NULL )
	{
		printf("cannot open file %s for reading\n", fname);
		exit(1);
	}

	fscanf(fp1, "%s %s\n%s", &p->fname, &p->lname, &p->phone);
	while(!feof(fp1))
	{
		data_count++;
		fscanf(fp1, "%s %s %s", &p->fname, &p->lname, &p->phone);	
	}
	
	fclose(fp1);		//close file
	return data_count;		//return the amount of data entries in the file
}
/*
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
	fscanf(fp1,"%d %d", &p->x, &p->y);
}
*/