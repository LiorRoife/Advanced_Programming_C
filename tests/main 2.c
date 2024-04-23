
#include "Headers.h"

void main()
{
	char** board = makeBoard();
	pathTree res;
	boardPos start = { 1,2 };
	movesArray** moves = (movesArray**)malloc(sizeof(movesArray*));

	for (int i = 0; i < N; i++)
	{

		moves[i] = (movesArray*)malloc(sizeof(movesArray) * M);

		for (int j = 0; j < M; j++)
		{
			moves[i][j].moves = (Move*)malloc(sizeof(Move));
			moves[i][j].size = 0;
		}
	}
	// PLACES WITH * E1,D6,B8,A4

	board[5][1] = '*';
	board[4][6] = '*';
	board[2][8] = '*';
	board[1][4] = '*';


	//A2
	moves[1][2].size = 4;

	moves[1][2].moves[0].rows = 2;
	moves[1][2].moves[0].cols = -1;

	moves[1][2].moves[1].rows = 2;
	moves[1][2].moves[1].cols = 1;

	moves[1][2].moves[2].rows = 1;
	moves[1][2].moves[2].cols = 2;

	moves[1][2].moves[3].rows = 4;
	moves[1][2].moves[3].cols = -1;

	//C3
	moves[3][3].size = 3;
	moves[3][3].moves[0].rows = -2;
	moves[3][3].moves[0].cols = -1;

	moves[3][3].moves[1].rows = -1;
	moves[3][3].moves[1].cols = 5;

	moves[3][3].moves[2].rows = 1;
	moves[3][3].moves[2].cols = 3;

	//B4
	moves[2][4].size = 6;

	moves[2][4].moves[0].rows = 3;
	moves[2][4].moves[0].cols = -3;

	moves[2][4].moves[1].rows = -1;
	moves[2][4].moves[1].cols = 2;

	moves[2][4].moves[2].rows = 1;
	moves[2][4].moves[2].cols = 2;

	moves[2][4].moves[3].rows = 2;
	moves[2][4].moves[3].cols = 1;

	moves[2][4].moves[4].rows = 2;
	moves[2][4].moves[4].cols = -1;

	moves[2][4].moves[5].rows = 1;
	moves[2][4].moves[5].cols = -2;

	//C1
	moves[3][1].size = 5;
	moves[3][1].moves[0].rows = 1;
	moves[3][1].moves[0].cols = 5;

	moves[3][1].moves[1].rows = 1;
	moves[3][1].moves[1].cols = 1;

	moves[3][1].moves[2].rows = -1;
	moves[3][1].moves[2].cols = 2;

	moves[3][1].moves[3].rows = 1;
	moves[3][1].moves[3].cols = 2;

	moves[3][1].moves[4].rows = 2;
	moves[3][1].moves[4].cols = 1;

	//C6
	moves[3][6].size = 3;
	moves[3][6].moves[0].rows = 0;
	moves[3][6].moves[0].cols = 2;

	moves[3][6].moves[1].rows = -2;
	moves[3][6].moves[1].cols = -2;

	moves[3][6].moves[2].rows = -1;
	moves[3][6].moves[2].cols = -2;


	res = findAllPossiblePaths(start, moves, board);


}
