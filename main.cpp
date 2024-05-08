#include <iostream>
#include <string>

using namespace std;

bool checking_valid(string ip_address, string first_octet, string second_octet, string third_octet, string fourth_octet, int dot_number) {

    if (ip_address.front() == '.' || ip_address.back() == '.') {return false;}

    for (int i = 0; i < ip_address.length(); i++) {
        if (ip_address[i] == '.' && ip_address [i + 1] == '.' ) { return false;}
        if (ip_address[i] == ' ') {return false;}
        if (ip_address.length() > 15 || ip_address.length() < 7) {return false;}
    }

    for (int i = 0; i < ip_address.length(); i++) {
        if (ip_address[0] == '0' && ip_address [dot_number + 1] >= '0' && ip_address [dot_number + 1] <= '9') {return false;}
        if (ip_address[i] >= '0' && ip_address[i] <= '9') {
            first_octet += ip_address[i]; continue;
        }
        if (ip_address[i] == '.') {
            dot_number = i;
            int first_octet_int = stoi(first_octet);
            if (first_octet_int <= 255 && first_octet_int >= 0) {break;}
        }
        return false;
    }

    for (int i = dot_number + 1; i < ip_address.length(); i++) {
        if (ip_address[dot_number + 1] == '0' && ip_address [dot_number + 2] >= '0' && ip_address [dot_number + 2] <= '9') {return false;}
        if (ip_address[i] >= '0' && ip_address[i] <= '9') {
            second_octet += ip_address[i]; continue;
        }
        if (ip_address[i] == '.') {
            dot_number = i;
            int second_octet_int = stoi(second_octet);
            if (second_octet_int <= 255 && second_octet_int >= 0) {break;}
        }
        return false;
    }

    for (int i = dot_number + 1; i < ip_address.length(); i++) {
        if (ip_address[dot_number + 1] == '0' && ip_address [dot_number + 2] >= '0' && ip_address [dot_number + 2] <= '9') {return false;}
        if (ip_address[i] >= '0' && ip_address[i] <= '9') {
            third_octet += ip_address[i]; 
            if (i == ip_address.length() - 1) {return false;}
            continue;
        }
        if (ip_address[i] == '.') {
            dot_number = i;
            int third_octet_int = stoi(third_octet);
            if (third_octet_int <= 255 && third_octet_int >= 0) {break;}
        }
        return false;
    }

    for (int i = dot_number + 1; i < ip_address.length(); i++) {
        if (ip_address[i] >= '0' && ip_address[i] <= '9') {
            fourth_octet += ip_address[i];
        }
        if (i < ip_address.length() - 1) {continue;}
        if (fourth_octet.length() > 1) {
        if (fourth_octet[0] == '0' && fourth_octet [1] >= '0' && fourth_octet [1] <= '9') {return false;}
        }
        if (ip_address[i] == ip_address.back()) {
            int fourth_octet_int = stoi(fourth_octet);
            if (fourth_octet_int <= 255 && fourth_octet_int >= 0) {break;}
        }
        return false;
    }
    if (second_octet.length() < 1 || third_octet.length() < 1 || fourth_octet.length() < 1) {return false;}
    return true;
}

int main() {
    cout << "Input ip - address: " ;
    string ip_address;
    cin >> ip_address;

    string first_octet = "";
    string second_octet = "";
    string third_octet = "";
    string fourth_octet = "";
    int dot_number = 0;

    
    if (checking_valid(ip_address, first_octet, second_octet, third_octet, fourth_octet, dot_number) == true) {
    cout << "Valid" << endl;
    } else {
        cout << "Invalid" << endl;
    }
}


/*
Что нужно сделать
Проверьте, задаёт ли введённая пользователем строка корректный IP-адрес четвёртой версии (IPv4). IP-адрес должен представлять из себя четыре числа, 
разделённые точками без пробелов, причём каждое число должно быть в диапазоне от 0 до 255 включительно. Числа не должны содержать ведущих нулей.
Других символов в строке, кроме вышеописанных, быть не должно.

Пользователь вводит строку, задающую IP-адрес через стандартный ввод. В результате программа должна вывести слово Valid, 
если адрес корректен, и слово Invalid, если это не так.

Примеры

Корректные: 
127.0.0.1 
255.255.255.255 
1.2.3.4 
55.77.213.101

Некорректные: 
255.256.257.258 (есть числа больше 255) 
0.55.33.22. (лишняя точка в конце) 
10.00.000.0 (лишние нули) 
23.055.255.033 (опять лишние нули) 
65.123..9 (две точки подряд) 
a.b.c.d (посторонние символы вместо чисел и точек)

Рекомендации
Активно используйте оператор индексации строки str[i], но помните, что индексы начинаются с нуля, а не с единицы.
Создайте отдельную функцию для получения отдельных чисел из IP-адреса и валидируйте эти отдельные числа.
Для валидации отдельных цифр у чисел следует использовать оператор сравнения с константами символов. Символы от ‘0’ до ‘9’ расположены последовательно и поэтому
уместны операторы <= и >=.
Вам потребуется функция, принимающая на вход строку со всем IP-адресом и порядковый номер октета. Октет — это часть IP-адреса между точками. 
Он содержится в восьми битах, отсюда и название (окта — восемь). 2^8 = 256. Отсюда уже предел значения октета — 255. 
То есть вызов get_address_part(“192.168.1.1”, 1) вернёт 168. Данная функция проходит по всей строке и ищет разделители — точки, 
одновременно с этим накапливает символы в строку, которую вернёт в результате. При нахождении разделителя нужно вернуть полученную строку. 
Проверку её корректности нужно делать в другой функции (проверить длину == 3 и то, что число в строке находится в диапазоне [0,255] ).
*/