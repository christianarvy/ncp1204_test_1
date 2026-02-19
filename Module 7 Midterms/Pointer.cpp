#include <iostream>
using namespace std;

int main(){
    string myname = "arvy";
    string &palayaw = myname; 
    string *ptr = &myname; 

    cout << "my name is " << myname << endl;
    cout << "my name address is: " << ptr << endl; 
    cout << "my name another address is: " << &myname << endl; 
    cout << "my name using pointeris: " << *ptr << endl;
    cout << "my name using reference is: " << palayaw << endl;

    return 0;
}