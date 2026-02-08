#include <iostream>
using namespace std;

class Car{
    public: 
    string brand;
    string model;
    int prices;
    int year;

    Car(string x, string y,int p, int z){
        brand = x;
        model = y;
        prices = p;
        year = z;
    }
    void displayInfo(){
        cout << "Brand: " << brand << endl; 
        cout << ", Model: " << model << endl; 
        cout << ", Price: $" << prices << endl; 
        cout << ", Year: " << year << endl;
    }

    int getPrice(int qty){
        return prices * qty;
    }
};
int main() {
    Car toyota("Toyota", "Camry", 24000, 2020);
    Car honda("Honda", "Civic", 32000, 2019);

    toyota.displayInfo();
    honda.displayInfo();    

    cout << "Total price for 3 Toyota cars: $" << toyota.getPrice(3) << endl;
    cout << "Total price for 2 Honda cars: $" << honda.getPrice(2) << endl;
}