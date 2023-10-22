#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int MAX_SIZE = 100;

// Function prototypes
void readMatrix(ifstream &file, int matrix[][MAX_SIZE], int n);
void printMatrix(const int matrix[][MAX_SIZE], int n);
void addMatrices(const int matrix1[][MAX_SIZE], const int matrix2[][MAX_SIZE], int result[][MAX_SIZE], int n);
void subtractMatrices(const int matrix1[][MAX_SIZE], const int matrix2[][MAX_SIZE], int result[][MAX_SIZE], int n);
void multiplyMatrices(const int matrix1[][MAX_SIZE], const int matrix2[][MAX_SIZE], int result[][MAX_SIZE], int n);

int main() {
    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE], matrixSum[MAX_SIZE][MAX_SIZE], matrixDifference[MAX_SIZE][MAX_SIZE], matrixProduct[MAX_SIZE][MAX_SIZE];
    int n;

    ifstream file("matrix_input.txt");
    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    file >> n;

    readMatrix(file, matrixA, n);
    readMatrix(file, matrixB, n);
    
    file.close();

    cout << "Will Whitehead" << endl;
    cout << "Lab #6: Matrix manipulation" << endl << endl;

    cout << "Matrix A:" << endl;
    printMatrix(matrixA, n);

    cout << "\nMatrix B:" << endl;
    printMatrix(matrixB, n);

    addMatrices(matrixA, matrixB, matrixSum, n);
    cout << "\nMatrix Sum (A + B):" << endl;
    printMatrix(matrixSum, n);

    multiplyMatrices(matrixA, matrixB, matrixProduct, n);
    cout << "\nMatrix Product (A * B):" << endl;
    printMatrix(matrixProduct, n);

    subtractMatrices(matrixA, matrixB, matrixDifference, n);
    cout << "\nMatrix Difference (A - B):" << endl;
    printMatrix(matrixDifference, n);

    return 0;
}

// Function bodies

void readMatrix(ifstream &file, int matrix[][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            file >> matrix[i][j];
        }
    }
}

void printMatrix(const int matrix[][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(5) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void addMatrices(const int matrix1[][MAX_SIZE], const int matrix2[][MAX_SIZE], int result[][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtractMatrices(const int matrix1[][MAX_SIZE], const int matrix2[][MAX_SIZE], int result[][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void multiplyMatrices(const int matrix1[][MAX_SIZE], const int matrix2[][MAX_SIZE], int result[][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}
