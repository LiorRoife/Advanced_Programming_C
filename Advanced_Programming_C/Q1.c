/*
Final Project
by Lior Roife (2062578268) , Maor Zemach (206273690)
*/

#include "MainHeader.h"
#include "Header1.h"

boardPosArray** validMoves(movesArray** moves, char** board)
{
	boardPosArray** res;
	res = (boardPosArray**)malloc(N * sizeof(boardPosArray*));
	assert(res != NULL);
	int i, j;
	for (i = 0; i < N; i++)
	{
		res[i] = (boardPosArray*)malloc(M * sizeof(boardPosArray));
		assert(res[i] != NULL);
		for (j = 0; j < M; j++)
		{
			if (moves[i][j].size > 0)   // if movesArray has at least 1 move we check movesArray[i][j]
				res[i][j] = CheckAndInsertMoves(&moves[i][j], board, i, j);
			else
				res[i][j].size = 0;    // if the movesArray size is 0 , we update the BoardPosArray to be 0.
		}
	}
	return res;
}

boardPosArray CheckAndInsertMoves(movesArray* moves, char** board, int rows, int cols)
{
	int i = 0;
	boardPosArray res;
	res.positions = (boardPos*)malloc(sizeof(boardPos) * moves->size);
	assert(res.positions != NULL);
	for (i; i < moves->size; i++)
	{
		if (checkMove(board, moves->moves[i].rows, moves->moves[i].cols, rows, cols))//if the move is valid we keep it
		{
			res.positions[i][0] = moves->moves[i].rows + (char)rows;
			res.positions[i][1] = moves->moves[i].cols + (char)cols;
		}
		else                                                                         //if the move isn't valid we remove it
		{
			removeElement(moves, i);
			i--;
		}
	}
	res.size = moves->size;//update the size at the end
	if (res.size != 0)
		res.positions = realloc(res.positions, sizeof(boardPos) * res.size);
	return res;
}

bool checkMove(char** board, char moveRow, char moveCol, int i, int j)
{
	moveRow += i;
	moveCol += j;
	if (moveRow >= N || moveCol >= M || moveRow < 0 || moveCol < 0) //We check if the current move is out of the board line limits
		return false;
	else if (board[moveRow][moveCol] != SPACE) //We check if the current move doesn't step on SPACE
		return false;                          //if the current move is ilegal
	else
		return true;                           //if the current move is legal
}

void removeElement(movesArray* moves, int curIndex)
{
	int tempSize;
	tempSize = moves->size - 1;
	char stepR = moves->moves[curIndex].rows;
	char stepC = moves->moves[curIndex].cols;
	stepR = moves->moves[tempSize].rows;
	stepC = moves->moves[tempSize].cols;
	moves->size -= 1;
	if (moves->size == 0)//if there are no steps left in moves to take
		free(moves->moves);
}