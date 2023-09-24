/*
int *ptr = (int*)malloc(sizeof(int)) = int *mas = new int[size]

free(ptr) = null (освобождаем место)
free(ptrArr) = null (освобождаем место)



*/







#include <iostream>
// Функция для построения треугольника Фибоначчи
int** buildFibonacciTriangle(int numRows) {
    int** triangle = new int* [numRows]; // Создаем динамический двумерный массив
    for (int i = 0; i < numRows; ++i) {
        triangle[i] = new int[i + 1]; // Выделяем память для каждой строки треугольника
        int* row = triangle[i]; // Указатель на текущую строку

        if (i == 0) {
            row[0] = 1; // Первая строка имеет значение 1
        }
        else if (i == 1) {
            row[0] = 1; // Вторая строка также имеет значение 1
            row[1] = 1;
        }
        else {
            int* prevRow = triangle[i - 1]; // Указатель на предыдущую строку
            row[0] = 1; // Первый элемент текущей строки равен 1

            for (int j = 1; j < i; ++j) {
                // Значение элемента равно сумме двух предыдущих элементов
                row[j] = prevRow[j - 1] + prevRow[j];
            }

            row[i] = 1; // Последний элемент текущей строки также равен 1
        }
    }

    return triangle;
}

// Функция для вывода треугольника Фибоначчи
void printFibonacciTriangle(int** triangle, int numRows) {
    for (int i = 0; i < numRows; ++i) {
        int* row = triangle[i];

        // Сдвигаем вывод вправо для визуального представления треугольника
        for (int j = 0; j < numRows - i - 1; ++j) {
            std::cout << " ";
        }

        for (int j = 0; j <= i; ++j) {
            std::cout << row[j] << " ";
        }

        std::cout << std::endl;
    }
}

// Основная функция
int main() {
    setlocale(LC_ALL, "RUS");
    int numRows;

    std::cout << "Введите количество строк треугольника Фибоначчи: ";
    std::cin >> numRows;

    int** triangle = buildFibonacciTriangle(numRows);

    std::cout << "Треугольник Фибоначчи:" << std::endl;
    printFibonacciTriangle(triangle, numRows);

    // Освобождаем память, выделенную для треугольника
    for (int i = 0; i < numRows; ++i) {
        delete[] triangle[i];
    }
    delete[] triangle;

    return 0;
}