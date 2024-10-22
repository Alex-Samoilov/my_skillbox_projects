#include <iostream>
using namespace std;

int rabbit (int number_step, int step_length = 3) {
  int wc = 0;
  if (number_step == 0) {
    return wc;
  } else
    for (int i = 1; i <= min(number_step, step_length); i++) {
        if (number_step - i == 0) {wc++;} 
else {wc += rabbit(number_step - i);
  } }
    return wc;
  }

int main() {

  int number_step = 0;
  int step_length = 0;
  int wayscount = 0;
  cout << "Input number of steps: ";
  cin >> number_step;
  cout << "Input step length: ";
  cin >> step_length;
  cout << "Number of ways: " << rabbit(number_step, step_length);

  }


 /*
Что нужно сделать
Кролик сидит на нулевой ступеньке большой лестницы. Он может прыгать на одну или более ступенек вверх, но не далее чем на k. 
Кролик хочет допрыгать до n-й ступеньки, но может сделать это большим количеством способов. 

Напишите рекурсивную функцию, которая принимает число n типа int и число k — максимальную длину прыжка, а возвращает количество способов, 
которым кролик может доскакать до n-й ступеньки. В функции для аргумента “максимальная длина прыжка” задать значение, по умолчанию равное 3.
 
 */