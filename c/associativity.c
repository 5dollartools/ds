#include <stdio.h>
void main()
{
	int a = 1 , b = 0, c = 3;

	//if no brackets then first left of comma is returned
	// if brackets are specified then right of , is returned.
	// In any case both the expressions are evaluated.

	a = 1, 2; //here a = 1
	a = ((1, 2), 3, 4); // here a is 4
	printf ( "%d", a);
}

