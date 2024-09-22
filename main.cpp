#include <iostream>
using namespace std;
int main () {
    string digit_1, digit_2, txt_result;
    cout << "Input digit 1: ";
    cin >> digit_1;
    cout << "Input digit 2: ";   
    cin >> digit_2;
    digit_1.push_back('.');
    txt_result = digit_1 + digit_2;
    double result = stof(txt_result);
    cout << result;


}


/*
Из целой и дробной частей числа, которые в отдельности вводит пользователь, 
составьте новое число с плавающей точкой (типа double) и выведите это число обратно в консоль для проверки. 
Целая часть — это часть числа, которая находится до точки (запятой), дробная — после.
*/