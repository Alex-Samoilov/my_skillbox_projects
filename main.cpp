#include <iostream>
#include <vector>
using namespace std;

void sort (vector <int> &numbers) {
    for(int i = 0; i < numbers.size(); i++) {
        for(int j = i; j < numbers.size(); j++) {
            if(numbers[i] > numbers[j]) {
                swap(numbers[i], numbers[j]);
            }
        }
    }
}

int main () {
    vector <int> numbers;

    while (true) {
        int count;
        int digit;
        cout << "Input digit: ";
        cin >> digit;
        count++;
        if (digit == -2) {
            break;
        } else if (digit == -1) {
            if(numbers.size() >= 5) {
                sort(numbers);
                cout << "The fifth highest number: " << numbers[4] << endl;
            } else {
                cout << "Not enough numbers have been entered!" << endl;
            }
        } else {
            numbers.push_back(digit);
            if(count == 5) {
                sort(numbers);
            } else if(count >= 5 && digit >= numbers[4]) {
                numbers.erase(numbers.end());
            } else if(count >= 5 && digit < numbers[4]) {
                sort(numbers);
                numbers.erase(numbers.end());
            }
        }
    } 
}


/*
С клавиатуры вводятся числа. 
Когда пользователь вводит «−1», необходимо выводить на экран пятое по возрастанию число среди введённых. 
Когда пользователь вводит «−2», программа завершает работу.
*/