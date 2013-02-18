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
	int sll_insert_before(int key, int data); 
	int sll_insert_after (int key, int data); 
	int sll_delete_node(int key); 
	bool sll_find_key(int key) const; 
	int sll_reverese_non_recursive(); 
	
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

int singly_linked_list::sll_insert_before(int key, int data)
{
	node *iter = m_first;
	node *prev = NULL;
	while ( iter != NULL)
	{
		if ( iter->m_data == key)
		{
			node *tmp = new node; 

			if ( tmp == NULL)
				throw;

			tmp->m_data = data;

			tmp->m_next = iter;
			
			if ( prev == NULL)
			{
				m_first = tmp;
			}
			else
			{
				prev->m_next = tmp;
			}
			break;
		}
		prev = iter;
		iter = iter->m_next;
	}
	return 0;
}

int singly_linked_list::sll_insert_after (int key, int data)
{
	node *iter = m_first;
	while ( iter != NULL)
	{
		if ( iter->m_data == key)
		{
			node *tmp = new node; 

			if ( tmp == NULL)
				return -1;

			tmp->m_data = data;
			tmp->m_next = iter->m_next;
			iter->m_next = tmp;
			break;
		}

		iter = iter->m_next;
	}

	return 0;
}

bool singly_linked_list::sll_find_key( int key ) const
{
	bool found = false;
	
	node *iter = m_first; 
	while ( iter)
	{
		if ( iter->m_data == key )
		{
			found = true;
			break;
		}
		iter = iter->m_next;
	}
	return found;
}


int singly_linked_list::sll_delete_node(int key)
{
	if ( m_first == NULL)
		return -1;

	node *iter = m_first;
	node *prev = NULL;

	while(iter)
	{
		if ( iter->m_data == key)
		{
			if ( prev == NULL)
			{
				m_first = iter->m_next;
			}
			else
			{
				prev->m_next = iter->m_next;
			}
			delete( iter);
			break;
		}
		prev = iter; 
		iter = iter->m_next;
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

int singly_linked_list::sll_reverese_non_recursive()
{
	if ( m_first == NULL || m_first->m_next == NULL)
		return -1; 
		
	node *iter = m_first; 
	node *prev = NULL; 
	node *next = NULL; 
	while (iter)
	{
		next = iter->m_next; 
		iter->m_next = prev; 
		prev = iter; 
		iter = next; 
	}
	m_first = prev; 
	
	return 0; 
} 

int main()
{
	singly_linked_list a;
	a.sll_add_tail(10); 
	a.sll_add_tail(20);
	a.sll_add_tail(30); 
	a.sll_add_tail(40);
	a.sll_add_tail(50); 
	a.sll_add_tail(60);

	a.sll_print(); 
	a.sll_reverese_non_recursive(); 
	a.sll_print();
	

	return 0;
}
