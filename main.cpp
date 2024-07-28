#include <iostream>
#include <vector>
using namespace std;

void print_field (char field[3][3]) {
    for (int i=0; i<3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "|";
            cout << field[i][j];
        }
        cout << "|";
        cout << endl;
    }

}

int result_game (char field [3][3]) {
    
    for (int i = 0; i < 3; i++) {
        if (field[i][0] == field[i][1] && field[i][1] == field[i][2] && field[i][0] != '-') {
            if (field[i][0] == 'X') {
                cout << "Result game:\nPlayer 2 - Won\n";
            } else {
                cout << "Result game:\nPlayer 1 - Won\n";
            }
            return 0; 
        }
        if (field[0][i] == field[1][i] && field[1][i] == field[2][i] && field[0][i] != '-') {
            if (field[0][i] == 'X') {
                cout << "Result game:\nPlayer 2 - Won\n";
            } else {
                cout << "Result game:\nPlayer 1 - Won\n";
            }
            return 0;
        }
    }

    if ((field[0][0] == field[1][1] && field[1][1] == field[2][2] && field[0][0] != '-') || 
        (field[0][2] == field[1][1] && field[1][1] == field[2][0] && field[0][2] != '-')) {
        if (field[1][1] == 'X') {
            cout << "Result game:\nPlayer 2 - Won\n";
        } else {
            cout << "Result game:\nPlayer 1 - Won\n";
        }
        return 0; 
    }
  
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (field[i][j] == '-') {
                return 1; 
            }
        }
    }
    cout << "Result game:\nDraw\n";
    return 0;
}

int main () {

    int row, column;

    char field [3][3];
    for (int i=0; i<3; i++) {
        for (int j = 0; j < 3; j++) {
            field[i][j] = '-';
        }
    }

    print_field(field);

    for (int count = 1; count < 10; count++) {
        if (count % 2 == 0) {
            cout << "Turn player 2\n";
        } else {
            cout << "Turn player 1\n";
        }
        cout << "Enter the coordinates!\nRow number: ";
        cin >> row;
        cout << "Column number: ";
        cin >> column;
        do {
            if (row < 4 && row > 0 && column < 4 && column > 0) {
                if (count % 2 == 0) {
                    if (field[row - 1][column - 1] == '-') {
                        field[row - 1][column - 1] = 'X';
                    } else {
                        while (field[row - 1][column - 1] != '-') {
                            cout << "Coordinates are already use\n";
                            cout << "Enter the coordinates!\nRow number: ";
                            cin >> row;
                            cout << "Column number: ";
                            cin >> column;
                        } field[row - 1][column - 1] = 'X';
                    }
                } else {
                    if (field[row - 1][column - 1] == '-') {
                        field[row - 1][column - 1] = 'O';
                    } else {
                        while (field[row - 1][column - 1] != '-') {
                            cout << "Coordinates are already use\n";
                            cout << "Enter the coordinates!\nRow number: ";
                            cin >> row;
                            cout << "Column number: ";
                            cin >> column;
                        } field[row - 1][column - 1] = 'O';
                    }
                }
            } else {
                while (row > 3 || row < 1 || column > 3 || column < 1) {
                    cout << "Incorrect coordinates!" << endl;
                    cout << "Enter the coordinates!\nRow number: ";
                    cin >> row;
                    cout << "Column number: ";
                    cin >> column; 
                    break;
                } 
                if (count % 2 == 0) {
                    field[row - 1][column - 1] = 'X';
                } else {
                    field[row - 1][column - 1] = 'O';
                }
            }
        } while (row > 3 || row < 1 || column > 3 || column < 1);

        print_field(field);
        if (result_game(field) == 0) {
            break;
        }
    }
}

/*
Что нужно сделать
Старая добрая игра на страницах всех школьных тетрадей. Поле размером 3 × 3 представлено в виде двумерного массива с типом элементов char. 
Участвуют два игрока, они ходят по очереди и ставят в указанные ими в стандартном вводе координаты свой символ — X или O (буквы латинского алфавита). 
Как только у одного из игроков будет установлено подряд три крестика или три нолика, он побеждает. 
Если свободных клеток не осталось, а трёх совпадающих элементов не найдено, то объявляется ничья. 
Для простоты не будем рассматривать диагональные совпадения — только строго вертикальные и строго горизонтальные.

Изначально всё поле инициализируется символом пробела — ‘ ‘(для обозначения пробела кавычки одинарные и в одну сторону). 
Это можно сделать сразу при объявлении либо с помощью вложенного цикла. 
На каждом ходе при занятой клетке или при неверных координатах этой клетки должно быть выведено сообщение, и игрок должен указать координаты клетки повторно. 
После каждого хода надо выводить в консоль текущее состояние всего игрового поля для наглядности.

Советы и рекомендации
Действия для обоих игроков одинаковые, отличаются только символом, который ставится на поле.
Игровой цикл не должен быть бесконечным. Игра имеет определённое максимальное количество шагов.
Не забывайте про случай ничьей.
Как и в предыдущем задании, здесь будет удобно сразу заполнить массив значениями false. Количество мест, доступных для заполнения, заранее известно. 
В процессе заполнения из этой переменой нужно не забывать вычитать единицу. Чтобы отметить место как занятое, нужно лишь написать places[i][j] = true;.
Проверку на победу игрока, которую надо осуществлять после каждого хода, можно сделать с помощью вложенного цикла, сразу проверяя и вертикаль, и горизонталь, 
а как именно — попробуйте догадаться сами.
Здесь заранее известно число ходов — 3 * 3. Столько раз должен быть выполнен цикл, который спрашивает у очередного игрока координаты.
Символ, который будет установлен в указанных координатах, можно на каждом шаге менять подобным образом:
if (gamer_name == 'X') 
                gamer_name = 'O'; 
else 
                gamer_name = 'X';

Что оценивается
Корректный ход игры, соответствующий правилам.
Правильный (желательно красивый) вывод игрового поля.
Понятный игроку интерфейс.
*/