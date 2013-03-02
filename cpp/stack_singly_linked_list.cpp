#include<iostream>
using namespace std; 
class stack
{
	class node
	{
	public:

		int data;
		node* next;
	};
	node* first;
	inline int push (int data);
	inline int pop (int& data);

public:
	stack();
	~stack();
	void print() const;
	stack& operator << (int data)
	{
		push(data);
		return *this; 
	}
	void operator >> (int& data)
	{
		pop(data);
	}
	stack& operator << (stack& s);
	bool is_empty();

};

stack::stack()
{
	first = NULL;
}

stack::~stack()
{
	while ( first!=NULL)
	{
		node* tmp = first->next;
		delete first;
		first = tmp;
	}
}

bool stack::is_empty()
{
	if ( first == NULL)
	{
		return true;
	}
	return false;
}

int stack::push (int data)
{
	node* tmp = new node; 

	if ( tmp==NULL)
		throw -1;

	tmp->data = data;

	if ( first == NULL)
	{
		tmp->next = NULL;
	}
	else
	{
		tmp->next = first;
	}
	first = tmp;
	return 0;
}

int stack::pop (int& data)
{
	if ( first == NULL)
		throw -2;

	node* tmp = first->next;
	data = first->data;
	delete first;
	first = tmp;
	return 0;
}

void stack::print() const
{
	node* tmp = first;

	while ( tmp != NULL)
	{
		cout<< tmp->data<<" ";
		tmp = tmp->next;
	}
	cout<<endl;
}

stack& stack::operator << (stack& s)
{
	while ( s.is_empty() != true )
	{
		int data;
		s.pop(data);
		push (data);
	}

	return *this;
}

int main(void)
{
	stack s, s1;

	
	s<<10<<20<<30<<40;
	s1<<50<<60<<70<<80; 

	s.print();
	s<<s1; 
	s.print();
	cout<<"h"; 
	s1.print();
	return 0;
}
