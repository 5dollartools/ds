/*
 ============================================================================
 Name        : 20121229_InfixToPostfix.c
 Author      : Rahul Bedge
 Version     :
 Copyright   : GPL
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

#define SIZE 100
typedef char Stack_Type;

typedef struct _stack
{
	Stack_Type storage[SIZE];
	int top;
} stack, *pstack;

int Push ( pstack pStack, Stack_Type data)
{
	if ( pStack && pStack->top < SIZE)
	{
		pStack->storage[++pStack->top] = data;
		return 0;
	}
	return -1;
}

int Pop( pstack pStack, Stack_Type* pData)
{
	if ( pStack && pStack->top != -1)
	{
		*pData = pStack->storage[pStack->top--];
		return 0;
	}
	return -1;
}

int Peek(pstack pStack, Stack_Type* pData)
{
	if ( pStack && pStack->top != -1)
	{
		*pData = pStack->storage[pStack->top];
		return 0;
	}
	return -1;
}

int IsEmpty( pstack pStack)
{
	return pStack->top == -1; // return the result of numeric expression.
}


/*
 * Initializes the stack
 */
void InitializeStack(pstack ps)
{
	ps->top = -1;
}

int IsFirstLowerOrEqualPriority( char oper1, char oper2)
{
	if ( (oper1 == '+' || oper1 == '-') && ( oper2 == '/' || oper2 == '*') )
	{
		return 1;
	}
	else if ( ((oper1 == '+' || oper1 == '-') && ( oper2 == '+' || oper2 == '-')) ||
			(((oper1 == '*' || oper1 == '/') && ( oper2 == '*' || oper2 == '/'))))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main(void)
{
	stack s1;
	char infix[SIZE] = "";
	char postfix[SIZE] = "";
	char* pInfix = infix;
	char* pPostFix = NULL;

	char currentChar ;
	int postfix_counter = 0;
	Stack_Type temp;

	int result = 0;

	InitializeStack(&s1);

	/* */
	printf ("Enter the infix\n");
	scanf( "%s", infix); // TODO: Stop over flow

	while ( (currentChar = *pInfix) ) // *pInfix != '\0' temp allows us to save dereferencing twice.
	{
		switch ( currentChar)
		{
			case '/':
			case '*':
			case '+':
			case '-':
				if (IsEmpty(&s1))
				{
					Push ( &s1, currentChar);
				}
				else
				{

					while (!IsEmpty(&s1))
					{
						Peek(&s1, &temp);
						if (IsFirstLowerOrEqualPriority(currentChar, temp))
						{
							Pop ( &s1, &temp);
							postfix[postfix_counter++] = temp;
						}
						else
							break;
					}
					Push ( &s1, currentChar);
				}
			break;

			case '(':
				Push(&s1, '('); // temp is always '(' so why read from temp
			break;

			case ')':
				while (1)
				{
					Pop(&s1, &temp);
					if ( temp == '(')
						break;

					postfix[postfix_counter++] = temp;
				}
				break;

			default:
				postfix[postfix_counter++] = currentChar;
				break;

		}

		++pInfix;
	}

	while (!IsEmpty(&s1))
	{
		Pop( &s1, &currentChar);
		postfix[postfix_counter++] = currentChar;
	}
	postfix[postfix_counter] = '\0';

	printf ( "%s\n", postfix);

	InitializeStack(&s1);
	pPostFix = postfix;

	while ( (currentChar = *pPostFix) ) // *pPostFix != '\0' temp allows us to save dereferencing twice.
	{
		Stack_Type first, second ;

		switch ( currentChar)
		{
			case '/':
				Pop ( &s1, &first);
				Pop ( &s1, &second);
				Push ( &s1, second/first );
				break;
			case '*':
				Pop ( &s1, &first);
				Pop ( &s1, &second);
				Push ( &s1, second*first );
				break;
			case '+':
				Pop ( &s1, &first);
				Pop ( &s1, &second);
				Push ( &s1, second+first );
				break;
			case '-':
				Pop ( &s1, &first);
				Pop ( &s1, &second);
				Push ( &s1, second -first );
				break;

			default:
				Push (&s1, (currentChar-'0'));
				break;
		}

		++pPostFix;
	}

	if ( Pop ( &s1, &currentChar) != -1 )
	{
		printf ( "%d", currentChar);
	}

	return 0;
}
