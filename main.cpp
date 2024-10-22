#include <iostream>
using namespace std;

void evendigit(long long number, int &ans) {
  if (number / 10 != 0) {
    if (number % 2 == 0) {++ans;}
    evendigit(number / 10, ans);
  }  
}

int main() {
  cout << "Even Digits!\n";
  long long number;
  int ans = 0;
  cout << "Input number: ";
  cin >> number;
  evendigit(number,ans);
  cout << "Number of event digits " << ans << endl;
}

/*
Напишите рекурсивную функцию, которая принимает большое число n типа long long и переменную ans, а возвращает void. 
После завершения работы функции в переменной ans должно оказаться количество чётных цифр в записи числа n. 
*/