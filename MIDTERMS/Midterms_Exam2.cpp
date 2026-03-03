#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev;
    Node(char val) : data(val), next(nullptr), prev(nullptr) {}
};

class JJ {
private:
    Node* head;
    Node* tail;
    bool isDoubly;
public:
    JJ(bool doubly = false) : head(nullptr), tail(nullptr), isDoubly(doubly) {}

    ~JJ() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

    void KK(char val, bool atFront = false) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
            return;
        }

        if (atFront) {
            newNode->next = head;
            if (isDoubly) head->prev = newNode;
            head = newNode;
            return;
        }

        tail->next = newNode;
        if (isDoubly) newNode->prev = tail;
        tail = newNode;
    }

    void NN(char val) { // Remove first occurrence of val
        if (!head) return; // Empty list
        if (head->data == val) { // Remove head
            Node* temp = head; // Store current head to delete
            head = head->next; // Move head to next node
            if (isDoubly && head) head->prev = nullptr; // Update new head's prev if doubly linked
            if (!head) tail = nullptr; // If list becomes empty, update tail
            delete temp; // Delete old head
            return; // Return after removing head
        }

        Node* curr = head; // Start from head
        while (curr->next && curr->next->data != val) curr = curr->next; // Traverse to find node before target
        if (!curr->next) return; // Target not found, return

        Node* temp = curr->next; // Node to be removed
        curr->next = temp->next; // Bypass the node to be removed
        if (isDoubly && curr->next) curr->next->prev = curr; // Update next node's prev if doubly linked
        if (!curr->next) tail = curr; // If removed node was tail, update tail
        delete temp; // Delete the target node
    }

    void LL() const {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            cout << (isDoubly ? " <-> " : " -> ");
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void MM() const {
        if (!isDoubly) return;
        Node* temp = tail;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL\n";
    }

    void OO() const { LL(); }
};

struct W {
    char data;
    W* left;
    W* right;
    W(char val) : data(val), left(nullptr), right(nullptr) {}
};

class PP {
private:
    W* root;

    enum class TraversalOrder { QQQ, RRR, SSS };

    void clear(W* node) {
        if (!node) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

    W* XX(W* node, char val) {
        if (!node) return new W(val);
        if (val < node->data)
            node->left = XX(node->left, val);
        else
            node->right = XX(node->right, val);
        return node;
    }

    W* YY(W* node, char val) {// Remove node with value val
        if (!node) return nullptr;// Base case: empty tree
        if (val < node->data) {
            node->left = YY(node->left, val);
        } else if (val > node->data) {
            node->right = YY(node->right, val);
        } else {
            if (!node->left) {
                W* temp = node->right;//
                delete node;
                return temp;
            }
            if (!node->right) {
                W* temp = node->left;
                delete node;
                return temp;
            }
            W* temp = node->right;
            while (temp->left) temp = temp->left;
            node->data = temp->data;
            node->right = YY(node->right, temp->data);
        }
        return node;
    }

    void ZZ(W* node, TraversalOrder order) {
        if (!node) return;
        if (order == TraversalOrder::RRR) cout << node->data << " ";
        ZZ(node->left, order);
        if (order == TraversalOrder::QQQ) cout << node->data << " ";
        ZZ(node->right, order);
        if (order == TraversalOrder::SSS) cout << node->data << " ";
    }

    void OO(TraversalOrder order) {
        ZZ(root, order);
        cout << "\n";
    }

public:
    PP() : root(nullptr) {}
    ~PP() { clear(root); }

    void KK(char val) { root = XX(root, val); }
    void NN(char val) { root = YY(root, val); }
    void QQ() { OO(TraversalOrder::QQQ); }
    void RR() { OO(TraversalOrder::RRR); }
    void SS() { OO(TraversalOrder::SSS); }

    void TT() {
        if (!root) return;
        queue<W*> q;
        q.push(root);
        while (!q.empty()) {
            W* node = q.front();
            q.pop();
            cout << node->data << " ";
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << "\n";
    }

    void UU() {
        if (!root) return;
        stack<W*> s;
        s.push(root);
        while (!s.empty()) {
            W* node = s.top();
            s.pop();
            cout << node->data << " ";
            if (node->right) s.push(node->right);
            if (node->left) s.push(node->left);
        }
        cout << "\n";
    }
};

int main() {
    cout << "=== Sing === \n";
    JJ sing(false);
    for (char value : {'a', 'b', 'c'}) sing.KK(value);
    sing.OO();
    sing.NN('b');
    sing.OO();

    cout << "\n=== Dance === \n";
    JJ dance(true);
    for (char value : {'d', 'e', 'f', 'g'}) dance.KK(value);
    cout << "LL: ";
    dance.LL();
    cout << "MM: ";
    dance.MM();

    dance.KK('c', true);
    cout << "After KK('c', true) - LL: ";
    dance.LL();
    cout << "After KK('c', true) - MM: ";
    dance.MM();

    dance.NN('e');
    cout << "After NN('e') - LL: ";
    dance.LL();
    cout << "After NN('e') - MM: ";
    dance.MM();

    cout << "\n=== Tavel === \n";
    PP tavel;
    for (char value : {'d', 'b', 'f', 'a', 'c', 'e', 'g'}) tavel.KK(value);

    cout << "QQ: ";
    tavel.QQ();
    cout << "RR: ";
    tavel.RR();
    cout << "SS: ";
    tavel.SS();
    cout << "TT: ";
    tavel.TT();
    cout << "UU: ";
    tavel.UU();

    return 0;
}
