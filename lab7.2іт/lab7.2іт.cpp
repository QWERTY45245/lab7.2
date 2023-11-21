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

// Функція для знаходження найменшого серед максимальних елементів по непарних рядках матриці
int findMinOfMaxOnOddRows(int matrix[][100], int rows, int cols) {
    int minOfMax = matrix[1][0];  // Початкове значення - другий елемент матриці

    for (int i = 1; i < rows; i += 2) {  // Переглядаємо тільки непарні рядки
        int maxInRow = matrix[i][0];  // Початкове значення - перший елемент рядка

        for (int j = 1; j < cols; ++j) {
            if (matrix[i][j] > maxInRow) {
                maxInRow = matrix[i][j];
            }
        }

        if (i == 1 || maxInRow < minOfMax) {
            minOfMax = maxInRow;
        }
    }

    return minOfMax;
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
/*#include<Windows.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Функція для створення матриці 
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

// Функція для знаходження найменшого серед максимальних елементів по парних рядках матриці
int findMinOfMaxOnEvenRows(int matrix[][100], int rows, int cols) {
    int minOfMax = matrix[0][0];  // Початкове значення - перший елемент матриці

    for (int i = 0; i < rows; i += 2) {  // Переглядаємо тільки парні рядки
        int maxInRow = matrix[i][0];  // Початкове значення - перший елемент рядка

        for (int j = 1; j < cols; ++j) {
            if (matrix[i][j] > maxInRow) {
                maxInRow = matrix[i][j];
            }
        }

        if (i == 0 || maxInRow < minOfMax) {
            minOfMax = maxInRow;
        }
    }

    return minOfMax;
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
    int result = findMinOfMaxOnEvenRows(matrix, rows, cols);
    cout << "Найменший серед максимальних елементів по парних рядках матриці: " << result << endl;

    return 0;
}*/

 