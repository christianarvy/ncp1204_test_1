#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node *prev;

    Node(int value) {
        this->data = value;
        this->next = nullptr; 
        this->prev = nullptr;
    }
};

class DoublyList {
    Node* head;

public:
    DoublyList() {
        head = nullptr; // Initialize head to nullptr, indicating an empty list
    }

    void frontInsert(int value) {
        Node* newNode = new Node(value); 
        if (head == nullptr) {
            head = newNode; // If the list is empty, set head to the new node
            return;
        }
        newNode->next = this->head; // Point the new node's next to the current head
        this->head->prev = newNode; // Set the previous of the current head to the new node
        this->head = newNode;
    }
    
    void backInsert(int value) {
        Node* newNode = new Node(value); 
        if (head == nullptr) {
            head = newNode; // If the list is empty, set head to the new node
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
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
    DoublyList listahan; 
    listahan.frontInsert(20);
    listahan.frontInsert(40);
    listahan.backInsert(60);
    listahan.backInsert(80);
    listahan.backInsert(100);
    listahan.display(); // Display the list

    return 0;
}