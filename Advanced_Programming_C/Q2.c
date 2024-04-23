/*
Final Project
by Lior Roife (2062578268) , Maor Zemach (206273690)
*/

#include "MainHeader.h"
#include "Header1.h"
#include "Header2.h"

int display(movesList* moves_list, boardPos start, char** board)
{
	char** tBoard = board; //Will be used as a template of the given board

	moveCell* movesCell = NULL;
	moveCell* currMoveList = moves_list->head;
	char colMove = '0', rowMove = '0', stepsI = '0';
	int currRow = start[0] - '0', currCol = start[1] - '0', resCounter = 0;
	tBoard[currRow][currCol] = STARTER; //Set the starter in the right place in the board.
	while (currMoveList != NULL)
	{
		colMove = currMoveList->move.cols;
		rowMove = currMoveList->move.rows;
		if (!checkMove(tBoard, rowMove, colMove, currRow, currCol))     //we check if the move is valid
		{                                                               //if the move isn't valid, remove it from the moves list
			movesCell = currMoveList->next;
			deleteCell(moves_list->head, currMoveList);
			resCounter++;
			currMoveList = movesCell;
		}
		else                                                            //else, we keep it
		{
			stepsI++;
			insertValidMove(&tBoard, stepsI, &currRow, &currCol, colMove, rowMove);
			currMoveList = currMoveList->next;
		}
	}
	PrintBoard(tBoard);              //When the work is done, print the temporary board and return the number of the deleted moves.
	return resCounter;
}

void insertValidMove(char*** board, char stepsIndex, int* currRow, int* currCol, char moveCol, char moveRow)
{
	int rows = *currRow, cols = *currCol;
	rows += moveRow; //calc row cordinate
	cols += moveCol; //calc col cordinate
	*(*(*board + rows) + cols) = stepsIndex;
	*currCol = cols;
	*currRow = rows;
}

void deleteCell(moveCell** head_ref, moveCell* del)
{
	if (*head_ref == NULL || del == NULL) 	//simple case 
		return;
	if (*head_ref == del)                 	//If the node we want to delete is the head 
		*head_ref = del->next;
	if (del->next != NULL)   	            //Change next only if the node to be deleted is NOT the last node 
		del->next->prev = del->prev;
	if (del->prev != NULL)   	            //Change prev only if node to be deleted is NOT the first node 
		del->prev->next = del->next;
	free(del);
	return;
}

char** CreateBoard()
{
	char** Board;
	Board = (char**)malloc(N * sizeof(char*));
	assert(Board != NULL);
	for (int i = 0; i < N; i++)
	{
		Board[i] = (char*)malloc(M * sizeof(char));
		assert(Board[i] != NULL);
		for (int j = 0; j < M; j++)
		{
			Board[i][j] = SPACE;
		}
	}
	return Board;
}

void PrintBoard(char** Board)
{
	printf(" ");
	for (int k = 0; k < M; k++)
	{
		printf("|%d", k + 1);
	}
	printf("|\n");
	for (int i = 0; i < N; ++i)
	{
		if (i == 0)
			printf("");
		printf("%c|", 'A' + i);
		for (int j = 0; j < M; ++j)
		{
			printf("%c|", Board[i][j]);
		}
		printf("\n");
	}
}