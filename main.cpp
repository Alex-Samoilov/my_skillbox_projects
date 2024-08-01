#include <iostream>
using namespace std;

void initial_wrapper (bool wrapper[12][12]){
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            wrapper[i][j] = true;
        }
    }
}

void print_wrapper (bool wrapper [12][12]) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            if (!wrapper[i][j]) {
                cout << "  X  ";
            } else {
                cout << "  o  ";
            }
        } cout << "\n";
    }
    
}

void pop_wrapper (bool wrapper[12][12]) {
    int row_1, col_1, row_2, col_2;
    cout << "Input coordinates left corner!\n";
        cout << "Row: ";
        cin >> row_1;
        cout << "Col: ";
        cin >> col_1;
        cout << "Input coordinates right corner!\n";
        cout << "Row: ";
        cin >> row_2;
        cout << "Col: ";
        cin >> col_2;
    while (row_1 < 0 || row_1 >= 12 || col_1 < 0 || col_1 >= 12 || 
           row_2 < 0 || row_2 >= 12 || col_2 < 0 || col_2 >= 12 || 
           row_1 > row_2 || col_1 > col_2) {
        cout << "Incorrect coordinates!\n";
        cout << "Input coordinates left corner!\n";
        cout << "Row: ";
        cin >> row_1;
        cout << "Col: ";
        cin >> col_1;
        cout << "Input coordinates right corner!\n";
        cout << "Row: ";
        cin >> row_2;
        cout << "Col: ";
        cin >> col_2;
    }
    for (int i = row_1; i <= row_2; i++) {
        for (int j = col_1; j <= col_2; j++) {
            wrapper[i][j] = false;
            cout << "Pop!" << endl;
        }
    }
}

int main () {

    bool wrapper[12][12];
    initial_wrapper(wrapper);
    print_wrapper(wrapper);
    
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            if(wrapper[i][j] == false) {
                continue;
            } else {
                pop_wrapper (wrapper);
                print_wrapper(wrapper);
            }
        } 
    }
}

/*
После посылки из Китая осталась спецплёнка для бережной перевозки груза — пупырка. 
Всего в пупырке 12 на 12 шариков-пузырьков. Состояние любого пузырька: он либо целый, либо нет, то есть true или false (тип массива — bool). 
Для начала требуется реализовать отдельную функцию инициализации пупырки начальным состоянием: полностью целая пупырка, все элементы true.

Программа заключается в последовательном лопании целых регионов пузырьков. 
Перед каждым таким лопанием надо показывать пользователю полностью всю плёнку: o — это целый пузырёк, x — лопнутый. 
Это тоже надо выделить в отдельную функцию. Итак, как выглядит само лопание. Пользователь вводит две координаты: начала региона и конца региона. 
Процедура лопания пузырей должна быть реализована с помощью отдельной функции, все аргументы должны проверяться на валидность, 
что они в в рамках диапазона возможных значений, иначе должна быть выведена ошибка. 
После лопания каждого пузыря, который не был ещё лопнут до того, в консоль должно выводиться сообщение “Pop!”.

Лопание должно продолжаться до последнего пузырька. Как только вся пупырка потрачена, программа заканчивает выполнение. 
Вы можете подсчитать окончание в самой функции по отображению пузырьков плёнки, так как функция выполняется после каждого лопания.

Советы и рекомендации
Обратите внимание, что лопание пузырей делается с помощью региона, а не одной точки.
Регион задаётся двумя координатами, это координаты углов прямоугольника.
При лопании региона достаточно запустить цикл только по этим элементам. Не нужно проходить каждый раз по всей матрице.
Всю область плёнки удобно представить в виде двумерного массива типа bool.
Инициализировать вручную такой массив сложно, лучше воспользоваться вложенными циклами.
Для проверки на целостность одной ячейки (если вы используете тип bool) можно не сравнивать её с истиной, а указать в условии имя переменной.
*/
