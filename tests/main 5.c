#include "Headers.h"
void main()
{
	char** board = makeBoard();
	boardPosArray* posArray;
	posArray = (boardPosArray*)malloc(sizeof(boardPosArray));
	posArray[0].size = 9;
	posArray[0].positions = (boardPos*)malloc(sizeof(boardPos) * 9);

	posArray[0].positions[0][0] = 1;
	posArray[0].positions[0][1] = 1;

	posArray[0].positions[1][0] = 1;
	posArray[0].positions[1][1] = 2;

	posArray[0].positions[2][0] = 1;
	posArray[0].positions[2][1] = 3;

	posArray[0].positions[3][0] = 2;
	posArray[0].positions[3][1] = 1;

	posArray[0].positions[4][0] = 2;
	posArray[0].positions[4][1] = 2;

	posArray[0].positions[5][0] = 2;
	posArray[0].positions[5][1] = 3;


	posArray[0].positions[6][0] = 3;
	posArray[0].positions[6][1] = 1;


	posArray[0].positions[7][0] = 3;
	posArray[0].positions[7][1] = 2;

	posArray[0].positions[8][0] = 3;
	posArray[0].positions[8][1] = 3;

	saveListToBinFile("TEST.bin", posArray);

}
