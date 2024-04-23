/*
Final Project
by Lior Roife (2062578268) , Maor Zemach (206273690)
*/

#ifndef HEADER4
#define HEADER4

//This func gets as input boardPos starting cordinates (start), movesArray, and a board
//The func returns a movesList with all possible pathes covered.
movesList* findPathCoveringAllBoard(boardPos start, movesArray** moves, char** board);

//This func gets as input strating cordinates (start), movesArray, row & col cordinates , a moveCell which present the current path , a pointer to a boolean flag (x), 
//a pointer to an movesList, AsteriskCount and the Path Length.
//The func find a path covering the entire board (Except the ASTERISKS cells)
void getPath(boardPos start, boardPosArray** moves, int row, int col, moveCell* currPath, bool* x, movesList** res, int AsteriskCount, int pathLength);

//The func gets as input the current Position (cPOs) , a moveCell (path) and the path length
//The func returns true if the cordinates of the current position exsit in the path.
bool Exist(boardPos cPos, moveCell* path, int* pathLength);

//This func gets as input a board, the func count the *'s and return the number.
int CountAsterisks(char** board);

#endif