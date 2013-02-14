#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};

int cll_add_node_head ( struct node **start_node, int data)
{
	struct node *tmp = malloc (sizeof(struct node)); 
	if (!tmp)
		return -1; 
	
	tmp->data = data; 
	if ( !*start_node)
	{
		*start_node = tmp; 
		tmp->next = *start_node; 
	}
	else
	{
		struct node *iter = *start_node; 
		while ( iter && iter->next!=*start_node)
			iter = iter->next; 

		tmp->next = *start_node; 
		*start_node = tmp; 
		iter->next = *start_node; 
	}
	return 0; 
}

int cll_add_node_tail (struct node **start_node, int data )
{
	struct node *tmp = malloc (sizeof(struct node));
	if ( !tmp)
		return -1;
		
	tmp->data = data; 

	if (!*start_node)
	{
		*start_node = tmp;
	}
	else
	{
		struct node *iter = *start_node;

		while ( iter && iter->next!=*start_node)
			iter = iter->next;

		iter->next = tmp; 
	}
	tmp->next = *start_node;
	return 0;
}

void cll_print(struct node *start_node)
{
	if ( !start_node)
		return;

	printf ("\n");

	struct node *iter = start_node; 
	do 
	{
		printf ("%d ", iter->data); 
		iter = iter->next; 
	}while (iter!=start_node); 

	printf ("\n"); 
}

int cll_delete ( struct node ** start_node, int key)
{
	if ( !*start_node)
		return -1; 
		
	struct node *iter = *start_node; 
	struct node *prev = NULL;
	
	do 
	{
		if ( key == iter->data)
		{
			if ( !prev)
			{
				struct node *tmp_iter = iter;

				while ( tmp_iter  && tmp_iter->next!=iter)
					tmp_iter = tmp_iter->next;
				
				
			}
			else
			{
				prev->next = iter->next; 
			}
			free ( iter); 
			break; 
		}
		
		prev = iter; 
		iter = iter->next; 
		
	}while (iter!=*start_node); 
	
		
	return 0; 
}

int main(void)
{
	struct node* start_node = NULL;
	cll_add_node_head(&start_node, 10);
	cll_add_node_head(&start_node, 20);
	cll_add_node_head(&start_node, 30);
	cll_add_node_tail(&start_node, 40);
	
	/*cll_add_node_tail(&start_node, 10);
	cll_add_node_tail(&start_node, 20);
	cll_add_node_tail(&start_node, 30);
	cll_add_node_tail(&start_node, 40);
	cll_add_node_tail(&start_node, 50);*/

	cll_print(start_node);
	
	cll_delete(&start_node, 20); 
	
	cll_print(start_node);
	
	return EXIT_SUCCESS;
}
