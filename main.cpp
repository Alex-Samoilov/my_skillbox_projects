#include <iostream>
#include <vector>
using namespace std;

int main () {
    vector <int> vec {15, 4, -2, 4, 7, 20, 9, 6};
    int result = 18;

    int start_pos = 1;

    for (int i = 0; i < vec.size(); i++) {
        for (int j = start_pos; j < vec.size(); j++) {
            if(vec[i] + vec[j] == result) {
                cout << "digit 1 = " << vec[i] << endl;
                cout << "digit 2 = " << vec[j] << endl;
                return 0;
            }
        }
        start_pos++;
    }

}


/*
Что нужно сделать
Вам даётся массив целых чисел и одно число — результат. 
Необходимо найти в массиве два числа, сумма которых будет давать результат, и вывести их на экран. 
Гарантируется, что только одна пара чисел в массиве даёт в сумме результат.
*/