#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>                  /*  for sleep()  */
#include <curses.h>

#define SNAKESIZE 4
WINDOW * mainwin;


int DrawSnake( )
{
	int startX = 30;
	int startY = 20;
	int countLength = 1;

	for ( countLength = 1; countLength<=SNAKESIZE; countLength++)
	{
		attrset (COLOR_PAIR(countLength));
		mvaddch(startY, startX+(5), '#');
	}


}

void Initialize()
{
	if ( (mainwin = initscr()) == NULL )
	{
		fprintf(stderr, "Error initialising ncurses.\n");
		exit(EXIT_FAILURE);
	}

	start_color();                    /*  Initialize colours  */

	init_pair(1,  COLOR_RED,     COLOR_BLACK);
	init_pair(2,  COLOR_YELLOW,  COLOR_BLACK);
	init_pair(3,  COLOR_GREEN,   COLOR_BLACK);
	init_pair(4,  COLOR_BLACK,    COLOR_BLACK);
}

int main(void)
{
	int c, x, y;
	Initialize();

	DrawSnake();



	refresh();
	getch();


	/*  Clean up after ourselves  */
	delwin(mainwin);
	endwin();
	refresh();

	return EXIT_SUCCESS;
}

