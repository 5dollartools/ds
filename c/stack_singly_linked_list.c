/*
 ============================================================================
 Name        : StackUsingSinglyLinkedList.c
 Author      : Rahul Bedge
 Version     :
 Copyright   : GPL
 Description : Stack implementation using Single linked list
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct _element
{
	int key;
	struct _element* next;
} element, *pelement, **ppelement;

int PushItem ( ppelement ppElement,int data)
{

	if ( ppElement == NULL )
		return -1 ; 

	pelement pTempElement = (pelement)malloc (sizeof(element));
	if ( pTempElement==NULL)
		return -1;

	pTempElement->key = data;

	if ( *ppElement == NULL)
	{
		// this is the first node
		pTempElement->next = NULL;
	}
	else
	{
		// not first element then always point the new node to the first node and set the first node point to temp node
		pTempElement->next = *ppElement;
	}
	*ppElement = pTempElement;

	return 0;
}

int PopItem ( ppelement ppElement, int* pData)
{

	if ( ppElement == NULL || *ppElement == NULL)
		return -1;

	pelement pElement = (*ppElement)->next;
	*pData = (*ppElement)->key;
	free ( *ppElement);
	*ppElement = pElement;


	return 0;

}

void printStack( pelement pElement)
{
	if ( pElement == NULL)
	{
		printf ("Stack is empty\n");
		return;
	}

	while ( pElement)
	{
		printf ( "%d\t", pElement->key);
		pElement = pElement->next;
	}
	printf ("\n");
}

int main(void)
{
	element* pStart = NULL;
	int data = 0;

	PushItem(&pStart, 10);
	PushItem(&pStart, 20);
	PushItem(&pStart, 30);
	PushItem(&pStart, 40);
	PushItem(&pStart, 50);
	PushItem(&pStart, 60);

	printStack ( pStart);

	PopItem(&pStart, &data);
	printf ( "Popped data: %d\n", data);
	printStack ( pStart);
	PopItem(&pStart, &data);
	printf ( "Popped data: %d\n", data);
	printStack ( pStart);
	PopItem(&pStart, &data);
	printf ( "Popped data: %d\n", data);
	printStack ( pStart);
	PopItem(&pStart, &data);
	printf ( "Popped data: %d\n", data);
	printStack ( pStart);


	return 0;
}
