#include "Headers.h"
void main()
{
	char** board = makeBoard();
	movesList* res;
	boardPos start = { 1,2 };
	movesArray** moves = (movesArray**)malloc(sizeof(movesArray*));

	for (int i = 0; i < N; i++)
	{

		moves[i] = (movesArray*)malloc(sizeof(movesArray) * M);

		for (int j = 0; j < M; j++)
		{
			moves[i][j].moves = (Move*)malloc(sizeof(Move)*2);
			moves[i][j].size = 0;
		}
	}
	////A2
	moves[1][2].size = 2;
	moves[1][2].moves[0].rows = 1;
	moves[1][2].moves[0].cols = 0;

	moves[1][2].moves[0].rows = 0;
	moves[1][2].moves[0].cols = 1;
	//A3
	moves[1][3].size = 1;
	moves[1][3].moves[0].rows = 0;
	moves[1][3].moves[0].cols = -2;
	//A1
	moves[1][1].size = 1;
	moves[1][1].moves[0].rows = 1;
	moves[1][1].moves[0].cols = 0;
	//B1
	moves[2][1].size = 1;
	moves[2][1].moves[0].rows = 0;
	moves[2][1].moves[0].cols = 1;
	//B2
	moves[2][2].size = 1;
	moves[2][2].moves[0].rows = 0;
	moves[2][2].moves[0].cols = 1;

	//B3
	moves[2][3].size = 1;
	moves[2][3].moves[0].rows = 1;
	moves[2][3].moves[0].cols = 0;
	//C3
	moves[3][3].size = 1;
	moves[3][3].moves[0].rows = 0;
	moves[3][3].moves[0].cols = -2;

	board[3][2] = '*';

	res = findPathCoveringAllBoard(start, moves, board);

}
