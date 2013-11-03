/*	Program to display the airthmetic functionality of the main operators
	as completd in a standard 'C' program.
		Developer Name : ________________	Date : __________
		Version Number : V1.00			Comment : Initial Program
*/
#include <stdio.h>
 
int main()
{
   //specify the integer variables
   int first, second, add, subtract, multiply;
   float divide;
 
   //prompt the user to enter enter 2 integers
   printf("Enter two integers\n");
   //assign the integers to the variables first & second
   scanf("%d%d", &first, &second);
 
   //compete the arithmetic operations
   /* In c language when we divide two integers we get integer result for example 5/2 evaluates to 2. 
     As a general rule integer/integer = integer and float/integer = float or integer/float = float. 
    So we convert denominator to float in our program, you may also write float in numerator. 
    This explicit conversion is known as typecasting. */
   /* Typecasting is simply a mechanism by which we can change the data type of a variable, 
     no matter how it was originally defined. When a variable is typecasted into a different type, 
     the compiler basically treats the variable as of the new data type. */
   add      = first + second;
   subtract = first - second;
   multiply = first * second;
   divide   = first / (float)second;   //typecasting
 
   //print the results of the above arithmetic operations
   printf("Sum = %d\n",add);
   printf("Difference = %d\n",subtract);
   printf("Multiplication = %d\n",multiply);
   printf("Division = %.2f\n",divide);
 
   return 0;
}