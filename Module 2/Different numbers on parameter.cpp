#include <iostream>
using namespace std;

int multiply(int a, int b);
int multiply(int a, int b, int c);

int main() {
    cout << multiply(10, 2) << endl;
    cout << multiply(5, 6, 4);

    return 0;
}

int multiply(int a, int b) {
    return a * b;
}
int multiply(int a, int b, int c) {
    return a * b * c;
}