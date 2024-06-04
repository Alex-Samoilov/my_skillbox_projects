#include <iostream>
using namespace std;
int main() {
    int numbers[] {110, 112, 114, 111, 119, 117, 116, 112, 121, 139, 162, 135, 164, 174, 198};
    int size = sizeof(numbers)/sizeof(numbers[0]);

    int duplicate;
    
    for (int i = 0; i < size; i++) {
        for(int n = i + 1; n < size; n++) {
            if(numbers[i] == numbers[n]) {duplicate = numbers[i];}
        }
    }
    
    int min_number = numbers[0];
    for(int i = 0; i < size - 1; i++) {
        if(min_number > numbers[i + 1]) {
            min_number = numbers[i + 1];
        }
    }

    cout << "Minimum value = " << min_number << endl;
    cout << "Duplicate = " << duplicate << endl;
    
}

/*
В программе инициализирован массив из 15 целых положительных чисел. Эти числа являются множеством из 14 последовательных чисел, 
начиная с Х (Х может быть любым), а одно число из ряда повторяется. Необходимо найти повторяющееся число и вывести его в консоль. 
По возможности используйте минимум дополнительной памяти и проходов по массиву.
*/