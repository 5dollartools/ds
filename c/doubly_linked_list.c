#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
	struct node* previous;
};

int dll_add_head ( struct node **ppNode, int data)
{
	struct node *pTemp = malloc ( sizeof(struct node));
	if (!pTemp)
		return -1;
	pTemp->data = data;
	pTemp->previous = NULL;

	if ( *ppNode == NULL)
	{
		pTemp->next = NULL;
	}
	else
	{
		pTemp->next = *ppNode;
	}
	*ppNode = pTemp;
	return 0;
}

int dll_add_tail ( struct node **ppNode, int data)
{
	struct node *pTmpNode= malloc (sizeof(struct node));
	if ( !pTmpNode)
		return -1;

	pTmpNode->data = data;
	if ( *ppNode == NULL)
	{
		pTmpNode->previous = NULL;
	}
	else
	{
		struct node *pIter = *ppNode;
		while ( pIter->next)
			pIter = pIter->next;

		pTmpNode->previous = pIter;
		pIter->next = pTmpNode;
	}
	pTmpNode->next = NULL;

	return 0;
}

void dll_reverse_recursive ( struct node **ppNode)
{
	if ( *ppNode != NULL)
	{
		struct node *pFirst = *ppNode;
		struct node *pRemain = pFirst->next;

		if ( !pRemain)
			return;

		pRemain->previous->previous = pRemain;
		pRemain->previous = NULL;
		dll_reverse_recursive(&pRemain);
		pFirst->next->next = pFirst;
		pFirst->next= NULL;
		*ppNode = pRemain;
	}
}

void dll_reverse_non_recursive(struct node **ppNode)
{
	if ( !*ppNode)
		return ;
	struct node *pPrev = NULL;
	struct node *pIter = *ppNode;
	struct node *pIterNext = NULL;
	while (pIter)
	{
		pIterNext = pIter->next;
		pIter->next = pIter->previous;
		pIter->previous = pIterNext;
		pPrev = pIter;
		pIter = pIterNext;
	}
	*ppNode = pPrev;
}

int dll_insert_before ( struct node **ppNode, int data )
{
	if ( !*ppNode )
		return -1;

	struct node *pTmp = malloc (sizeof (struct node));
	pTmp->data = data;

	struct node *pIter = *ppNode;
	struct node *pPrev = NULL;
	while ( pIter)
	{
		if ( pIter->data == data)
		{
			pPrev = pIter->previous;
			if ( !pPrev)
			{
				pTmp->next = pIter;
				pTmp->previous = NULL;
			}
			else
			{


			}

		}

		pIter = pIter->next;
	}
}

void dll_print ( struct node *pStart)
{
	printf ( "\n");
	while ( pStart)
	{
		printf ( "%d\t", pStart->data);
		pStart = pStart->next;
	}
	printf ( "\n");
}


int main(void)
{
	struct node *l1 = NULL;

	dll_add_head(&l1, 10);
	dll_add_tail(&l1, 20);
	dll_add_tail(&l1, 30);
	dll_add_tail(&l1, 40);

	dll_print(l1);

	dll_reverse_non_recursive(&l1);

	dll_print(l1);
	return 0;
}
