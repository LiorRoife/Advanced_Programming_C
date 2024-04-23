/*
Final Project
by Lior Roife (2062578268) , Maor Zemach (206273690)
*/

#ifndef HEADER5
#define HEADER5

//This func gets as input a file name, and a boardPosArray (pos_arr)
//The func saves the input boardPosArray to encoded binary file
void saveListToBinFile(char* file_name, boardPosArray* pos_arr);

//This func used to "complete" the encoding of of a Position cordinates
void encodeTherest(char* mask, FILE* fp, int size);

//This func gets as input a mask (char*) , boardPosArray and an integer
//The func encode 4 bytes at a time  (in every iteration)
void insertToMask(char* mask, boardPosArray pos_arr, int i);

#endif