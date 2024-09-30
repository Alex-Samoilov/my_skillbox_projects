#include <iostream>
using namespace std;

void exchange(int* indicator_a, int* indicator_b) {
    int c = *indicator_a;
    *indicator_a = *indicator_b;
    *indicator_b = c;
}

int main () {
    int a = 10, b = 20;

    int* indicator_a = &a;
    int* indicator_b = &b;

    cout << *indicator_a << endl;
    cout << *indicator_b << endl;

    exchange(indicator_a, indicator_b);
    cout << *indicator_a << endl;
    cout << *indicator_b;
}

/*
Напишите функцию, принимающую два указателя на int и меняющую местами содержимое этих указателей.
*/