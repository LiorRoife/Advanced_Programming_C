/*
Final Project
by Lior Roife (2062578268) , Maor Zemach (206273690)
*/

#ifndef HEADER3
#define HEADER3

typedef struct _treeNodeListCell 
treeNodeListCell;

typedef struct _treeNode 
{
	boardPos position;
	treeNodeListCell* next_possible_positions; // מיקומים רשימת
} treeNode;

typedef struct _treeNodeListCell // A treeNode List Cell
{
	treeNode* node;
	struct _treeNodeListCell* next;
} treeNodeListCell;

typedef struct _pathTree      // A Path Tree
{
	treeNode* head;
} pathTree;

//This func gets as input boarrdPos (starting cordinates), movesArray (moves) and a board (char**)
//The func creates a new Tree with all optional positions according to the input moves.
pathTree findAllPossiblePaths(boardPos start, movesArray** moves, char** board);

//This func gets as input a boardPos (row , col cordinates) and a moveCell pointer (path)
//The func check if the input cordinates already appear in the input path
bool isExist(boardPos currPos, moveCell* path);

//This func gets as input starting position, moves array, row, col and a pointer to a moveCell
//The func creates and returns a treeNodeListCell according the pathes of "moves"
treeNodeListCell* createList(boardPos start, boardPosArray** moves, int row, int col, moveCell* currPath);

//This func creates a new TreeNodeListCell according to the inpuy treeNode and next.
treeNodeListCell* createNewTreeNodeListCell(treeNode* treeNode, treeNodeListCell* next);

//This func inserts a node to the and end of a given list
moveCell* insertNodeToEndList(boardPos start, moveCell* currPath);

//This func creates a new TreeNode according to the input parameters (cell and nextPossiblePos)
treeNode* createNewTreeNode(boardPos cell, treeNodeListCell* nextPossiblePos);

#endif