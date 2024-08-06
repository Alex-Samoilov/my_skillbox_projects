#include <iostream>
#include <vector>
using namespace std;

int main () {
    vector <int> vec {-2, 1, -3, 4, -1 ,2 ,1 ,-5 ,4};
    
    int max_sum = 0;
    int start_pos = 0;
    int start_index = 0;
    int end_index = 0;

    for (int i = 0; i < vec.size(); i++) {
        int temporary_result = 0;
        for (int j = start_pos; j < vec.size(); j++) {
            temporary_result += vec[j];
            if(temporary_result > max_sum) {
                max_sum = temporary_result;
                start_index = start_pos;
                end_index = j;
            }
        }
        start_pos++;
    }

    cout << "start_index = " << start_index << endl;
    cout << "end_index = " << end_index << endl;
}


/*
Что нужно сделать
Вам даётся массив целых чисел. 
Необходимо найти в массиве такие два индекса i и j, что сумма a[i], a[i+1], a[i+2], …, a[j] будет максимально возможной, и вывести их.

Пример
a = {−2, 1, −3, 4, −1 ,2 ,1 ,−5 ,4}

Наибольшая сумма последовательных элементов находится между индексами 3 и 6: {4, −1 ,2 ,1}, сумма = 6. Необходимо вывести 3 и 6.
*/