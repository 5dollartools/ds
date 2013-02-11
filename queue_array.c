/*
 ============================================================================
 Name        : Queue.c
 Author      : Rahul Bedge
 Version     :
 Copyright   : GPL
 Description : Program to implement circular queue with an Array
 ============================================================================
 */

#include <stdio.h>

#define QUEUELENGTH 4

int front = -1, rear = -1;
int Queue[QUEUELENGTH];

// Code is not scalable. Remove the globalsfront ==

/*
 * Takes data as the parameter
 * returns 0 is success
 * returns -1 if queue is not empty
 */

int IsQueueFull()
{
	return ((rear+1)%QUEUELENGTH == front);
}

int IsQueueEmpty()
{
	return front == -1;
}

void Enqueue (int data)
{
	/*
	 * Increment end when new item is added to the list
	 * Reset end when it reaches QUEUELENGTH
	 * Check when incrementing if end == start then this indicates that the list is full. Do not allow this
	 * 	Special case when resetting this needs to be checked.
	 *
	 * 	Boundary
	 * 	1. Enqueue only when start
	*/


	// Rearrange the program to
	if ( rear == -1 )
	{
		front = 0 ;
		rear = 0;
		Queue[rear] = data;
	}
	else
	{
		if ( !IsQueueFull())
		{
			rear = (rear+1)%QUEUELENGTH;
			Queue[rear]= data;
		}
		else
		{
			return ;
		}
	}

}

/*
 * Takes variables address
 * returns 0 is success
 * returns -1 if queue is empty
 *
 */
int Dequeue (int* data)
{

	/*
	 * Do not dequeue if start == end, indicates that the list is empty
	 * Reset start when it reaches QUEUELENGTH.
	 * Check when incrementing start. if start == end then this indicates that the queue is full.
	 * 	Do not dequeue after this.
	 * 	Special case when resetting this needs to be checked. Allow start == end. Marks the queue is full
	 *
	 */
	//*data = Queue[endPosition];

	if ( front != -1)
	{
		*data = Queue[front];

		if ( front == rear)
		{
			front = rear = -1;
		}
		else
			front = (front+1)%QUEUELENGTH;
	}
	else
	{
		printf ("Queue is empty \n");
	}

	return 0;

}

int main(void)
{
	int a = 0;
	Enqueue(10);
	Enqueue(20);
	Enqueue(30);
	Enqueue(40);
	Enqueue(50);

	Dequeue(&a);
	printf("%d", a);
	Dequeue(&a);
	printf("%d", a);
	Dequeue(&a);
	printf("%d", a);
	Dequeue(&a);
	printf("%d", a);
	Dequeue(&a);
	printf("%d", a);


	return 0;
}
