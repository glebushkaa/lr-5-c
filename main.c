#include "lr-array.h"

void main() {
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
}