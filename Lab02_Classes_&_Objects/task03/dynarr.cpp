#include "dynarr.h"
#include <iostream>
using namespace std;

dynArr::dynArr() {
    data = NULL;
    row = 0, col = 0;
}

dynArr::dynArr(int row, int col) {
    data = new int *[row];
    for (int i = 0; i < row; i++) {
        data[i] = new int[col];
    }
}

dynArr::~dynArr() {
    delete[] data;
}

int dynArr::getValue(int rowIndex, int columnIndex) {
    return data[rowIndex][columnIndex];
}

void dynArr::setValue(int rowIndex, int columnIndex, int value) {
    data[rowIndex][columnIndex] = value;
}

void dynArr::allocate(int rowIndex, int columnIndex) {
    dynArr::~dynArr();
    data = new int *[rowIndex];
    for (int i = 0; i < rowIndex; i++) {
        data[i] = new int[columnIndex];
    }
}