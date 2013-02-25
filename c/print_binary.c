/*
 ============================================================================

 Name        : PrintBinary.c
 Author      : Rahul Bedge
 Version     :
 Copyright   : GPL
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 32


typedef  struct _stack
{
	int arr[SIZE];
	int topElement;
} Stack;

void Push ( Stack* pS, int data)
{
	if ( pS->topElement < SIZE)
	{
		pS->arr[++pS->topElement] = data;
	}
}

int Pop ( Stack* pS, int* data )
{
	if ( pS->topElement >= 0)
	{
		*data = pS->arr[pS->topElement--];
		return 0;
	}
	else
	{
		return -1;
	}
}

void Initialize(Stack* pS)
{
	pS->topElement = -1;
}

void PrintBinary()
{
	Stack s1 ;
	Initialize(&s1);
	int num = 0;
	char* p = NULL;

	printf ( "Enter a number: ");
	scanf ("%d", &num );
	do
	{
		Push ( &s1, num%2);
		printf ( "%d", num%2);
		num = num/2;
	}while ( num);

	printf ( "\n");

	while ( 1)
	{
		int output = 0;
		int ret = Pop ( &s1, &output);
		if ( ret == -1 )
			break;
		printf ( "%d", output);
	}

}

void PrintBinary_bitwise()
{
	int n = -2;
	int i = 32;
	while ( --i >= 0)
	{
		//decNum & (highestOne >> i)
		if (n & (1 << i))
			printf ( "1");
		else
			printf ( "0");

		//i--;
	}
}

int main(void)
{
	//PrintBinary();
	PrintBinary_bitwise();
	return 0;
}

