#include <iostream>
using namespace std;
int main() {

    float numbers [15];
    
    cout << "Input 15 numbers:" << endl;

    int lenght = 15;
    
    for(int i = 0; i < lenght; i++) {
        cin >> numbers[i];
    }

    while(lenght != 0) {

        for(int i = 1; i < 15; i++) {
            if(numbers[i - 1] > numbers[i]) {
                float temp = numbers[i - 1];
                numbers[i - 1] = numbers[i];
                numbers[i] = temp;
            }
        }
        lenght--;
    }

    cout << "***sorted array***" << endl;
    for(int i = 0; i < 15; i++) {
        cout << numbers[i] << "; " << endl;
    }
    
}

/*
Что нужно сделать
Пользователь вводит в консоль 15 дробных чисел. Необходимо прочитать их и вывести в консоль в порядке от большего к меньшему. 
По возможности используйте минимум дополнительной памяти и проходов по массиву.
*/