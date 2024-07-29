#include <iostream>
#include <vector>
using namespace std;

bool comparison (int matrix_1[4][4], int matrix_2[4][4], bool &equally) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (matrix_1[i][j] != matrix_2[i][j]) {
                equally = false;
                return equally;
            }
        }
    } return equally;
}

int main () {
    cout << "Input matrix_1" << endl;
    int matrix_1 [4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> matrix_1[i][j];
        }
    }
    
    cout << "Input matrix_2" << endl;
    int matrix_2 [4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> matrix_2[i][j];
        }
    }

    bool equally = true;

    comparison(matrix_1, matrix_2, equally);

    if (equally == false) {
        cout << "The matrices are not equal" << endl;
    } else {
        for (int i =0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (i != j) {
                    matrix_1[i][j] = 0;
                }
                cout << matrix_1[i][j];
            }
            cout << "\n";
        }
    }

}

/*
Задание 3. Матрицы
Требуется реализовать небольшую программу для сравнения двух двумерных матриц размером 4 × 4 на предмет их полного равенства. 
Если матрицы равны друг другу, необходимо взять одну из матриц и привести её к диагональному виду. 
Программа принимает на вход две целочисленные матрицы A и B, которые вводятся с помощью std::cin, и сравнивает их на предмет полного равенства. 
Если матрицы равны, то об этом сообщается в стандартном выводе. Алгоритм должен быть по возможности оптимальным и не проводить лишних операций. 
Если матрицы не равны, выводится соответствующее сообщение и выполнение программы прекращается. 
Если матрицы равны, то из них выбирается одна и преобразуется в диагональную. 
Конвертация в диагональную форму делается путём простейшего зануления всех элементов, лежащих вне главной диагонали. 
Напомню, что диагональная матрица — это такая матрица, у которой все элементы вне диагонали равны нулю. 
Диагональ матрицы, в свою очередь, — это все элементы, расположенные по диагонали от первого элемента первой строки до последнего элемента последней строки. 
Итоговую диагональную матрицу можно расположить на месте прежней матрицы, не используя дополнительных переменных. 
Результат преобразования требуется вывести в консоль для проверки. Ищите именно оптимальное решение, оно довольно простое.

Советы и рекомендации
Чтобы не производить лишних вычислений, стоит при первом же расхождении значений в соответствующих ячейках завершить алгоритм.
Если хотя бы один элемент матриц не совпадает, можно сразу останавливать проверку.
Чтобы в результате получить диагональную матрицу, достаточно пройти по каждому элементу массива и занулить его, если строка не равна столбцу.
Достаточно привести матрицу к диагональному виду. Делать алгоритмическое преобразование не нужно.
Сравнение матриц и приведение матрицы к диагональному виду лучше оформить в виде отдельных функций.
*/