/*	Program37.c:	Program to group variables together in a struct...
					V0.1 - based on notes.
	Authors: Patrick Moorehouse
	Last Modified: 10/12/2012
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_user_info {
char name[30];
char phonenumber[20];
char studentnum[20];
};

typedef struct s_user_info user_info;
void input_string(user_info *p);
void output_string(user_info *p);
void write_to_file(user_info *p);
void read_from_file(user_info *p);

int main(void)
{
user_info user;
user_info *p;
p = &user;
char tmp[3];
char op;

printf("Would you like to read user data or write new information?\n");
printf("To read, type r, to write, type w: \n");
fgets(tmp, 3, stdin);
sscanf(tmp, "%c", &op);

if (op == 'r' || op == 'R')
{
read_from_file(p);
}

else if (op == 'w' || op == 'W')
{
input_string(p);
}

else
{
printf("You did not specify a valid option.\n");
}

return 0;
}

void input_string(user_info *p)
{
printf("Enter name: ");
fflush(stdout);
fgets(p->name, 30, stdin);
p->name[strlen(p->name)-1] = '\0';

printf("Enter phone number: ");
fflush(stdout);
fgets(p->phonenumber, 20, stdin);
p->phonenumber[strlen(p->phonenumber)-1] = '\0';

printf("Enter student number: ");
fflush(stdout);
fgets(p->studentnum, 20, stdin);
p->studentnum[strlen(p->studentnum)-1] = '\0';

write_to_file(p);
output_string(p);
}

void output_string(user_info *p)
{
printf("\n=-=-= User details =-=-=\n");
printf("Name: %s\n", p->name);
printf("Phone: %s\n", p->phonenumber);
printf("StudentID: %s\n", p->studentnum);
}

void write_to_file(user_info *p)
{
	FILE *fp1;
	char fname[] = "user_info.txt";
	
	if ( (fp1 = fopen(fname, "a" )) == NULL )
	{
		printf("cannot open file %s for reading\n", fname);
		exit(1);
	}
	
	fprintf(fp1, "%s %s %s %d\n", p->name, p->phonenumber, p->studentnum);
	printf("\nThe following information has been written to disk.\n");
	fclose(fp1);
}

void read_from_file(user_info *p)
{
	FILE *fp1;
	char fname[] = "user_info.txt";
	
	if ( (fp1 = fopen(fname, "r" )) == NULL )
	{
		printf("cannot open file %s for reading\n", fname);
		exit(1);
	}
	
	fscanf(fp1, "%s %s %s", &p->name, &p->phonenumber, &p->studentnum);
	while(!feof(fp1))
	{
	output_string(p);
	fscanf(fp1, "%s %s %s", &p->name, &p->phonenumber, &p->studentnum);	
	}
	
	fclose(fp1);
}