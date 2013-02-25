#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

#define  ROWS 20
#define COLUMNS 20

typedef enum _STATE
{
	DEAD,
	ALIVE
}STATE;
STATE arrLife[ROWS][COLUMNS];

void ProcessState()
{
	/* Alive and dead*/
	int r = 0, c = 0;
	int liveCount = 0;
	/* size could be a concern so static */
	static STATE arrLifeMemory[ROWS][COLUMNS];


	memcpy ( &arrLifeMemory, &arrLife, sizeof(arrLifeMemory));

	for ( r = 0; r < ROWS; r++)
	{
		for ( c = 0; c<COLUMNS; c++)
		{
			liveCount = 0;

			if ( (c+1) < COLUMNS && arrLife[r][c+1])
			{
				liveCount++;
			}
			if ( (c-1) > -1 && arrLife[r][c-1])
			{
				liveCount++;
			}

			if ( (r+1) < ROWS && arrLife[r+1][c])
			{
				liveCount++;
			}
			if ( (r-1) > -1 && arrLife[r-1][c])
			{
				liveCount++;
			}

			if ( (c+1) < COLUMNS && (r+1)<ROWS  && arrLife[r+1][c+1])
			{
				liveCount++;
			}

			if ( (c-1) > -1 && (r+1)<ROWS && arrLife[r+1][c-1])
			{
				liveCount++;
			}
			if ( (c+1) < COLUMNS && (r-1)>-1 && arrLife[r-1][c+1])
			{
				liveCount++;
			}
			if ( (c-1) > -1 && (r-1)>-1 && arrLife[r-1][c-1])
			{
				liveCount++;
			}

			/* Maintain alive state neighbour should be 2 or 3 for anything else the cell dies*/
			/* Any other number the cell  dies*/
			/* From dead to alive the neighbour count should be exactly 3*/
			/* All changes happen simultenoulsly */

			if ( arrLife[r][c] == ALIVE && (liveCount > 3 || liveCount < 2))
			{
				arrLifeMemory[r][c] = DEAD;
			}
			if ( arrLife[r][c]== DEAD && ( liveCount == 3))
			{
				arrLifeMemory[r][c] = ALIVE;
			}
		}

	}
	memcpy ( &arrLife, &arrLifeMemory, sizeof(arrLife));
}


void PrintLife()
{
	/* print the matrix */
	int r = 0, c = 0;
	for ( r = 0; r < ROWS; r++)
	{
		for ( c = 0; c<COLUMNS; c++)
		{
			printf ( "%c", arrLife[r][c]==ALIVE?'X':'-');
		}
		printf("\n");
	}
}

void main()
{
	/* Ask for inputs */
	int row = 0, column = 0;
	char breakLoop = 'Y';
	int count = 0;

	while ( breakLoop == 'Y' )
	{
		printf ( "Specify R and C for marking the live cell \n");
		scanf ( "%d", &row);
		scanf ( "%d", &column);
		if ( column >= COLUMNS || row >= ROWS)
		{
			printf ( "Invalid input... \n");
			continue;
		}
		arrLife[row][column] = ALIVE;
		PrintLife();
 		scanf ( "%c", &breakLoop ) ;
		printf ( "Do you want to continue Y/N\n");
		scanf ( "%c", &breakLoop ) ;
	}


	while (1)
	{
		system("clear");
		printf ( "%d\n", ++count);
		ProcessState();
		PrintLife();
		sleep(1);
	}
}
