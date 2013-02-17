#include <iostream>
#include<stdio.h>

using namespace std;

class singly_linked_list
{
private :
	class node
	{
	public:
		int m_data;
		node *m_next;
	};
	node *m_first;
	int m_count;
public:
	singly_linked_list();
	int sll_add_head(int data);
	int sll_print() const;
	int sll_add_tail(int data); 	
	~singly_linked_list();
	

};

singly_linked_list::singly_linked_list()
{
	m_count = 0;
	m_first = NULL;
}

singly_linked_list::~singly_linked_list()
{
	while ( m_first) 
	{
		node *next = m_first->m_next; 
		delete m_first; 
		m_first = next;
	}
}


int singly_linked_list::sll_add_head(int data)
{
	node *_tmp = new node;

	if ( _tmp == NULL)
		throw;

	_tmp->m_data = data;
	_tmp->m_next = m_first;
	m_first = _tmp;

	return 0;
}

int singly_linked_list::sll_add_tail(int data)
{
	node *tmp = new node; 
	if ( tmp == NULL)
		throw;

	tmp->m_data = data ;
	tmp->m_next= NULL;

	if ( m_first == NULL)
	{
		m_first = tmp;
	}
	else
	{
		node *iter = m_first;
		while (iter->m_next)
			iter = iter->m_next;

		iter->m_next = tmp;
	}
	return 0;
}

int singly_linked_list::sll_print() const
{
	if ( m_first == NULL)
		return -1;
		
	node *_iter = m_first;
	while ( _iter) 
	{
		cout<<_iter->m_data<<"\t";
		_iter = _iter->m_next;
	}
	
	cout<<endl; 
	return 0;
}



int main()
{
	singly_linked_list a;
	a.sll_add_head(10);
	a.sll_add_head(20);
	a.sll_add_head(30);
	a.sll_add_tail(40); 
	a.sll_add_tail(50); 
	a.sll_print();

	return 0;
}
