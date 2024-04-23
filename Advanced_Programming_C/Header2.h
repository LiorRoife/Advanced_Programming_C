/*
Final Project
by Lior Roife (2062578268) , Maor Zemach (206273690)
*/

#ifndef HEADER2
#define HEADER2

typedef struct _moveCell       // A Move Cell
{
	Move move;
	struct _moveCell* next, * prev;
} moveCell;

typedef struct _movesList      // A List Of Moves
{
	moveCell* head;
	moveCell* tail;
} movesList;

//This func gets as input a pointer to a movesList , starting position ("start") and a board (char[N][M])
//The func checks every move in the input movesList , delete the forbidden moves from it.
//Then the func prints to the board "the way" the user made move by move (only the valid moves).
//At the end the func return the number of the deleted elements (how many moves deleted from the input movesList).
int display(movesList* moves_list, boardPos start, char** board);

//This func gets as input a pointer to a board(char**) , index for rows , cols , move values (char moveRow ,moveCol).
//If the move is valid the func inserts it to the right place according to the input indexes.
void insertValidMove(char*** board, char stepsIndex, int* currRow, int* currCol, char moveCol, char moveRow);

//This func gets as input pointer to the head of a list and a pointer to a move in the list, the func finds the move and delete it from the List.
void deleteCell(moveCell** head_ref, moveCell* del);

//This func gets as input a pointer to a board (char**)
//The func prints the board values to the screen.
void PrintBoard(char** Board);

//This func initiates a new board (char**).
char** CreateBoard();

#endif