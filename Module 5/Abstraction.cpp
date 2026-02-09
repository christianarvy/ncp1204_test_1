#include <iostream>
using namespace std;

class Appliance {
public:
    virtual void turnOn() = 0; 
};

class ElectricFan : public Appliance {
public:
    void turnOn() override {
        cout << "Electric fan is now ON" << endl;
    }
};

int main() {
    Appliance* a = new ElectricFan();
    a->turnOn();
    delete a;
    return 0;
}
