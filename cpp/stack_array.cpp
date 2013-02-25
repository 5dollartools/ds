#include <iostream>
using namespace std;
#define STACKSIZE 4

class stack
{
	int m_top;
	int m_storage[STACKSIZE];
	inline void push(int data);
	inline void pop(int& data);

public:
	stack();
	bool is_full();
	bool is_empty();
	void operator << (int data)
	{
		push(data);
	}
	void operator >>(int& data)
	{
		pop(data);

	}
	void print() const;
};


int IsEmpty()
{
	if ( top <= 0  )
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int IsFull()
{
	if ( top >= STACKSIZE)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}

}

void Push ( ItemType c )
{
	if ( top < STACKSIZE)
		stack[top++] = c;
	else
		printf ( "Stack overflow!!!\n");
}

int Pop ( ItemType* p)
{
	if ( top > 0 )
	{
		/// Done a problem in '--' decrement
		/// This is an order problem.
		/// expression evaluation intent was to pre increment but I was post incrementing
		*p = stack[--top];
		return 0 ;
	}
	else
	{
		printf ( "Stack underflow!!!\n");
		return -1;
	}
}

void printStack( )
{
	// fucked the print logic. Needs to take care of top when printing.
	// logic error: step were incorrect
	int count;

	if ( IsEmpty() == TRUE)
	{
		printf ( "Stack is empty\n");
		return;
	}

	for (count = 0; count < top; count++)
	{
		printf ( PRINT, stack[count]);
	}

	printf ( "\n");
}

int main(void)
{
	ItemType p ;

	Push(10);
	Push(20);
	Push(30);
	Push(40);
	printStack();
	Pop(&p);
	printStack();
	Pop(&p);
	printStack();
	//printStack();

	return 0;
}



