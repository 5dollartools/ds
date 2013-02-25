#include <iostream>
using namespace std;

class queue
{
	class node
	{
	public :
		int data;
		node *next;
	};
	int size;
	node* front;
	node* rear;

	inline void enqueue(int data);
	inline void dequeue(int& data);

public:
	queue();
	~queue();
	void operator << (int data)
	{
		enqueue(data);
	}
	void operator >> (int& data)
	{
		dequeue(data);
	}
	void print() const;
	bool is_empty() const;
	bool is_full() const;
};

queue::queue()
{
	front = NULL;
	rear = NULL;
	size = 0;
}

queue::~queue()
{
	while (front!=NULL)
	{
		delete front;
		front = front->next;
	}
}

void queue::enqueue(int data)
{
	node *tmpNode = new node;

	if ( tmpNode == NULL)
		throw -1;

	tmpNode->data = data;
	tmpNode->next = NULL;

	if ( front == NULL)
	{
		front = rear = tmpNode;
	}
	else
	{
		rear->next = tmpNode;
		rear = tmpNode;
	}
	size++;
}

void queue::dequeue(int& data)
{
	if ( front == NULL)
		throw -2;
	node *tmpNode = front;
	data = tmpNode->data;
	front = tmpNode->next;
	delete tmpNode;
	size--;
}

void queue::print() const
{
	node *pStart = front;

	cout<<endl<<"Size of queue: "<<size<<endl; ;
	while ( pStart)
	{
		cout << pStart->data<<" ";
		pStart = pStart->next;
	}
	cout<<endl;
}

bool queue::is_empty() const
{
	return front == NULL?true:false;
}

int main()
{
	queue a;
	a<<2;
	a<<3;
	a<<4;
	a<<5;

	int test;
	a >> test;
	cout<<test;
	a >> test;
	cout<<test;

	a.print();
	return 0;


}
