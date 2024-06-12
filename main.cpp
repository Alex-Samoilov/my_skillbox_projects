#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector <int> vec(20);

    int element;

    cout << "Enter \"-2\" if you want to shut down the program!" << endl;
    cout << "Enter \"-1\" if you want to display the contents of the vector!" << endl;
    cout << "Enter any other value if you want to add it to the vector!" << endl;


    for(int i = 0; element != -2; i++) {
        if(i <= vec.size() - 1) {
            cout << "Input number: ";
            cin >> element;
            if(element == -2) {
                break;
            } else if (element == - 1) {
                i--;
                for (int c = 0; c < vec.size(); c++) {
                    cout << vec[c] << endl;
                }
            } else {
                vec[i] = element;
            }
        } else {
            cout << "Input number: ";
            cin >> element;
            if(element == -2) {
                break;
            } else if (element == - 1) {
                for (int c = 0; c < vec.size(); c++) {
                    cout << vec[c] << endl;
                }
            } else {
                for(int j = 0; j < vec.size(); j++) {
                vec[j] = vec[j + 1];
            }
                vec.back() = element;
            }
        }
    }
}