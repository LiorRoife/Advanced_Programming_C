/*
Final Project
by Lior Roife (2062578268) , Maor Zemach (206273690)
*/

#include "MainHeader.h"
#include "Header1.h"
#include "Header2.h"
#include "Header3.h"
#include "Header4.h"

movesList* findPathCoveringAllBoard(boardPos start, movesArray** moves, char** board)
{
	boardPosArray** optionalMoves = validMoves(moves, board);
	movesList* res = (movesList*)malloc(sizeof(movesList*));
	assert(res != NULL);
	int sRow = start[0], sCol = start[1], AsteriskCount , pathLength = 0;
	AsteriskCount = CountAsterisks(board); // Count the *'s
	bool* x = false;	                   //boolean variable to mark a that a valid path found
	res->head = NULL;
	res->tail = NULL;
	getPath(start, optionalMoves, sRow, sCol, NULL, &x, &res, AsteriskCount, pathLength);
	if (x == true)
		return res;
	else
		return NULL;
}

void getPath(boardPos start, boardPosArray** moves, int row, int col, moveCell* currPath, bool* x, movesList** res, int AsteriskCount, int pathLength)
{
	int j, size;
	boardPos cPos;
	size = moves[row][col].size;
	if (((N - 1) * (M - 1)) - AsteriskCount == (pathLength + 1)) //When a valid path found we use "x" as a flag to stop the func and return the path we found
		*x = true;
	else
	{
		currPath = insertNodeToEndList(start, currPath);//insert the pos the the path
		for (j = 0; j < size; j++)
		{
			if (moves[start[0]][start[1]].positions[j][0] == 0 && moves[start[0]][start[1]].positions[j][1] == 0)
				j++;
			if (j <= size)//Update the current pos (cPos)
			{
				cPos[0] = moves[start[0]][start[1]].positions[j][0];
				cPos[1] = moves[start[0]][start[1]].positions[j][1];
			}
			if (!Exist(cPos, currPath, &pathLength))//if the move doesn't exist in the current path we use getPath
			{
				getPath(cPos, moves, cPos[0], cPos[1], currPath, x, res, AsteriskCount, pathLength);
			}
		}
		if (*x == true)    //once a valid path has been found we insert it into the result.
			(*res)->head = insertNodeToEndList(start, (*res)->head);
		free(currPath);
	}
}

bool Exist(boardPos cPos, moveCell* path, int* pathLength)
{
	*pathLength = 0;
	while (path != NULL)
	{
		*pathLength += 1;
		if ((path->move.rows == cPos[0]) && (path->move.cols == cPos[1]))
			return true;
		else
			path = path->next;
	}
	return false;
}

int CountAsterisks(char** board)
{
	int count = 0, i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (board[i][j] == ASTERISK)
				count++;
		}
	}
	return count;
}