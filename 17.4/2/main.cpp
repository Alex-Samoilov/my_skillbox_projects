#include <iostream>
using namespace std;

void reverse(int* arr) {

    int temp, count = 0;
    for (int i = 9; i > 4; i-- ) { 
        temp = *(arr + count);
        *(arr + count) = *(arr + i);   
        *(arr + i) = temp;
        count++;
    }
}

int main () {
    int array [10] =  {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int* arr = array;

    reverse(arr);
    for(int i = 0; i < 10; i++) {
        cout << *(arr + i) << endl;
    }
}

/*
Напишите функцию, принимающую указатель на тип int, по которому размещены десять переменных типа int. 
Функция ничего не возвращает, но по тому же указателю элементы должны располагаться в обратном порядке.



#include <iostream>
using namespace std;

void reverse(int* arr, int count = 0) {
    int* arr_2 = arr;

    for (int i = 9; i > 4; i-- ) { 
        *(arr + count) = *(arr + i);   
        count++;
    }
    for (int i = 4; i > 0 ; i --) {
        *(arr + count) = *(arr_2 + i);   
        count++;
    } 
}

int main () {
    int array [10] =  {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int* arr = array;
    
    int count = 0;
    int arr_2 [10] = array;

    for (int i = 9; i > 4; i-- ) { 
        *(arr + count) = *(arr + i);   
        count++;
    }
    for (int i = 4; i > 0 ; i --) {
        *(arr + count) = *(arr_2 + i);   
        count++;
    } 

    for(int i = 0; i < 10; i++) {
        cout << *(arr + i) << endl;
    }
}
*/