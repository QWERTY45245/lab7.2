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

// ������� ��� ����������� ���������� ����� ������������ �������� �� �������� ������ �������
int findMinOfMaxOnOddRows(int matrix[][100], int rows, int cols) {
    int minOfMax = matrix[1][0];  // ��������� �������� - ������ ������� �������

    for (int i = 1; i < rows; i += 2) {  // ����������� ����� ������ �����
        int maxInRow = matrix[i][0];  // ��������� �������� - ������ ������� �����

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
/*#include<Windows.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// ������� ��� ��������� ������� 
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

// ������� ��� ����������� ���������� ����� ������������ �������� �� ������ ������ �������
int findMinOfMaxOnEvenRows(int matrix[][100], int rows, int cols) {
    int minOfMax = matrix[0][0];  // ��������� �������� - ������ ������� �������

    for (int i = 0; i < rows; i += 2) {  // ����������� ����� ���� �����
        int maxInRow = matrix[i][0];  // ��������� �������� - ������ ������� �����

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
    int result = findMinOfMaxOnEvenRows(matrix, rows, cols);
    cout << "��������� ����� ������������ �������� �� ������ ������ �������: " << result << endl;

    return 0;
}*/

 