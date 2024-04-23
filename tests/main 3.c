#include "Headers.h"
void main()
{
	char** board = makeBoard();


	movesList moveList;
	makeEmptyList(&moveList);
	Move move1, move2, move3, move4;
	move1.cols = 1;
	move1.rows = 1;

	move2.cols = -1;
	move2.rows = -1;

	move3.rows = 2;
	move3.cols = 2;

	move4.rows = -2;
	move4.cols = -2;
	insertDataToEndList(&moveList, move1);
	insertDataToEndList(&moveList, move2);
	insertDataToEndList(&moveList, move3);
	insertDataToEndList(&moveList, move4);

	char start[2] = { '1','1' };
	display(&moveList, start, board);
}
