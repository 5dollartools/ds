#include <stdio.h>
#include <stdlib.h>

struct node				
{
	int data;
	struct node *next;
};

int sll_add_tail(struct node **ppNode, int data)
{
	struct node *pTempNode = malloc (sizeof(struct node));

	if ( pTempNode == NULL)
	{
		return -1;
	}
	pTempNode->data = data ;
	pTempNode->next = NULL;

	if ( *ppNode == NULL)
	{
		*ppNode = pTempNode;
	}
	else
	{
		struct node *pIter = *ppNode;
		while (pIter->next)
			pIter = pIter->next;

		pIter->next = pTempNode;
	}
	return 0;
}

int sll_add_head(struct node **ppNode, int data)
{
	struct node *pTempNode = malloc ( sizeof(struct node));
	if ( !pTempNode)
		return -1;

	pTempNode->data = data;
	pTempNode->next = *ppNode;
	*ppNode = pTempNode;
	return 0;
}

int sll_insert_before(struct node **ppNode, int key, int data)
{
	struct node *pIter = *ppNode;
	struct node *pPrev = NULL;
	while ( pIter)
	{
		if ( pIter->data == key)
		{
			struct node *pTempNode = malloc ( sizeof (struct node));

			if ( !pTempNode)
				return -1;

			pTempNode->data = data;

			pTempNode->next = pIter;
			if ( pPrev ==NULL)
			{
				*ppNode = pTempNode;
			}
			else
			{
				pPrev->next = pTempNode;
			}
			break;
		}
		pPrev = pIter;
		pIter = pIter->next;
	}
	return 0;
}

int sll_insert_after (struct node **ppNode, int key, int data)
{
	struct node *pIter = *ppNode;
	while ( pIter)
	{
		if ( pIter->data == key)
		{
			struct node *pTempNode = malloc ( sizeof (struct node));

			if ( !pTempNode)
				return -1;

			pTempNode->data = data;
			pTempNode->next = pIter->next;
			pIter->next = pTempNode;
			break;
		}

		pIter= pIter->next;
	}

	return 0;
}

int sll_print(struct node *pStart)
{
	if ( pStart == NULL)
		return -1;

	printf ("\n");
	while ( pStart)
	{
		printf ("%d\t", pStart->data);
		pStart = pStart->next;
	}

	return 0;
}


void sll_reverse_non_recursive(struct node **ppNode)
{
	struct node *pPrev = NULL;
	struct node *pCurrent = *ppNode;

	while (pCurrent)
	{
		struct node *pNext = pCurrent->next;
		pCurrent->next = pPrev;
		pPrev = pCurrent;
		pCurrent = pNext;
	}

	*ppNode = pPrev;
}


void sll_reverse_recursive(struct node **ppNode)
{
	if (*ppNode)
	{
		struct node *pFirst =  *ppNode;
		struct node *pRest = (*ppNode)->next;

		if ( pRest == NULL)
			return;

		sll_reverse_recursive(&pRest);
		pFirst->next->next = pFirst;
		pFirst->next = NULL;
		*ppNode = pRest;
	}
}

int sll_delete_node ( struct node **ppNode, int key)
{
	if ( *ppNode == NULL)
		return -1;

	struct node *pIter = *ppNode;
	struct node *pPrev = NULL;

	while(pIter)
	{
		if ( pIter->data ==key)
		{
			if ( pPrev == NULL)
			{
				*ppNode = pIter->next;
			}
			else
			{
				pPrev->next = pIter->next;
			}
			free ( pIter);
			break;
		}
		pPrev= pIter;
		pIter = pIter->next;
	}
	return 0;
}

int sll_find_key ( struct node *pStart, int key )
{
	int found = 0;
	while ( pStart)
	{
		if ( pStart->data == key )
		{
			found = 1;
			break;
		}
		pStart = pStart->next;
	}
	return found;
}


int main(void)
{
	struct node *l1 = NULL;

	sll_add_head(&l1, 5);
	sll_add_tail(&l1, 10);
	sll_add_tail(&l1, 20);
	sll_add_tail(&l1, 30);
	sll_add_tail(&l1, 40);
	sll_add_tail(&l1, 60);

	sll_print (l1);
	sll_delete_node( &l1, 30) ;
	sll_print (l1);

	sll_reverse_recursive(&l1);
	sll_print (l1);


	return 0;
}
