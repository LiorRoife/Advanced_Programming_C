/*
Final Project
by Lior Roife (2062578268) , Maor Zemach (206273690)
*/

#include "MainHeader.h"
#include "Header1.h"
#include "Header2.h"
#include "Header3.h"

pathTree findAllPossiblePaths(boardPos start, movesArray** moves, char** board)
{
	boardPosArray** optionalMoves = validMoves(moves, board);
	pathTree newPathTree;
	newPathTree.head = createNewTreeNode(start,NULL);
	int row = start[0], col = start[1];
	int movesArraySize = optionalMoves[start[0]][start[1]].size;
	newPathTree.head = createNewTreeNode(start, NULL);
	newPathTree.head->next_possible_positions = createList(start, optionalMoves, row, col, NULL);
	return newPathTree;
}

bool isExist(boardPos currPos , moveCell* path)
{
	while (path != NULL)
	{
		if (path->move.rows == currPos[0] && path->move.cols == currPos[1])
			return true;
		else
			path = path->next;
	}
	return false;
}

treeNodeListCell* createList(boardPos start, boardPosArray** moves, int row, int col, moveCell* currPath)
{
	int i = 0;
	treeNodeListCell* Node = (treeNodeListCell*)malloc(sizeof(treeNodeListCell));
	assert(Node != NULL);
	Node = NULL;
	int size;
	size = moves[row][col].size;
	currPath = insertNodeToEndList(start, currPath);
	for (i; i < (unsigned int)size; i++)
	{
		boardPos currPos;
		if (moves[start[0]][start[1]].positions[i][0] == 0 && moves[start[0]][start[1]].positions[i][1] == 0)
			i++;
		if (i <= size)
		{
			currPos[0] = moves[start[0]][start[1]].positions[i][0];
			currPos[1] = moves[start[0]][start[1]].positions[i][1];
		}
		if (!isExist(currPos, currPath)) //if the cordinates doesn't appear
		{
			treeNode* node = createNewTreeNode(currPos, NULL);
			treeNodeListCell* listCell = createNewTreeNodeListCell(node, NULL);
			listCell->node->next_possible_positions = createList(currPos, moves, currPos[0], currPos[1], currPath);
			listCell->next = Node;
			Node = listCell;
		}
	}
	free(currPath);
	return Node;
}


treeNodeListCell* createNewTreeNodeListCell(treeNode* treeNode, treeNodeListCell* next)
{
	treeNodeListCell* res = (treeNodeListCell*)malloc(sizeof(treeNodeListCell));
	assert(res != NULL);
	res->node = treeNode;
	res->next = next;
	return res;
}

moveCell* insertNodeToEndList(boardPos start, moveCell* currPath)
{
	moveCell* newNode;
	newNode = (moveCell*)malloc(sizeof(moveCell));
	assert(newNode != NULL);
	newNode->move.rows = start[0];
	newNode->move.cols = start[1];
	newNode->next = currPath;
	return newNode;
}

treeNode* createNewTreeNode(boardPos cell, treeNodeListCell* nextPossiblePos)
{
	treeNode* res;
	res = (treeNode*)malloc(sizeof(treeNode));
	assert(res != NULL);
	res->position[0] = cell[0];
	res->position[1] = cell[1];
	res->next_possible_positions = nextPossiblePos;
	return res;
}