#ifndef _LR_ARRAY_H
#define _LR_ARRAY_H

#define CELL_SIZE 4
#define CELLS_QUANTITY 4

#define OUT_OF_BOUND_INDEX -4032

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct { 
    int* data;
    int size;
} Array;

Array emptyIntArray();
void fillCellWithRandomNumbers(Array* array);
void showCells(Array* array);
void swapCells(Array* array, int firstCellStartIndex, int secondCellStartIndex);
void invertCell(Array* array, int startIndex);

#endif