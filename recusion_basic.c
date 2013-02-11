/*
 ============================================================================
 Name        : Recusion_basic.c
 Author      : Rahul Bedge
 Version     :
 Copyright   : GPL
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void Counter(int num)
{
	if ( num > 0 )
	{
		printf ( "%d\t", num); // Behaves like queue
		//Counter ( --num); // permanent modifications to inputs matters
		Counter ( num-1); //
		printf ( "%d\t", num); // Behaves like stack
	}
	else
	{
		printf("\n");
	}
}

int main(void)
{
	Counter(10);
	return 0;
}
