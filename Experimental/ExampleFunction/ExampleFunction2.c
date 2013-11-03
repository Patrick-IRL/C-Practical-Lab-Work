#include <stdio.h>

void add_and_display(int a, int b);
int input_number(void);
int check_number_is_within_range(int number, int start, int end);

int main(void)
{
	int i,j;

	i = input_number();
	j = input_number();
	add_and_display(i,j);

	return 0;
}

void add_and_display(int a, int b)
{
	int c = a + b;
	printf("%d + %d = %d\n", a, b, c);
}

int input_number(void)
{
	int user_input;

	do
	{
		printf("please enter a number between 0-9:\n");
		scanf("%9d", &user_input);
	} while ( check_number_is_within_range(user_input, 0, 9) 

== 0 );
	return user_input;
}

int check_number_is_within_range(int number, int start, int end)
{
	if (!((number >= start) && (number <= end)))
	{
		printf("%d is not within the range %d-%d\n", 

number, start, end);
		return 0;
	}
	return 1;
}

