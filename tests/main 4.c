#include "Headers.h"
void main()
{
	char** board = makeBoard();
	boardPosArray** res;
	movesArray** moves = (movesArray**)malloc(sizeof(movesArray*));

	for (int i = 0; i < N; i++)
	{

		moves[i] = (movesArray*)malloc(sizeof(movesArray) * M);

		for (int j = 0; j < M; j++)
		{
			moves[i][j].moves = (Move*)malloc(sizeof(Move)*8);
			moves[i][j].size = 0;
		}
	}
	board[5][1] = '*';
	board[4][6] = '*';
	board[2][8] = '*';
	board[1][4] = '*';


	//A2
	moves[1][2].size = 1;

	moves[1][2].moves[0].rows = -4;
	moves[1][2].moves[0].cols = -5;


	//C3
	moves[3][3].size = 3;
	moves[3][3].moves[0].rows = -2;
	moves[3][3].moves[0].cols = -1;

	moves[3][3].moves[1].rows = -1;
	moves[3][3].moves[1].cols = 5;

	moves[3][3].moves[2].rows = 1;
	moves[3][3].moves[2].cols = 3;

	//B4
	moves[2][4].size = 6;

	moves[2][4].moves[0].rows = 3;
	moves[2][4].moves[0].cols = -3;

	moves[2][4].moves[1].rows = -1;
	moves[2][4].moves[1].cols = 2;

	moves[2][4].moves[2].rows = 1;
	moves[2][4].moves[2].cols = 2;

	moves[2][4].moves[3].rows = 2;
	moves[2][4].moves[3].cols = 1;

	moves[2][4].moves[4].rows = 2;
	moves[2][4].moves[4].cols = -1;

	moves[2][4].moves[5].rows = 1;
	moves[2][4].moves[5].cols = -2;

	//C1
	moves[3][1].size = 5;
	moves[3][1].moves[0].rows = 1;
	moves[3][1].moves[0].cols = 5;

	moves[3][1].moves[1].rows = 0;
	moves[3][1].moves[1].cols = 0;

	moves[3][1].moves[2].rows = -1;
	moves[3][1].moves[2].cols = 2;

	moves[3][1].moves[3].rows = 1;
	moves[3][1].moves[3].cols = 2;

	moves[3][1].moves[4].rows = 2;
	moves[3][1].moves[4].cols = 1;

	//C6
	moves[3][6].size = 3;
	moves[3][6].moves[0].rows = 0;
	moves[3][6].moves[0].cols = 2;

	moves[3][6].moves[1].rows = -2;
	moves[3][6].moves[1].cols = -2;

	moves[3][6].moves[2].rows = -1;
	moves[3][6].moves[2].cols = -2;

	res = validMoves(moves, board);

}

char** makeBoard()
{
	char ch = 'A';
	char nums = '0';
	//board initiallization
	char** board = (char**)malloc(N * sizeof(char*));
	for (int i = 0; i < N; i++)
	{
		board[i] = (char*)malloc(M * sizeof(char));

		for (int j = 0; j < M; j++)
		{
			if (j == 0 && i > 0)
			{
				board[i][j] = ch;
				ch++;
			}
			else if (i == 0)
			{
				if (j == 0)
					board[i][j] = ' ';
				else
					board[i][j] = nums;
				nums++;
			}
			else
			{
				board[i][j] = ' ';
			}
		}
	}
	return board;
}

char** buildCharBoard()
{
	char** board;
	int x;
	srand(time(NULL));   //this is initialization
	board = (char**)malloc(N * sizeof(char*));
	int i, j;

	for (i = 0; i < N; i++)
	{
		board[i] = (char*)malloc(M * sizeof(char));

		for (j = 0; j < M; j++)
		{
			x = rand() % 2;
			if (x == 0)
				board[i][j] = ' ';
			else
			{
				board[i][j] = '*';
			}
		}
	}

	return board;
}

void printBoard(char** board)
{
	int i, j;
	printf(" ");
	for (j = 1; j <= M; j++)
	{
		printf("%3d", j);
	}

	printf("\n");
	for (i = 0; i < N; i++)
	{
		printf("%c", 'A' + i);
		for (j = 0; j < M; j++)
		{
			if (board[i][j] == '*' || board[i][j] == '#' || board[i][j] == ' ')
				printf("%3c", board[i][j]);
			else printf("%3d", board[i][j]);
		}
		printf("\n");
	}
}
