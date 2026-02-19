#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        this->data = value;
        this->next = nullptr; 
    }
};

class LinkedList {
    Node* head; 

public:
    LinkedList() {
        head = nullptr; 
     }

    void insert(int value) {
        Node* newNode = new Node(value); // Create a new node
        if (head == nullptr) {
            head = newNode; // If the list is empty, set head to the new node
            return;
        }
        newNode->next = this->head; // Point the new node's next to the current head
        this->head = newNode; // Update head to the new node
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList listahan; 
    listahan.insert(20);
    listahan.insert(40);
    listahan.insert(60);
    listahan.insert(80);
    listahan.insert(100);
    listahan.display(); // Display the list

    return 0;
}