#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Add comments
struct node
{
	int data;
	struct node* lchild;
	struct node* rchild;
};

struct sq_node
{
	struct node *pData;
	struct sq_node* next;
};

struct queue
{
	struct sq_node *front;
	struct sq_node *rear;
};

struct stack
{
	struct sq_node *top;
};

void Push ( struct stack *pStack, struct node *pData)
{
	struct sq_node *pTemp = malloc ( sizeof(struct sq_node));

	if ( !pTemp)
		return;

	pTemp->pData = pData;
	pTemp->next = pStack->top;
	pStack->top = pTemp;
}

struct node *Pop ( struct stack *pStack)
{
	if (!pStack->top)
		return NULL;

	struct sq_node *pTemp = pStack->top;
	struct node *pData  = pTemp->pData;
	pStack->top = pTemp->next;
	free(pTemp);
	return pData;

}

struct node* PeekStack(struct stack *pStack)
{
	if ( !pStack->top)
		return NULL;

	return pStack->top->pData;
}

int IsStackEmpty(struct stack *pStack)
{
	return pStack->top == NULL;
}


struct node *DeQueue (struct queue *pQueue)
{
	if ( !pQueue->front)
		return NULL;

	struct sq_node *pTemp = pQueue->front;
	struct node *pData = pTemp->pData;
	pQueue->front = pTemp->next;
	if ( !pQueue->front)
		pQueue->rear = NULL;

	free(pTemp);
	return pData;
}
void Enqueue(struct queue *pQueue, struct node *pData)
{
	struct sq_node *pTempNode = malloc (sizeof(struct sq_node));

	if ( !pTempNode)
		return;


	pTempNode->next = NULL;
	pTempNode->pData = pData;

	if ( pQueue->front == NULL)
	{
		pQueue->front = pQueue->rear = pTempNode;
	}
	else
	{
		pQueue->rear->next = pTempNode;
		pQueue->rear = pTempNode;
	}
}
int IsQueueEmpty(struct queue *pQueue)
{
	return pQueue->front == NULL;
}

void InitializeQueue(struct queue *pQueue)
{
	pQueue->front = NULL;
	pQueue->rear = NULL;
}

void InitializeStack(struct stack *pStack)
{
	pStack->top = NULL;
}

struct node *bst_new_node(int data)
{
	struct node *pNode = malloc ( sizeof ( struct node));
	if ( pNode == NULL)
		return NULL;

	pNode->lchild = NULL;
	pNode->rchild = NULL;
	pNode->data = data ;

	return pNode;
}

int bst_add_node ( struct node **pptnode, int data)
{
	/// check if root is NULL
	if ( !(*pptnode))
	{
		*pptnode = bst_new_node(data);
		return 0;
	}

	struct node *pRoot = *pptnode;

	while (1)
	{
		if ( data == pRoot->data)
		{
			break;
		}
		else if ( data < pRoot->data )
		{
			if ( pRoot->lchild)
				pRoot = pRoot->lchild;
			else
			{
				pRoot->lchild = bst_new_node(data);
				break;
			}
		}
		else
		{
			if ( pRoot->rchild)
				pRoot = pRoot->rchild;
			else
			{
				pRoot->rchild = bst_new_node(data);
				break;
			}
		}
	}

	return 0;
}

void bst_in_order_recursive( struct node *pRoot)
{
	if ( pRoot != NULL)
	{

		// The sequence of RChild and pLChild will give descending and
		// The sequence of LChild and pRChild will give ascending
		bst_in_order_recursive(pRoot->lchild);
		printf ( "%d\t", pRoot->data);
		bst_in_order_recursive(pRoot->rchild);
	}
}

void bst_pre_order_recursive( struct node *pRoot)
{
	if ( pRoot != NULL)
	{

		printf ( "%d\t", pRoot->data);
		bst_pre_order_recursive(pRoot->lchild);
		bst_pre_order_recursive(pRoot->rchild);
	}
}

void bst_post_order_recursive( struct node *pRoot)
{
	if ( pRoot != NULL)
	{

		bst_post_order_recursive(pRoot->lchild);
		bst_post_order_recursive(pRoot->rchild);
		printf ( "%d\t", pRoot->data);
	}
}

void bst_breadth_first_traverse(struct node *pRoot)
{
	if ( !pRoot)
		return;

	struct queue Queue;
	InitializeQueue(&Queue);
	Enqueue(&Queue, pRoot);
	while ( !IsQueueEmpty(&Queue))
	{
		struct node *pTemp = DeQueue(&Queue);
		printf ( "%d\t", pTemp->data);
		if ( pTemp->lchild)
			Enqueue(&Queue, pTemp->lchild);
		if ( pTemp->rchild)
			Enqueue(&Queue, pTemp->rchild);
	}
}

void bst_inorder_non_recursive(struct node* pRoot)
{
	struct stack Stack;
	InitializeStack(&Stack);

	while ( !IsStackEmpty(&Stack) || pRoot)
	{
		if ( pRoot)
		{
			Push(&Stack, pRoot);
			pRoot = pRoot->lchild;
		}
		else
		{
			struct node *pTemp = Pop (&Stack);
			printf ( "%d\t", pTemp->data);
			pRoot = pTemp->rchild;
		}
	}

}

void bst_preorder_non_recursive(struct node* pRoot)
{
	struct stack Stack;
	InitializeStack(&Stack);

	while ( !IsStackEmpty(&Stack) || pRoot)
	{
		if ( pRoot)
		{
			printf ( "%d\t", pRoot->data);
			Push(&Stack, pRoot);
			pRoot = pRoot->lchild;
		}
		else
		{
			struct node *pTemp = Pop (&Stack);
			pRoot = pTemp->rchild;
		}
	}

}

void bst_postorder_non_recursive(struct node* pRoot)
{
	if ( !pRoot)
		return;
	struct stack Stack;
	InitializeStack(&Stack);
	struct node *prev = NULL;
	struct node *current = NULL;

	Push(&Stack, pRoot);

	while (!IsStackEmpty(&Stack))
	{
		current = PeekStack(&Stack);

		if ( prev == NULL || prev->lchild == current || prev->rchild == current)
		{
			if ( current->lchild)
				Push ( &Stack, current->lchild);
			else if ( current->rchild)
				Push ( &Stack, current->rchild);
		}
		else if ( current->lchild == prev)
		{
			if ( current->rchild)
				Push (&Stack, current->rchild);
		}
		else
		{
			struct node *pTemp = NULL;
			pTemp = Pop(&Stack);
			printf ( "%d\t", pTemp->data);
		}

		prev = current;
	}

}

struct node *bst_find_detach_predessor(struct node *pTarget)
{
	struct node* pIter = pTarget->lchild;
	struct node* pPrevious  = pTarget;

	while ( pIter && pIter->rchild)
	{
		pPrevious = pIter;
		pIter = pIter->rchild;
	}
	pPrevious->rchild = pIter->lchild;
	return pIter;

}

void bst_delete_node ( struct node** pRoot, int data)
{
	int found = 0;
	struct node **pplink = pRoot;
	struct node *pCurrent = *pRoot;

	while ( pCurrent)
	{
		if ( data < pCurrent->data)
		{
			pplink = &(pCurrent->lchild);
			pCurrent = pCurrent->lchild;
		}
		else if ( data > pCurrent->data)
		{
			pplink = &(pCurrent->rchild);
			pCurrent = pCurrent->rchild;
		}
		else if ( pCurrent->data == data)
		{
			found = 1;
			break;
		}
	}

	if (found)
	{
		if ( pCurrent->lchild == NULL && pCurrent->rchild == NULL)
		{
			*pplink = NULL;
			free(pCurrent);
		}
		else if ( pCurrent->lchild && pCurrent->rchild )
		{
			struct node* pIter = pCurrent->lchild;
			struct node* pPrevious  = pCurrent;

			while ( pIter && pIter->rchild)
			{
				pPrevious = pIter;
				pIter = pIter->rchild;
			}
			pPrevious->rchild = pIter->lchild;
			pCurrent->data = pIter->data;
		}
		else
		{
			// assignment has low priority so RHS is evaluated first
			*pplink = pCurrent->lchild ? pCurrent->lchild:pCurrent->rchild;
			free(pCurrent);
		}
	}
}

void bst_to_dll ( struct node ** start_node)
{
	if ( *start_node != NULL)
	{
		bst_to_dll(&(*start_node)->lchild);
		printf ( "%d\t", (*start_node)->data);
		bst_to_dll(&(*start_node)->rchild);
	}
}

int main(void)
{
	struct node *pRoot = NULL;

	bst_add_node(&pRoot, 4);
	bst_add_node(&pRoot, 12);
	bst_add_node(&pRoot, 2);
	bst_add_node(&pRoot, 5);
	bst_add_node(&pRoot, 9);
	bst_add_node(&pRoot, 14);
	bst_add_node(&pRoot, 3);
	bst_add_node(&pRoot, 7);
	bst_add_node(&pRoot, 10);

	bst_to_dll(&pRoot);




	return 0;
}
