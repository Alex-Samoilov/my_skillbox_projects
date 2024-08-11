#include <iostream>
#include <vector>
using namespace std;

int main () {
    vector <int> arr = {-100, -50, -5, 1, 10, 15};

    for(int i = 0; i < arr.size(); i++) {
        bool sort = true;
        for(int j = 0; j < arr.size() - (i + 1); j++) {
            if(abs(arr[j]) > abs(arr[j + 1])) {
                swap(arr[j], arr[j + 1]);
            } else {
                sort = false;
                break;
            }
        }
    }

  for(int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }

}


/*
Вам даётся массив целых чисел, отсортированных по возрастанию. 
Необходимо вывести его на экран отсортированным в порядке возрастания модуля чисел.
*/