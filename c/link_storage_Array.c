/*
 ============================================================================
 Name        : LinkStorage_Array.c
 Author      : Rahul Bedge
 Version     :
 Copyright   : GPL
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int next[MAX];
int array[MAX];

int avail = -1;
int extent = -1;
int first = -1;

void Initialize ()
{
	avail = -1;
	extent = -1;
	first = -1;
}


int addTail ( int data)
{
	int newIndex;
	if ( avail == -1)
	{
		if ( extent == MAX-1)
			return -1;

		newIndex = ++extent;
	}
	else
	{
		newIndex = avail;
		avail= avail[next];
	}

	array[newIndex] = data;
	next[newIndex] = -1;

	int temp = first;
	int prev = -1;
	while ( temp != -1)
	{
		prev = temp;
		temp = temp[next]; // this is same as next[temp]
	}

	if ( prev == -1)
	{
		first = newIndex;
	}
	else
	{
		next[prev] = newIndex;
	}
	return 0;
}

int deleteNode ( int data )
{
	if ( first == -1)
		return -1;

	int temp = first;
	int prev = -1;
	while ( temp!=-1 )
	{
		if (data == array[temp])
		{
			if ( avail != -1)
			{
				next[avail] = avail;
			}
			avail = temp;

			if ( prev != -1)
			{
				prev[next] = temp[next];
			}
			else
			{
				first = -1;
			}

			temp = prev[next];
			continue;
		}
		prev = temp;
		temp = temp[next];
	}
	return 0;
}

//addhead
//print
//reverse
//recursiveReverse

int main(void)
{
	Initialize();
	return 0;
}
