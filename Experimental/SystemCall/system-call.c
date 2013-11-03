/*	Program to specify a system call in a  'C' program.
      Developer Name : ________________	Date : __________
	Version Number : V1.00			Comment : Initial Program
*/
/* This c program prints ip (internet protocol) address of your computer, 
   system function is used to execute the command ipconfig which prints ip address, subnet mask and default gateway. 
   The code given below works for Windows xp and Windows 7 */

#include<stdlib.h>
 
main()
{
   system("C:\\Windows\\System32\\ipconfig");
   system("pause");
 
   return 0;
}