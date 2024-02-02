#ifndef NUMBERMATRIX_H
#define NUMBERMATRIX_H

#include <string>
#include "NumberList.h"
using namespace std;

struct cell {
    int row;
    int column;
    int value;
};

struct NumberMatrix {
    
    int columnSize[100];
    int rowSize;
    NumberList rows[100];

    NumberMatrix() {
        for (int i = 0; i < 100; i++) {
            columnSize[i] = 0;
        }
        rowSize = 0;
    }

    void addRow(NumberList row) {
        rows[rowSize] = row;
        columnSize[rowSize] = row.size;
        rowSize++;
    }

    void removeRow(int row) {
        for (int i = row; i < rowSize - 1; i++) {
            rows[i] = rows[i + 1];
            columnSize[i] = columnSize[i + 1];
        }
        rowSize--;
    }

    void remove(int row, int column) {
        rows[row].remove(column);
        columnSize[row]--;
    }

    int get(int row, int column) {
        return rows[row].get(column);

    }

    bool set(int row, int column, int number) {
        if (row < 0 || row >= rowSize) {
            return false;
        }
        
        return rows[row].set(column, number);
    }

    bool contains(int number) {
        for (int i = 0; i < rowSize; i++) {
            if (rows[i].contains(number)) {
                return true;
            }
        }
        return false;
    }

    void clear() {
        for (int i = 0; i < rowSize; i++) {
            rows[i].clear();
        }
        rowSize = 0;
    }

    NumberMatrix copy() {
        NumberMatrix other;
        for (int i = 0; i < other.rowSize; i++) {
            NumberList row = rows[i].copy();
        }
        rowSize = other.rowSize;
        return other;
    }

    cell getMinimumValueOfColumn(int column) {
        int minimum = rows[0].get(column);

        cell result;

        for (int i = 0; i < rowSize; i++) {
        
            if (rows[i].get(column) <= minimum) {
                
                minimum = rows[i].get(column);
                result.row = i;
                result.column = column;
                result.value = minimum;
                
            }
        }
        
        return result;
    }

    string toString() {
        string result = "[";
        for (int i = 0; i < rowSize; i++) {
            result += rows[i].toString();
            if (i < rowSize - 1) {
                result += ", \n";
            }
        }
        result += "]";
        return result;
    }



};

NumberMatrix generateNumberMatrixWithRandomNumbers(int rows, int columns, int min, int max) {
    NumberMatrix result;
    for (int i = 0; i < rows; i++) {
        NumberList row = generateNumberListWithRandomNumbers(columns, min, max);
        result.addRow(row);
    }
    return result;
}

#endif /* NUMBERMATRIX_H */