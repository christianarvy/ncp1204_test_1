#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* left; 
    Node* right;

    Node(char value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
    public:
    Node* root;
    BinaryTree() : root(nullptr) {}

    void displayConnections(Node* node) {
        if (node == nullptr) return;
        if (node->left) {
            cout << node->data << " -> " << node->left->data << endl;
            displayConnections(node->left);
        }
        if (node->right) {
            cout << node->data << " -> " << node->right->data << endl;
            displayConnections(node->right);
        }
    }
};

int main() {
    BinaryTree puno;

    puno.root = new Node('A');
    puno.root->left = new Node('B');
    puno.root->right = new Node('C');
    puno.root->left->left = new Node('D');
    puno.root->left->right = new Node('E');
    puno.root->right->left = new Node('F');
    puno.root->right->right = new Node('G');

    cout << "Connections in the binary tree:" << endl;
    puno.displayConnections(puno.root);

    return 0;
}
