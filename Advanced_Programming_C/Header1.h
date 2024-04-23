/*
Final Project
by Lior Roife (2062578268) , Maor Zemach (206273690)
*/

#ifndef HEADER1
#define HEADER1

//This func gets as input movesArray (moves) , and a board (char**)
//The func check removes invalid moves from the movesArray, and returns a boardPosArray with the valid moves.
boardPosArray** validMoves(movesArray** moves, char** board);

//This func gets as input movesArray , a board (char**) , rows, cols cordinates
//The func inserts the valid moves from the movesArray to a new BoardPosArray which the func returns at the end.
boardPosArray CheckAndInsertMoves(movesArray* moves, char** board, int rows, int cols);

//This func gets as input moves array and an index (curIndex)
//The func removes the move from the input moves arrray
void removeElement(movesArray* moves, int curIndex);

//This func gets as input board (char**), move values (char rows, cols) and indexes for the place in board
//This func checks if a given "move" is valid.
bool checkMove(char** board, char moveRow, char moveCol, int i, int j);

#endif