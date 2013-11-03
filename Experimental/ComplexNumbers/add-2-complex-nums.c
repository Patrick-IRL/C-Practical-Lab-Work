/*	Program to display how to add two complex numbers as completd in a standard 'C' program.
		Developer Name : ________________	Date : __________
		Version Number : V1.00			Comment : Initial Program
*/
/* This program calculate the sum of two complex numbers which will be entered by the user and then prints it. 
User will have to enter the real and imaginary parts of two complex numbers. 
In our program we will add real parts and imaginary parts of complex numbers and prints the complex number, i is the symbol used for iota. 
For example if user entered two complex numbers as (1 + 2i) and (4 + 6 i) then output of program will be (5+8i) */
#include <stdio.h>

//structure used to store the complex number 
struct complex
{
   int real, img;
};
 
main()
{
   struct complex a, b, c;
   
   //user to provide complex number input
   printf("Enter a and b where a + ib is the first complex number.\n");
   printf("a = ");
   scanf("%d", &a.real);
   printf("b = ");
   scanf("%d", &a.img);
   printf("Enter c and d where c + id is the second complex number.\n");
   printf("c = ");
   scanf("%d", &b.real);
   printf("d = ");
   scanf("%d", &b.img);
   
   //assign real & imaginary components
   c.real = a.real + b.real;
   c.img = a.img + b.img;
 
   //check for imaginary value and print result
   if ( c.img >= 0 )
      printf("Sum of two complex numbers = %d + %di\n",c.real,c.img);
   else
      printf("Sum of two complex numbers = %d %di\n",c.real,c.img);
 
   return 0;
}