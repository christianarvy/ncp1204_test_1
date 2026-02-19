#include <iostream>
using namespace std;
class File {
public:
File() {
cout << "File opened" << endl;
}
~File() {
cout << "File closed" << endl;
}
};
int main() {
File f;
return 0;
}