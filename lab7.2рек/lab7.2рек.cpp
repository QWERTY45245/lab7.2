#include <iostream>
#include <cstdlib>
#include <ctime>
#include<Windows.h>
using namespace std;

// ������� ��� ��������� ������� �� �������� ������ ����
void createMatrix(int matrix[][100], int rows, int cols) {
    srand(time(0));  // ����������� ���������� ���������� �����

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = rand() % 100;  // �������� �������� �������� � ������� 0-99
        }
    }
}

// ������� ��� ��������� ������� �� ����� � ������ �������
void printMatrix(int matrix[][100], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

// ������� ��� ����������� ������������� �������� � �����
int findMaxInRow(int matrix[][100], int row, int cols, int currentMax = 0) {
    if (cols == 0) {
        return currentMax;
    }

    if (matrix[row][cols - 1] > currentMax) {
        currentMax = matrix[row][cols - 1];
    }

    return findMaxInRow(matrix, row, cols - 1, currentMax);
}

// ������� ��� ����������� ���������� ����� ������������ �������� �� �������� ������ �������
int findMinOfMaxOnOddRows(int matrix[][100], int rows, int cols, int currentMin = 0, int currentRow = 0) {
    if (currentRow >= rows) {
        return currentMin;
    }

    if (currentRow % 2 != 0) {  // �������� �� �������� �����
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

    cout << "������ ������� ����� ������� (k): ";
    cin >> rows;

    cout << "������ ������� �������� ������� (n): ";
    cin >> cols;

    if (rows <= 0 || cols <= 0 || rows > 100 || cols > 100) {
        cout << "��������� ������ �������." << endl;
        return 1;
    }

    int matrix[100][100];

    // ��������� �� ��������� �������
    createMatrix(matrix, rows, cols);
    cout << "�������:" << endl;
    printMatrix(matrix, rows, cols);

    // ����������� �� ��������� ���������� ��� �������� �����
    int result = findMinOfMaxOnOddRows(matrix, rows, cols);
    cout << "��������� ����� ������������ �������� �� �������� ������ �������: " << result << endl;

    return 0;
}

/*#include <iostream>
#include <cstdlib>
#include <ctime>
#include<Windows.h>
using namespace std;

// ������� ��� ��������� ������� �� �������� ������ ����
void createMatrix(int matrix[][100], int rows, int cols) {
    srand(time(0));  // ����������� ���������� ���������� �����

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = rand() % 100;  // �������� �������� �������� � ������� 0-99
        }
    }
}

// ������� ��� ��������� ������� �� ����� � ������ �������
void printMatrix(int matrix[][100], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

// ������� ��� ����������� ������������� �������� � �����
int findMaxInRow(int matrix[][100], int row, int cols, int currentMax = 0) {
    if (cols == 0) {
        return currentMax;
    }

    if (matrix[row][cols - 1] > currentMax) {
        currentMax = matrix[row][cols - 1];
    }

    return findMaxInRow(matrix, row, cols - 1, currentMax);
}

// ������� ��� ����������� ���������� ����� ������������ �������� �� ������ �������
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

    cout << "������ ������� ����� ������� (k): ";
    cin >> rows;

    cout << "������ ������� �������� ������� (n): ";
    cin >> cols;

    if (rows <= 0 || cols <= 0 || rows > 100 || cols > 100) {
        cout << "��������� ������ �������." << endl;
        return 1;
    }

    int matrix[100][100];

    // ��������� �� ��������� �������
    createMatrix(matrix, rows, cols);
    cout << "�������:" << endl;
    printMatrix(matrix, rows, cols);

    // ����������� �� ��������� ����������
    int result = findMinOfMaxOnRows(matrix, rows, cols);
    cout << "��������� ����� ������������ �������� �� ������ �������: " << result << endl;

    return 0;
}*/
