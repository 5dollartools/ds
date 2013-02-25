/*
 ============================================================================
 Name        : QueueUsingSinglyLinkedList.c
 Author      : Rahul Bedge
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef int queue_data;

struct node
{
	queue_data data;
	struct node *next;
};

struct queue
{
	int size;
	struct node* front;
	struct node* rear;
};

void queue_initialize(struct queue *pQueue)
{
	pQueue->front = NULL;
	pQueue->rear = NULL;
	pQueue->size = 0;
}

int queue_enqueue(struct queue *pQueue, queue_data data)
{
	if ( !pQueue)
		return -1;

	struct node *pTempNode = malloc ( sizeof (struct node));

	if ( !pTempNode)
		return -1;

	pTempNode->data = data;
	pTempNode->next = NULL;

	if ( pQueue->front == NULL)
	{
		pQueue->front = pQueue->rear = pTempNode;
	}
	else
	{
		pQueue->rear->next = pTempNode;
		pQueue->rear = pTempNode;
	}
	pQueue->size++;

	return 0;
}

int queue_dequeue(struct queue *pQueue, queue_data *data)
{
	if ( !pQueue || !pQueue->front)
		return -1;

	struct node *pTemp = pQueue->front;
	*data = pTemp->data;
	pQueue->front = pTemp->next;
	free(pTemp);

	pQueue->size--;

	return 0;
}

void queue_print(struct queue *pQueue)
{
	struct node *pStart = pQueue->front;

	printf ( "Size of queue: %d\n", pQueue->size);
	while ( pStart)
	{
		printf ( "%d\t", pStart->data);
		pStart = pStart->next;
	}
}

int queue_IsEmpty(struct queue *pQueue)
{
	return pQueue->front == NULL?1:0;
}

int main()
{
	struct queue Queue;
	queue_initialize(&Queue);
	queue_enqueue(&Queue, 10);
	queue_enqueue(&Queue, 20);
	queue_enqueue(&Queue, 30);


	printf ( "Empty: %d\n", queue_IsEmpty(&Queue));
	queue_print(&Queue);

	return 0;


}
