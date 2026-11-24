#include "Stack.h"
using namespace std;

Node::Node(double val): value(val), next(nullptr) {}

Node::~Node() {
    delete next;
}

Stack::Stack(): header(nullptr) {}

Stack::~Stack() {
    delete header;
}

bool Stack::isEmpty() {
    if (header == nullptr) {
        return true;
    }
    return false;
}

void Stack::push(double value) {
    Node* node = new Node(value);
    if (isEmpty()) {
        header = node;
        return;
    }
    node -> next = header;
    header = node;
}

bool Stack::pop() {
    if (isEmpty()) {
        throw "stack is empty";
    }
    Node* node = header;
    header = header -> next;
    delete node;
    return true;
}

int Stack::size() {
    Node* node = header;
    int len = 0;
    while (node != nullptr) {
        len ++;
        node = node -> next;
    }
    return len;
}

double Stack::top() {
    if (isEmpty()) {
        throw "stack is empty";
    }
    return header -> value;
}

void Stack::clear() {
    if (isEmpty()) {
        return;
    }
    Node* node = header;
    header = header -> next;
    delete node;
    clear();
}
