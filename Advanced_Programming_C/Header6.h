/*
Final Project
by Lior Roife (2062578268) , Maor Zemach (206273690)
*/

#ifndef HEADER6
#define HEADER6

#define NO_VALID_PATH 1            // There is no valid path  
#define FULL_PATH_FOUND 2          // There is a path that covers the entire board (except Asterisks and Starter points)
#define PARTIAL_PATH_FOUND 3       // There is a path that covers part of the board
#define THE_FILE_DOES_NOT_EXIST -1 //The bin file does not exist in the folder

typedef unsigned char BYTE;

//This func gets as input a file name, a movesArray and a board
//The func checks if the moves in the input file doesn't conatin a valid path according to the movesArray input, and if so, returns 1.
//Else the func prints the valid path to the board (as at Q2) and if the path covers the entire board , returns 2.
//Else the func returns 3
int checkAndDisplayPathFromFile(char* file_name, movesArray** moves, char** board);

//This func used to decoded data from an input file.
//The func gets as input a file name and size and returns a boardPos array with the data decoded from the input file.
boardPos* DecodeFromFile(char* file_name, short int* size);

//This func gets as input data in BYTES and a pointer to a decoded Data variable
//the func decoded the input data and transfer it to the decoded Data input variable.
void DecodeData(BYTE* data, boardPos* decData);

//This func check if an input boardPos (row & col cordinates) appears in the input BoardPosArray (allowedMoves) and returns "True" if so.
bool isAllowed(boardPos curr, boardPosArray allowedMoves);

//This func used once at the end of the project to free every allocated memory left.
//The fun gets as input the allowedMoves array, the decodedData array and the validMovesList.
void FinalFree(boardPosArray** allowedMoves, boardPos* Data, movesList* validMovesList);

void insertNodeToEndOfList(movesList* lst, moveCell* tail);//This func inserts a node to the and end of a given list

moveCell* createNewListNode(Move data, moveCell* next);//This func creates a new ListNode.

bool isEmptyList(movesList* lst);//This func check if an inout list is empty.

void insertDataToEndList(movesList* lst, Move data);//This func used to an input move to the end of the input movesList.

void makeEmptyList(movesList* lst);//This func initiates a movesList

#endif