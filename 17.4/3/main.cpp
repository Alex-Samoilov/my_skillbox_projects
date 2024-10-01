#include <iostream>
using namespace std;

bool substring(const char* str_1, const char* str_2) {
    for (int i = 0; *(str_1 + i) != '\0'; i++) {
        if (*(str_2 + 1) == '\0' && *(str_2) == *(str_1 + i)) {
            return true;
        }
        if (*(str_2) == *(str_1 + i)) {
            for (int j = 0; *(str_2 + j) != '\0'; j++) {
                int count = i + j;
                if (*(str_1 + count) != '\0') { 
                    if (*(str_2 + j) != *(str_1 + count)) {
                        continue;
                    } else {
                        if (*(str_2 + j + 1) == '\0' ) {return true;}
                    }
                } else {return false;}
            } 
        }
    } return false;
}

int main () {
    const char* str_1 = "banana";
    const char* str_2 = "anana";
    if (substring(str_1, str_2) == true ? cout << "true" : cout << "false");

}


/*
Напишите функцию, принимающую два указателя на char*, по которым размещены две строки.
Функция должна возвращать true, если вторая строка является подстрокой первой.




bool substring(char* str_1, char* str_2) {
    for (int i = 0; *(str_1 + i) != '\0'; i++) {
        if (*(str_2) == *(str_1 + i) && *(str_2 + 1) == *(str_1 + i + 1)) {
            return true;
        }
    } return false;
}
*/