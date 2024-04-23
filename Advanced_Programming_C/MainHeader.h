/*
Final Project
by Lior Roife (2062578268) , Maor Zemach (206273690)
*/

#ifndef MAIN_HEADER
#define MAIN_HEADER

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#define N 4                    // Define Board Rows
#define M 5                    // Define Board Cols   (the board size being changed through those elements).
#define STARTER '#'            // Define the starting Cell in the Board as "STARTER"
#define SPACE ' '              // Define empty Cell as "SPACE"
#define ASTERISK '*'           // Define forbidden Cell with * as "ASTERISK"

typedef char boardPos[2];      //Cordinates: boardPos[0] is a row value, boardPos[1] is a col value.

typedef struct _move           // A Move On The Board.
{
	char rows, cols;
} Move;

typedef struct _movesArray     // An Array Of Moves.
{
	unsigned int size;
	Move* moves;
} movesArray;

typedef struct _boardPosArray  // An Array Of Board Positions.
{
	unsigned int size;
	boardPos* positions;
} boardPosArray;

#endif