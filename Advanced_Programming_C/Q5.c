/*
Final Project
by Lior Roife (2062578268) , Maor Zemach (206273690)
*/

#include "MainHeader.h"
#include "Header5.h"

void saveListToBinFile(char* file_name, boardPosArray* pos_arr)
{
	FILE* file;
	int i = 0;
	unsigned short int size = (short)(*pos_arr).size;
	file = fopen(file_name, "wb+");
	fwrite(&size, sizeof(short int), 1, file);
	char* mask;
	mask = (char*)calloc(3, sizeof(char));
	assert(mask != NULL);
	while (i < size)
	{
		if (i % 4 == 0 && i != 0)                     //Every four iterations we Write Four encoded positions
		{
			fwrite(mask[0], sizeof(char), 1, file);
			fwrite(&mask[1], sizeof(char), 1, file);
			fwrite(&mask[2], sizeof(char), 1, file);
			mask[0] = 0;
			mask[1] = 0;
			mask[2] = 0;
		}
		insertToMask(mask, (*pos_arr), i);
		i++;
	}
	encodeTherest(mask, file, size);                  //We encode the rest of the positions and write them to the file
	fclose(file);
}

void insertToMask(char* mask, boardPosArray pos_arr, int i)//Encode the positions
{
	if (i % 4 == 0)
	{
		mask[0] |= (pos_arr.positions[i][0] - 1) << 5;
		mask[0] |= (pos_arr.positions[i][1] - 1) << 2;
	}
	if (i % 4 == 1)
	{
		mask[0] |= (pos_arr.positions[i][0] - 1) >> 1;
		mask[1] |= (pos_arr.positions[i][0] - 1) << 7;
		mask[1] |= (pos_arr.positions[i][1] - 1) << 4;
	}
	if (i % 4 == 2)
	{
		mask[1] |= (pos_arr.positions[i][0] - 1) << 1;
		mask[1] |= (pos_arr.positions[i][1] - 1) >> 2;
		mask[2] |= (pos_arr.positions[i][1] - 1) << 6;
	}
	if (i % 4 == 3)
	{
		mask[2] |= (pos_arr.positions[i][0] - 1) << 3;
		mask[2] |= (pos_arr.positions[i][1] - 1);
	}
}

void encodeTherest(char* mask, FILE* fileP, int size)
{
	if (size % 4 == 1)
	{
		fwrite(&mask[0], sizeof(char), 1, fileP;
	}
	if (size % 4 == 2)
	{
		fwrite(&mask[0], sizeof(char), 1, fileP);
		fwrite(&mask[1], sizeof(char), 1, fileP);
	}
	if (size % 4 == 3)
	{
		fwrite(&mask[0], sizeof(char), 1, fileP);
		fwrite(&mask[1], sizeof(char), 1, fileP);
		fwrite(&mask[2], sizeof(char), 1, fileP);
	}
}