#include <iostream>
#include <vector>
using namespace std;

void swapvec (vector <int> &arr_1, int* indicatorArr_2) {
    int temp;
    for (int i = 0; i < size(arr_1); i++) {
        temp = arr_1[i];
        arr_1[i] = *(indicatorArr_2 + i);
        *(indicatorArr_2 + i) = temp;
    }
}

int main () {
    vector <int> arr_1 {2, 4, 6, 8, 10};
    int arr_2 []   =   {1, 3, 5, 7, 9};
    int* indicatorArr_2 = arr_2;

    swapvec(arr_1, indicatorArr_2);
    for (int i = 0; i < size(arr_1); i++) {
        cout << arr_1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < size(arr_1); i++) {
        cout << *(indicatorArr_2 + i) << " ";
    }
}


/*
Напишите функцию swapvec, принимающую std::vector<int> и указатель на массив переменных типа int (одного размера) и обменивающую значения этих массивов.
swapvec(arr_1, indicatorArr_2);
*/