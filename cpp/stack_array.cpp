/*
 ============================================================================
 Name        : Stack.c
 Author      : Rahul Bedge
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


// Define the goal for sub routines. Direction and planning needs to be done.

#include <stdio.h>
typedef  int ItemType;


#define STACKSIZE 4
#define TRUE 1
#define FALSE 0
#define PRINT "%d\t"

ItemType stack[STACKSIZE];
int top;

int IsEmpty()
{
	if ( top <= 0  )
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int IsFull()
{
	if ( top >= STACKSIZE)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}

}

void Push ( ItemType c )
{
	if ( top < STACKSIZE)
		stack[top++] = c;
	else
		printf ( "Stack overflow!!!\n");
}

int Pop ( ItemType* p)
{
	if ( top > 0 )
	{
		/// Done a problem in '--' decrement
		/// This is an order problem.
		/// expression evaluation intent was to pre increment but I was post incrementing
		*p = stack[--top];
		return 0 ;
	}
	else
	{
		printf ( "Stack underflow!!!\n");
		return -1;
	}
}

void printStack( )
{
	// fucked the print logic. Needs to take care of top when printing.
	// logic error: step were incorrect
	int count;

	if ( IsEmpty() == TRUE)
	{
		printf ( "Stack is empty\n");
		return;
	}

	for (count = 0; count < top; count++)
	{
		printf ( PRINT, stack[count]);
	}

	printf ( "\n");
}

int main(void)
{
	ItemType p ;

	Push(10);
	Push(20);
	Push(30);
	Push(40);
	printStack();
	Pop(&p);
	printStack();
	Pop(&p);
	printStack();
	//printStack();

	return 0;
}



