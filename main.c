#include "lr-array.h"

void main() {
    printf("Swap with temp array\n");
    Array array = emptyIntArray();

    for (int filled = 0; filled < CELLS_QUANTITY; filled++) {
        fillCellWithRandomNumbers(&array);
    }
    showCells(&array);

    swapCells(&array, 0, CELL_SIZE);
    invertCell(&array, CELL_SIZE);

    swapCells(&array, CELL_SIZE * 2, CELL_SIZE * 3);
    invertCell(&array, CELL_SIZE * 3);

    showCells(&array);

    printf("\nSwap with temp variable\n");

    Array defaultArray = emptyIntArray();

    for (int filled = 0; filled < CELLS_QUANTITY; filled++) {
        fillCellWithRandomNumbers(&defaultArray);
    }
    showCells(&defaultArray);

    swapCellsByDefaultArray(&defaultArray, 0, CELL_SIZE);
    invertCell(&defaultArray, CELL_SIZE);

    swapCellsByDefaultArray(&defaultArray, CELL_SIZE * 2, CELL_SIZE * 3);
    invertCell(&defaultArray, CELL_SIZE * 3);

    showCells(&defaultArray);
}