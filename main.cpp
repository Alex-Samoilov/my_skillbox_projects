#include <iostream>
#include <vector>
using namespace std;

vector <int> del_last(vector <int> vec, int pos) {
    for (; pos < vec.size(); pos++) {
        vec[pos] = vec[pos+1];
        }
        vec.pop_back();
        return vec;
}

int main() {

    cout << "Enter quantity of values: ";
    int quantity;
    cin >> quantity;
    vector <int> vec (quantity);

    int pos = 0;

    for (int i=0; i<vec.size(); i++) {
        cout << "Element #" << i+1 << ": ";
        cin >> vec[i];
    }

    cout << "Enter the number you want to delete: ";
    int delete_Num;
    cin >> delete_Num;

    for(; pos < vec.size();) {
        if(vec[pos] != delete_Num) {
            pos++;
            continue;
        }
        vec = del_last(vec, pos);
    }

    for (int i=0; i < vec.size(); i++) {
        cout << vec[i];
    }
   

}

/*
Необходимо из заданного пользователем вектора удалить число X.

Как работает программа
Пользователь вводит с клавиатуры число n — размер вектора, который надо заполнять.
Пользователь вводит n целых чисел, которые заполняют вектор.
Пользователь вводит значение — X. X — удаляемое из вектора значение. Необходимо удалить из вектора все элементы, которые равны заданному значению.
В конце программы необходимо вывести итоговое состояние вектора.
*/