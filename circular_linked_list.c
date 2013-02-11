/*
 ============================================================================
 Name        : CircularLinkList.c
 Author      : Rahul Bedge
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};

int cll_add_node (struct node **ppNode, int data )
{
	struct node *pTempNode = malloc (sizeof (struct node));
	if ( !pTempNode )
		return -1;

	if (*ppNode == NULL)
	{
		*ppNode = pTempNode;
	}
	else
	{
		struct node *pIter = *ppNode;
		struct node *pPrev = *ppNode;

		while ( pIter && pIter->next!=*ppNode)
		{
			printf ("%d %d", pIter->data, pIter->next->data);
			pPrev = pIter;
			pIter = pIter->next;
		}
		pPrev->next = pTempNode;
	}
	pTempNode->next = *ppNode;
	return 0;
}

void cll_print(struct node *pStart)
{
	if ( !pStart)
		return;

	printf ("test \n");
	while ( pStart && pStart->next != pStart)
	{
		printf ( "%d\t", pStart->data);
		pStart = pStart->next;
	}
}

void cll_initialize(struct node **ppNode)
{
	if ( *ppNode)
	{
		(*ppNode)->data = 0;
		(*ppNode)->next = NULL;

	}
}

int main(void)
{
	struct node* pStart = NULL;

	cll_initialize(&pStart);

	cll_add_node(&pStart, 10);
	cll_add_node(&pStart, 20);
	cll_add_node(&pStart, 30);

	cll_print(pStart);

	return EXIT_SUCCESS;
}
