#include <stdio.h>
#include <iostream>
using namespace std; 
#define QUEUELENGTH 4

class queue
{
	int m_front; 
	int m_rear;
	int m_storage[QUEUELENGTH];
	inline void enqueue (int data); 
	inline void dequeue (int& data);

public:
	queue(); 
	bool is_queue_full(); 
	bool is_queue_empty(); 
	queue& operator << (int data)
	{
		enqueue(data); 
		return *this; 
	}
	queue& operator >>(int& data)
	{
		dequeue(data); 
		return *this; 
	}
	
	void print() const; 
}; 

queue::queue()
{
	m_front = -1, m_rear = -1;
}

bool queue::is_queue_full()
{
	if ( (m_rear+1)%QUEUELENGTH == m_front)
		return true; 
	
	return false; 
}

bool queue::is_queue_empty()
{
	if ( m_front == -1)
		return true; 
	
	return false;
}

void queue::enqueue (int data)
{
	if ( m_rear == -1 )
	{
		m_front = 0 ;
		m_rear = 0;
		m_storage[m_rear] = data;
	}
	else
	{
		if ( !is_queue_full())
		{
			m_rear = (m_rear+1)%QUEUELENGTH;
			m_storage[m_rear]= data;
		}
		else
		{
			return ;
		}
	}

}

void queue::dequeue (int& data)
{
	if ( m_front != -1)
	{
		data = m_storage[m_front];

		if ( m_front == m_rear)
		{
			m_front = m_rear = -1;
		}
		else
			m_front = (m_front+1)%QUEUELENGTH;
	}
	else
	{
		printf ("Queue is empty \n");
	}
}

void queue::print() const 
{
	if (m_front == -1)
		return; 

	cout << endl; 
	
	int _front = m_front; 
	
	for ( ; _front !=  m_rear; _front = (_front+1)%QUEUELENGTH)
	{
		cout<<m_storage[_front]<<" "; 
	}
	cout<<m_storage[_front]; 
	cout<<endl; 
}

int main(void)
{
	queue a; 
	a << 10 <<20; 
	a.print(); 
	
	return 0;
}
