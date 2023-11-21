#include <iostream>
#include <cstdlib>
#include <ctime>
#include<Windows.h>
using namespace std;

// Функція для створення матриці із елементів цілого типу
void createMatrix(int matrix[][100], int rows, int cols) {
    srand(time(0));  // Ініціалізація генератора випадкових чисел

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = rand() % 100;  // Генеруємо випадкові значення в діапазоні 0-99
        }
    }
}

// Функція для виведення матриці на екран у вигляді таблиці
void printMatrix(int matrix[][100], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

// Функція для знаходження максимального елементу у рядку
int findMaxInRow(int matrix[][100], int row, int cols, int currentMax = 0) {
    if (cols == 0) {
        return currentMax;
    }

    if (matrix[row][cols - 1] > currentMax) {
        currentMax = matrix[row][cols - 1];
    }

    return findMaxInRow(matrix, row, cols - 1, currentMax);
}

// Функція для знаходження найменшого серед максимальних елементів по непарних рядках матриці
int findMinOfMaxOnOddRows(int matrix[][100], int rows, int cols, int currentMin = 0, int currentRow = 0) {
    if (currentRow >= rows) {
        return currentMin;
    }

    if (currentRow % 2 != 0) {  // Перевірка на непарний рядок
        int maxInRow = findMaxInRow(matrix, currentRow, cols);

        if (currentRow == 1 || maxInRow < currentMin) {
            currentMin = maxInRow;
        }
    }

    return findMinOfMaxOnOddRows(matrix, rows, cols, currentMin, currentRow + 1);
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int rows, cols;

    cout << "Введіть кількість рядків матриці (k): ";
    cin >> rows;

    cout << "Введіть кількість стовпців матриці (n): ";
    cin >> cols;

    if (rows <= 0 || cols <= 0 || rows > 100 || cols > 100) {
        cout << "Некоректні розміри матриці." << endl;
        return 1;
    }

    int matrix[100][100];

    // Створення та виведення матриці
    createMatrix(matrix, rows, cols);
    cout << "Матриця:" << endl;
    printMatrix(matrix, rows, cols);

    // Знаходження та виведення результату для непарних рядків
    int result = findMinOfMaxOnOddRows(matrix, rows, cols);
    cout << "Найменший серед максимальних елементів по непарних рядках матриці: " << result << endl;

    return 0;
}

/*#include <iostream>
#include <cstdlib>
#include <ctime>
#include<Windows.h>
using namespace std;

// Функція для створення матриці із елементів цілого типу
void createMatrix(int matrix[][100], int rows, int cols) {
    srand(time(0));  // Ініціалізація генератора випадкових чисел

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = rand() % 100;  // Генеруємо випадкові значення в діапазоні 0-99
        }
    }
}

// Функція для виведення матриці на екран у вигляді таблиці
void printMatrix(int matrix[][100], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

// Функція для знаходження максимального елементу у рядку
int findMaxInRow(int matrix[][100], int row, int cols, int currentMax = 0) {
    if (cols == 0) {
        return currentMax;
    }

    if (matrix[row][cols - 1] > currentMax) {
        currentMax = matrix[row][cols - 1];
    }

    return findMaxInRow(matrix, row, cols - 1, currentMax);
}

// Функція для знаходження найменшого серед максимальних елементів по рядках матриці
int findMinOfMaxOnRows(int matrix[][100], int rows, int cols, int currentMin = 0, int currentRow = 0) {
    if (currentRow == rows) {
        return currentMin;
    }

    int maxInRow = findMaxInRow(matrix, currentRow, cols);

    if (currentRow == 0 || maxInRow < currentMin) {
        currentMin = maxInRow;
    }

    return findMinOfMaxOnRows(matrix, rows, cols, currentMin, currentRow + 1);
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int rows, cols;

    cout << "Введіть кількість рядків матриці (k): ";
    cin >> rows;

    cout << "Введіть кількість стовпців матриці (n): ";
    cin >> cols;

    if (rows <= 0 || cols <= 0 || rows > 100 || cols > 100) {
        cout << "Некоректні розміри матриці." << endl;
        return 1;
    }

    int matrix[100][100];

    // Створення та виведення матриці
    createMatrix(matrix, rows, cols);
    cout << "Матриця:" << endl;
    printMatrix(matrix, rows, cols);

    // Знаходження та виведення результату
    int result = findMinOfMaxOnRows(matrix, rows, cols);
    cout << "Найменший серед максимальних елементів по рядках матриці: " << result << endl;

    return 0;
}*/
