#include <iostream>
using namespace std;

int fact(int n)
{
    // BASE CONDITION
    if (n == 0)
        return 1;
  
    return n * fact(n - 1);
}

int main()
{
    cout << "Factorial of 5 : " << fact(6);
    return 0;
}