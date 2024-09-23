#include<iostream>
#include<sstream>
using namespace std;

double calc (double first_value, double second_value, char operation) {
        if (operation == '+') {return first_value + second_value;}
        if (operation == '-') {return first_value - second_value;}
        if (operation == '*') {return first_value * second_value;}
        if (operation == '/') {return first_value / second_value;}
        return 0;
    }

int main () {
    string example;
    cout << "Input example: ";
    cin >> example;
    stringstream expression (example);
    double first_value, second_value;
    char operation;
    expression >> first_value >> operation >> second_value;
    cout << calc(first_value, second_value, operation);
}

/*
Создайте небольшую программу для вычисления простых действий с числами. 
При запуске программа ожидает пользовательского ввода во временную переменную строку. 
После ввода строки она распарсивается на отдельные члены. Строка записывается в форме “<число-1><действие><число-2>” (без пробелов). 
Оба числа — это значения с плавающей точкой, повышенной точности (double). 
Действие может быть одним из: +, −, /, *. Результат действия выводится в стандартный вывод cout.
*/