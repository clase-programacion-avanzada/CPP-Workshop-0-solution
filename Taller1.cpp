#include <iostream>
#include "libs/NumberList.h"
#include "libs/NumberMatrix.h"

using namespace std;

void printMenu();
void printNumberList(NumberList numberList);
void printNumberMatrix(NumberMatrix numberMatrix);
void printMinimumValuesOfEachColumn(NumberMatrix numberMatrix);
NumberList generateNumberListWithRandomNumbersAndPrintResult(int size, int min, int max);
NumberList getNumberListWithoutRepetitionsAndPrintResult(NumberList numberList);
NumberList getNumberListWithNumberOfRepetitionsAndPrintResult(NumberList numberLists);
NumberMatrix generateNumberMatrixWithRandomNumbersAndPrintResult(int rowSize, int columnSize, int min, int max);

int main() {
    /*En este taller es obligatorio el uso de estructuras y funciones. 
    Debe usar headers para evitar que el código se vea muy extenso, y no puede usar cin o cout en ninguna parte del código que no sea el archivo main.cpp.
    
    Se recomienda que use la estructura NumberList para el desarrollo de este taller.
    
    */
    
    int option = 0;
    NumberList numberList;
    NumberList numberListWithoutRepetitions;
    NumberList numberListWithNumberOfRepetitions;

    NumberMatrix numberMatrix;
    do {
        printMenu();
        cin >> option;
        
        switch (option) {
            case 1:
                numberList = generateNumberListWithRandomNumbersAndPrintResult(20, 1, 10);
                break;
            case 2:
                if (numberList.size == 0) {
                    cout << "Debe generar la lista de números primero" << endl;
                    break;
                }
                numberListWithoutRepetitions = getNumberListWithoutRepetitionsAndPrintResult(numberList);
                break;
            case 3:
                numberListWithNumberOfRepetitions = 
                    getNumberListWithNumberOfRepetitionsAndPrintResult(numberList); 
                break;
            case 4:
                numberMatrix = generateNumberMatrixWithRandomNumbersAndPrintResult(5, 5, 1, 10);
                break;
            case 5:
                if (numberMatrix.rowSize == 0) {
                    cout << "Debe generar la matriz primero" << endl;
                    break;
                }
                printMinimumValuesOfEachColumn(numberMatrix);
                break;
            case 6:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción inválida" << endl;
                break;  
        }
    } while (option != 6);
    


    return 0;
}

void printMenu() {
    cout << "1. Crear e imprimir una lista de números enteros de 20 elementos." << endl;
    cout << "2. Crear e imprimir una lista de números sin repetir." << endl;
    cout << "3. Crear e imprimir una lista de números con el número de veces que aparece el número en la lista del punto 1." << endl;
    cout << "4. Generar una matriz de 5x5 con números aleatorios" << endl;
    cout << "5. Generar una función que imprima los valores mímimos de cada columna, indicando el número de la columna y el valor mínimo." << endl;
    cout << "6. Salir" << endl;
    cout << "Ingrese una opción: ";
}

void printNumberList(NumberList numberList) {
    cout << numberList.toString() << endl;
}

void printNumberMatrix(NumberMatrix numberMatrix) {
    cout << numberMatrix.toString() << endl;
}

/*
1. Crear e imprimir una lista de números enteros de 20 elementos.
        Los números deben ser generados de forma aleatoria entre 1 y 10. (0.5)
        i.e: 
            [4,7,2,1,5,3,2,1,9,10,2,3,4,5,6,7,8,9,10,1]*/

NumberList generateNumberListWithRandomNumbersAndPrintResult(int size, int min, int max) {
    NumberList result = generateNumberListWithRandomNumbers(size, min, max);
    cout << "Lista de números generada: ";
    printNumberList(result);
    return result;
}
/*2. Crear e imprimir una lista de números donde se guardarán los números del 
        punto anterior una sola vez, es decir, sin repetir ningún número y en el 
        órden de aparición. (1.0)
        i.e: 
            [4,7,2,1,5,3,9,10,6,8]*/
NumberList getNumberListWithoutRepetitionsAndPrintResult(NumberList numberList) {
    NumberList result = getNumberListWithoutRepetitions(numberList);
    cout << "Lista de números sin repeticiones: ";
    printNumberList(result);
    return result;
}
/*3. Crear e imprimir una lista de números donde se guarda en cada posición el 
        número de veces que aparece el número en la lista del punto 1. (1.0)
        i.e: 
            [2,2,3,3,2,2,2,2,1,1]*/

NumberList getNumberListWithNumberOfRepetitionsAndPrintResult(NumberList numberList) {
    NumberList result = getNumberListWithNumberOfRepetitions(numberList);
    cout << "Lista de números con el número de veces que aparece el número en la lista del punto 1: ";
    printNumberList(result);
    return result;
}
/*4. Haciendo uso de la estructura NumberMatrix, generar números aleatorios del 1 al 10, 
        guardarlos en una matriz de 5x5 e imprimirla. (1.0)
        i.e: 
            [4,7,2,1,5
             3,2,1,9,10
             2,3,4,5,6
             7,8,9,10,1
             1,2,3,4,5] */

NumberMatrix generateNumberMatrixWithRandomNumbersAndPrintResult(int rowSize, int columnSize, int min, int max) {
    NumberMatrix result = generateNumberMatrixWithRandomNumbers(rowSize, columnSize, min, max);
    cout << "Matriz generada: " << endl;
    printNumberMatrix(result);
    return result;
}

/*5. Generar una función que imprima los valores mímimos de cada columna, indicando 
        el número de la columna y el valor mínimo. (1.0)
        i.e: 
            fila columna valor
            4    0       1
            4    1       2
            1    2       1
            0    3       1
            3    4       1
*/
void printMinimumValuesOfEachColumn(NumberMatrix numberMatrix) {
    cout << "Fila    Columna    Valor" << endl;
    for (int i = 0; i < numberMatrix.columnSize[0]; i++) {
        cell minimumValueOfColumn = numberMatrix.getMinimumValueOfColumn(i);
        cout << minimumValueOfColumn.row << "    " << minimumValueOfColumn.column << "       " << minimumValueOfColumn.value << endl;
    }
}
