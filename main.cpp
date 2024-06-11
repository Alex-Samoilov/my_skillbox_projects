#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector <float> prices {2.5, 4.25, 3.0, 10.0};
    vector <int> items {1, 1, 0, 3};

    float result;

    for (int i = 0; i < items.size(); i++) {
        result += prices[items[i]];
    }
       cout << result;

}