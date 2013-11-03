#include <stdio.h>
#include <stdlib.h>

typedef struct sPOINT {
	int x,y;
	struct sPOINT* next;
} point;

point *create_element(void);
point *add_point(point *start);
point *remove_point(point *start);
point *element_at_index(point *e, int index);

void input(point *p);
void display(point *p);
void display_all(point *p);
void write_all_to_file(point *p);
void read_from_file(point *p);

int main(void)
{
	int option;
	point *start=NULL;

	start = add_point_from_file(start);
	
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
	
	write_all_to_file(start);

	return 0;
}

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
	printf("enter values for x and y (e.g. 1 2): ");
	scanf("%d %d", &p->x, &p->y);
	display(p);
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
		
	//int count=0;
	if (p == NULL)
	{
		printf("No elements in the list!\n");
		return;
	}

	printf("\n\nAll points in the list:\n");
	for (; p != NULL; p = p->next)
	{
		fprintf(fp1, "%d %d\n", p->x, p->y);
	}
	printf("\n\n");
	fclose(fp1);
}

point *create_element_from_file(void)
{
	FILE *fp1;
	char fname[] = "user_info.txt";
	
	if ( (fp1 = fopen(fname, "r" )) == NULL )
	{
		printf("cannot open file %s for reading\n", fname);
		exit(1);
	}
	
	point *p = (point*) malloc(sizeof(point));
	p->next=NULL;
	fscanf(fp1, "%d %d", &p->x, &p->y);
	
	fclose(fp1);
	return p;
}

point* add_point_from_file(point *start)
{
	point *last;
	point *n = create_element_from_file();

	//input(n);
	
	//Add n to the end of the list
	if (start != NULL) 
	{
		for (last = start; last->next != NULL; last = last->next);
		last->next = n;
	}
	else start=n; //this element is the new start

	return start;
}