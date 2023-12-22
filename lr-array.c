#include "lr-array.h"

int random(int min, int max) {
    while(1) {
        int value = rand();
        if(value >= min && value <= max) {
            return value;
        }
    }
}

Array emptyIntArray() {
    return (Array) {
        malloc(sizeof(int) * 0),
        0
    };
}

void fillCellWithRandomNumbers(Array* array) {
    array->data = realloc(array->data, sizeof(int) * (array->size + CELL_SIZE));
    for (int i = 0; i < CELL_SIZE; i++) {
        array->data[array->size] = random(0, 100);
        (array->size)++;
    }
}

void swapCells(Array* array, int firstCellStartIndex, int secondCellStartIndex) {
    if(array->size < secondCellStartIndex + CELL_SIZE) exit(OUT_OF_BOUND_INDEX);
    if(array->size < firstCellStartIndex + CELL_SIZE) exit(OUT_OF_BOUND_INDEX);
    int* tempArray = malloc(sizeof(int) * CELL_SIZE);
    for(int i = 0; i < CELL_SIZE; i++) {
        tempArray[i] = array->data[firstCellStartIndex + i];
    }
    for(int i = 0; i < CELL_SIZE; i++) {
        array->data[firstCellStartIndex + i] = array->data[secondCellStartIndex + i];
    }
    for(int i = 0; i < CELL_SIZE; i++) {
        array->data[secondCellStartIndex + i] = tempArray[i];
    }
    free(tempArray);
}

void showCells(Array* array) {
    for (int first = 0; first < array->size; first++) {
        if (first % CELL_SIZE == 0) printf("| ");
        printf("%i ", array->data[first]);
        if (first + 1 == array->size) printf("|\n");
    }
}

void invertCell(Array* array, int startIndex) {
    if(array->size < startIndex + CELL_SIZE) exit(OUT_OF_BOUND_INDEX);
    int* tempArray = malloc(sizeof(int) * CELL_SIZE);
    for(int i = 0; i < CELL_SIZE; i++) {
        tempArray[i] = array->data[startIndex + i];
    }
    for(int i = 0; i < CELL_SIZE; i++) {
        array->data[startIndex + i] = tempArray[CELL_SIZE - (i + 1)];
    }
    free(tempArray);
}