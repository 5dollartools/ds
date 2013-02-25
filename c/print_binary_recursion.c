/*
 ============================================================================
 Name        : PrintBinary_recursion.c
 Author      : Rahul Bedge
 Version     :
 Copyright   : GPL
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void PrintBinary (int num)
{
	if ( num == 0)
		return;

	//num = num/2;
	PrintBinary(num/2);
	printf ( "%d", num%2);
}

int main(void)
{
	int num = 0;
	printf ( "Enter a number: ");
	scanf ("%d", &num);

	PrintBinary(num);

	return 0;
}
