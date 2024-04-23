/*
Final Project
by Lior Roife (2062578268) , Maor Zemach (206273690)
*/

#include "MainHeader.h"
#include "Header1.h"
#include "Header2.h"
#include "Header3.h"
#include "Header4.h"
#include "Header6.h"


int checkAndDisplayPathFromFile(char* file_name, movesArray** moves, char** board)
{
	int i = 0, valMovesCount = 0;
	short int BitsDecoded = 0;//bits decoded count
	boardPosArray** allowedMoves = validMoves(moves, board);//board positions array with the valid moves only
	boardPos start;//starting pos
	boardPos* Data;//decoded data
	Move validMove;//used to save a valid move (cordinates) if found
	Data = DecodeFromFile(file_name, &BitsDecoded);
	bool Validator = false;//bool variable used to flag when No valid Path found.
	if (Data == NULL)
		return THE_FILE_DOES_NOT_EXIST;
	else
	{
		movesList* validMovesList = (movesList*)malloc(sizeof(movesList) * BitsDecoded);
		assert(validMovesList != NULL);
		makeEmptyList(validMovesList);
		int currRow = 0, currCol = 0;
		while (i + 1 < BitsDecoded && !Validator)
		{
			currRow = Data[i][0];
			currCol = Data[i][1];
			if (isAllowed(Data[i + 1], allowedMoves[currRow][currCol]))
			{
				validMove.rows = Data[i + 1][0] - Data[i][0];
				validMove.cols = Data[i + 1][1] - Data[i][1];
				insertDataToEndList(validMovesList, validMove);
				valMovesCount++;
			}
			else
				Validator = true;
			i++;
		}
		if (Validator)
			return NO_VALID_PATH;
		else
		{
			start[0] = Data[0][0];
			start[1] = Data[0][1];
			int AsterisksCount, Path;
			AsterisksCount = CountAsterisks(board);
			valMovesCount -= display(validMovesList, start, board);
			Path = (N  * M ) - AsterisksCount - 1;
			if (valMovesCount == Path)//if the the number of the valid moves =  the number of the non asterisk cells; We found a path that covers the entire board.
				return FULL_PATH_FOUND;
			else
				return PARTIAL_PATH_FOUND;
		}
		FinalFree(Data, allowedMoves, validMovesList);
	}
}

void FinalFree(boardPosArray** allowedMoves, boardPos* Data, movesList* validMovesList)
{
	int i, j, k;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (allowedMoves[i][j].size > 0)
			{
				for (k = 0; k < allowedMoves[i][j].size; k++)
				{
					free(allowedMoves[i][j].positions[k]);
				}
			}
			free(allowedMoves[i][j].positions);
		}
		free(allowedMoves[i]);
	}
	free(allowedMoves);
	free(Data);
	moveCell* tempHead = validMovesList->head;
	while (validMovesList->head != NULL)
	{
		tempHead = validMovesList->head;
		validMovesList->head = validMovesList->head->next;
		free(tempHead);
	}
	free(validMovesList);
}

boardPos* DecodeFromFile(char* file_name, short int* size)
{
	FILE* fp;//file pointer
	fp = fopen(file_name, "rb");
	boardPos* resBoardPosArray;
	boardPos* tempDecodedBoardPosArray;
	BYTE* BYTES_Array = (BYTE*)malloc(sizeof(BYTE) * 3);
	assert(BYTES_Array != NULL);
	tempDecodedBoardPosArray = (boardPos*)malloc(sizeof(boardPos) * 3);//used to decode and save the valid board positions before we copy the them to the result board positions array.
	assert(tempDecodedBoardPosArray != NULL);
	int logSize = 0;
	short int totalMoves = 0;//Moves counter which is later used as a size variable.
	if (fp != NULL)
	{
		fread(&totalMoves, sizeof(short int), 1, fp);
		*size = totalMoves;
		resBoardPosArray = (boardPos*)malloc(sizeof(boardPos) * (*size));
		assert(resBoardPosArray != NULL);
		for (int i = 0; i < *size; i += 3)
		{
			fread(BYTES_Array, sizeof(BYTE), 3, fp);
			DecodeData(BYTES_Array, tempDecodedBoardPosArray);
			for (int j = 0; j < 4 && totalMoves>0; totalMoves--, j++)
			{
				resBoardPosArray[logSize][0] = tempDecodedBoardPosArray[j][0];
				resBoardPosArray[logSize][1] = tempDecodedBoardPosArray[j][1];
				logSize++;
			}
		}
		fclose(fp);
		free(BYTES_Array);
	}
	else
		resBoardPosArray = NULL;
	return resBoardPosArray;
}

void DecodeData(BYTE* data, boardPos* decData)
{
	BYTE m1, m2, m3a, m3b, m4, m5, m6a, m6b, m7, m8;
	m1 = 0xE0;//msb
	m2 = 0x1C;
	m3a = 0x03;
	m3b = 0x80;
	m4 = 0x70;
	m5 = 0x0E;
	m6a = 0x01;
	m6b = 0xC0;
	m7 = 0x38;//lsb
	m8 = 0x07;

	decData[0][0] = ((data[0] & m1) >> 5) + 1;
	decData[0][1] = ((data[0] & m2) >> 2) + 1;
	decData[1][0] = (((data[0] & m3a) << 1) | ((data[1] & m3b) >> 7)) + 1;
	decData[1][1] = ((data[1] & m4) >> 4) + 1;
	decData[2][0] = ((data[1] & m5) >> 1) + 1;
	decData[2][1] = (((data[1] & m6a) << 2) | ((data[2] & m6b) >> 6)) + 1;
	decData[3][0] = ((data[2] & m7) >> 3) + 1;
	decData[3][1] = (data[2] & m8) + 1;
}

bool isAllowed(boardPos curr, boardPosArray allowedMoves)
{
	int i = 0;
	for (i; i < allowedMoves.size; i++)
	{
		if (allowedMoves.positions[i][0] == curr[0] && allowedMoves.positions[i][1] == curr[1])
			return true;
	}
	return false;
}

void makeEmptyList(movesList* lst)
{
	lst->head = NULL;
	lst->tail = NULL;
}

bool isEmptyList(movesList* lst)
{
	if (lst->head == NULL)
		return true;
	else
		return false;
}

void insertDataToEndList(movesList* lst, Move data)
{
	moveCell* newTail;
	newTail = createNewListNode(data, NULL);
	insertNodeToEndOfList(lst, newTail);
}

moveCell* createNewListNode(Move data, moveCell* next)
{
	moveCell* res;
	res = (moveCell*)malloc(sizeof(moveCell));
	assert(res != NULL);
	res->move = data;
	res->next = next;
	return res;
}

void insertNodeToEndOfList(movesList* lst, moveCell* tail)
{
	if (isEmptyList(lst) == true) 
	{
		lst->head = lst->tail = tail;
	}
	else
	{
		lst->tail->next = tail;
		lst->tail = tail;
	}
	tail->next = NULL;
}
