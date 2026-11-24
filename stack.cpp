#include <bits/stdc++.h>
using namespace std;

struct Node {
public:
    double value;
    Node* next;
    Node(double val): value(val), next(nullptr) {}
    ~Node() {
        delete next;
    }
};

struct Stack {
public:
    Node* header;
    Stack(): header(nullptr) {}
    ~Stack() {
        delete header;
    }

    bool isEmpty() {
        if (header == nullptr) {
            return true;
        }
        return false;
    }

    void push(double value) {
        Node* node = new Node(value);
        if (isEmpty()) {
            header = node;
            return;
        }
        node -> next = header;
        header = node;
    }

    bool pop() {
        if (isEmpty()) {
            return false;
        }
        Node* node = header;
        header = header -> next;
        delete node;
        return true;
    }

    int size() {
        Node* node = header;
        int len = 0;
        while (node != nullptr) {
            len ++;
            node = node -> next;
        }
        return len;
    }

    double top() {
        if (isEmpty()) {
            return -1;
        }
        return header -> value;
    }

    void clear() {
        if (isEmpty()) {
            return;
        }
        Node* node = header;
        header = header -> next;
        delete node;
        clear();
    }
};

int main() {}
