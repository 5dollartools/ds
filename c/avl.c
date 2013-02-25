#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int bst_add_node_iter ( struct node **pptnode, int data)
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

int bst_add_node_iter1 ( struct node **pptnode, int data)
{
	if ( !(*pptnode))
	{
		*pptnode = bst_new_node(data);
		return 0;
	}

	struct node *pRoot = *pptnode;
	struct node **parent_link = pptnode;

	while (pRoot)
	{
		if ( data == pRoot->data)
			return -1;

		/*
		 * Notice the comma operator. Because of the () the expression to the right is returned and on the left is evaluated.
		 * Comma is least priority lesser than = so braket is important and becuase we are using () we need to reverse the
		 * sequence of pRoot->lchild and parent_link
		 */
		pRoot= data<pRoot->data ? (parent_link = &(pRoot->lchild), pRoot->lchild) : (parent_link = &(pRoot->rchild), pRoot->rchild);
	}

	*parent_link = bst_new_node(data);

	return 0;
}

int bst_add_node_iter2 ( struct node **pptnode, int data)
{
	if ( !(*pptnode))
	{
		*pptnode = bst_new_node(data);
		return 0;
	}

	struct node *pRoot = *pptnode;
	struct node **parent_link = pptnode;

	while (pRoot)
	{
		if ( data == pRoot->data)
			return -1;

		/*
		 * Notice the comma operator. Because of the () the expression to the right is returned and on the left is evaluated
		 */
		pRoot= data<pRoot->data ? (parent_link = &(pRoot->lchild), pRoot->lchild) : (parent_link = &(pRoot->rchild), pRoot->rchild);

		/*
		 * This is also an alternate way.
		 */
		//data<pRoot->data ? (parent_link = &(pRoot->lchild); pRoot = pRoot->lchild) : (parent_link = &(pRoot->rchild); pRoot = pRoot->rchild);
	}

	*parent_link = bst_new_node(data);

	return 0;
}


void bst_restore_balance(struct node **);

void bst_add_node_recur ( struct node **ppNode, int data)
{
	if ( !(*ppNode ))
		*ppNode = bst_new_node(data);
	else
	{
		bst_add_node_recur(((data < (*ppNode)->data) ? &(*ppNode)->lchild : &(*ppNode)->rchild), data);
		bst_restore_balance(ppNode);
	}
}


void bst_in_order_recursive( struct node *pRoot)
{
	if ( pRoot != NULL)
	{

		/*
		 * The sequence of RChild and pLChild will give descending and
		 * The sequence of LChild and pRChild will give ascending
		 */
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
		if ( pTemp)
			printf ( "%d ", pTemp->data);
		else
			printf ( "X ");

		if ( pTemp)
		{
		//if ( pTemp->lchild)
			Enqueue(&Queue, pTemp->lchild);
		//if ( pTemp->rchild)
			Enqueue(&Queue, pTemp->rchild);

		}
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

#define MAX (a,b) ((a)>(b)?(a):(b))

int bst_node_height (struct node *pNode)
{
	if ( pNode == NULL)
	{
		return 0;
	}
	else
	{
		return 1+ (bst_node_height(pNode->lchild)|bst_node_height(pNode->rchild));
	}
}

int bst_node_balance_factor (struct node *pNode)
{
	if (!pNode)
		return 0;

	return bst_node_height(pNode->lchild) - bst_node_height(pNode->rchild);
}

struct node *bst_ll_rotate(struct node *subtree_root)
{
	struct node *pivot = subtree_root->lchild;
	subtree_root->lchild = pivot->rchild;
	pivot->rchild = subtree_root;
	return pivot;
}

struct node *bst_rr_rotate(struct node *subtree_root)
{
	struct node *pivot = subtree_root->rchild;
	subtree_root->rchild = pivot->lchild;
	pivot->lchild = subtree_root;
	return pivot;
}

struct node *bst_lr_rotate(struct node *subtree_root)
{
	subtree_root->lchild = bst_rr_rotate(subtree_root->lchild);
	return bst_ll_rotate(subtree_root);
}

struct node *bst_rl_rotate(struct node *subtree_root)
{
	subtree_root->rchild = bst_ll_rotate(subtree_root->rchild);
	return bst_rr_rotate(subtree_root);
}

void bst_restore_balance(struct node **parent)
{
	int bf_parent = bst_node_balance_factor(*parent);
	if ( bf_parent < -1)
	{
		if ( bst_node_balance_factor((*parent)->rchild) < 0)
		{
			printf ( "rr on %d\n", (*parent)->data);
			*parent = bst_rr_rotate(*parent);
		}
		else
		{
			printf ( "rl on %d\n", (*parent)->data);
			*parent = bst_rl_rotate(*parent);
		}
	}
	else if ( bf_parent > 1)
	{
		if ( bst_node_balance_factor((*parent)->lchild) > 0)
		{
			printf ( "ll on %d\n", (*parent)->data);
			*parent = bst_ll_rotate(*parent);
		}
		else
		{
			printf ( "lr on %d\n", (*parent)->data);
			*parent = bst_lr_rotate(*parent);
		}
	}
}


int main(void)
{
	struct node *pRoot = NULL;

	bst_add_node_recur(&pRoot, 1);
	bst_add_node_recur(&pRoot, 2);
	bst_add_node_recur(&pRoot, 3);
	bst_add_node_recur(&pRoot, 4);
	bst_add_node_recur(&pRoot, 5);
	bst_add_node_recur(&pRoot, 6);
	bst_add_node_recur(&pRoot, 7);

	bst_breadth_first_traverse(pRoot);

	return 0;
}
