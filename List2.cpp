#include "List.h"
#include <bits/stdc++.h>
using namespace std;

Node::Node(double val): value(val), next(nullptr), last(nullptr) {}

Node::~Node() {
    delete next;
    delete last;
}

DoubleLinkedList::DoubleLinkedList(): header(nullptr), tail(nullptr) {}

DoubleLinkedList::~DoubleLinkedList() {
    delete header;
    delete tail;
}

bool DoubleLinkedList::isEmpty() {
    if (header == nullptr) {
        return true;
    }
    return false;
}

void DoubleLinkedList::addToBegin(double value) {
    Node* node = new Node(value);
    if (!isEmpty()) {
        header -> last = node;
        node -> next = header;
        header = node;
    } else {
        header = node;
        tail = node;
    }
}

void DoubleLinkedList::addToEnd(double value) {
    Node* node = new Node(value);
    if (!isEmpty()) {
        tail -> next = node;
        node -> last = tail;
        tail = node;
    } else {
        header = node;
        tail = node;
    }
}

void DoubleLinkedList::addBefore(double value, int i) {
    if (isEmpty() || i < 0) {
        throw "index out of range";
    }
    if (i == 0) {
        Node* node = new Node(value);
        header -> last = node;
        node -> next = header;
        header = node;
        return;
    }
    int len = 0;
    Node* h = header;
    while (h != nullptr and len != i) {
        h = h -> next;
        len ++;
    }
    if (len != i or h == nullptr) {
        throw "index out of range";
    }
    Node* node = new Node(value);
    h -> last -> next = node;
    node -> next = h;
    node -> last = h -> last;
    h -> last = node;
}

void DoubleLinkedList::addAfter(double value, int i) {
    if (isEmpty() || i < 0) {
        throw "index out of range";
    }
    int len = 0;
    Node* h = header;
    while (h != nullptr and len != i) {
        h = h -> next;
        len ++;
    }
    if (len != i or h == nullptr) {
        throw "index out of range";
    }
    Node* node = new Node(value);
    if (h -> next != nullptr) {
        h -> next -> last = node;
        node -> next = h -> next;
        h -> next = node;
        node -> last = h;
    } else {
        h -> next = node;
        node -> last = h;
        tail = node;
    }
}

int DoubleLinkedList::lengthList() {
    Node* h = header;
    int len = 0;
    while (h != nullptr) {
        h = h -> next;
        len ++;
    }
    return len;
}

bool DoubleLinkedList::changeElement(double value, int i) {
    Node* h = header;
    int len = 0;
    while (h != nullptr and len != i) {
        h = h -> next;
        len ++;
    }
    if (len != i or h == nullptr) {
        throw "index out of range";
    }
    h -> value = value;
    return true;
}

bool DoubleLinkedList::deleteToBegin() {
    if (isEmpty()) {
        throw "list is empty";
    }
    Node* node = header;
    if (lengthList() == 1) {
        header = nullptr;
        tail = nullptr;
        delete node;
        return true;
    }
    header -> next -> last = nullptr;
    header = header -> next;
    delete node;
    return true;
}

bool DoubleLinkedList::deleteToEnd() {
    if (isEmpty()) {
        throw "list is empty";
    }
    Node* node = tail;
    if (lengthList() == 1) {
        header = nullptr;
        tail = nullptr;
        delete node;
        return true;
    }
    tail -> last -> next = nullptr;
    tail = tail -> last;
    delete node;
    return true;
}

bool DoubleLinkedList::deleteByIndex(int i) {
    if (isEmpty()) {
        throw "list is empty";
    }
    if (i < 0) {
        throw "index out of range";
    }
    if (i == 0) {
        return deleteToBegin();
    }
    if (i == lengthList() - 1) {
        return deleteToEnd();
    }
    Node* h = header;
    int len = 0;
    while (h != nullptr and len != i) {
        h = h -> next;
        len ++;
    }
    if (len != i or h == nullptr) {
        throw "index out of range";
    }
    h -> last -> next = h -> next;
    h -> next -> last = h -> last;
    delete h;
    return true;
}

bool DoubleLinkedList::deleteFirstValue(double value) {
    Node* h = header;
    int len = 0;
    while (h != nullptr) {
        if (h -> value == value) {
            return deleteByIndex(len);
        }
        h = h -> next;
        len ++;
    }
    return false;
}

bool DoubleLinkedList::deleteAllValue(double value) {
    int cnt = 0;
    while (deleteFirstValue(value) == true) {
        cnt ++;
    }
    if (cnt == 0) {
        return false;
    }
    return true;
}

bool DoubleLinkedList::valueInList(double value, bool fromBegin) {
    if (fromBegin) {
        Node* h = header;
        while (h != nullptr) {
            if (h -> value == value) {
                return true;
            }
            h = h -> next;
        }
        return false;
    }
    Node* h = tail;
    while (h != nullptr) {
        if (h -> value == value) {
            return true;
        }
        h = h -> last;
    }
    return false;
}

double DoubleLinkedList::getMax() {
    if (isEmpty()) {
        throw "list is empty";
    }
    Node* h = header;
    double mx = h -> value;
    while (h -> next != nullptr) {
        h = h -> next;
        if (mx < h -> value) {
            mx = h -> value;
        }
    }
    return mx;
}

bool DoubleLinkedList::ListIsSorted() {
    if (isEmpty() || lengthList() == 1) {
        return true;
    }
    Node* h = header;
    while (h -> next != nullptr) {
        if (h -> value > h -> next -> value) {
            return false;
        }
    }
    return true;
}

void DoubleLinkedList::addList(DoubleLinkedList* list1) {
    if (isEmpty()) {
        header = list1 -> header;
        tail = list1 -> tail;
        return;
    }
    if (list1 -> isEmpty()) {
        return;
    }
    tail -> next = list1 -> header;
    list1 -> header -> last = tail;
    tail = list1 -> tail;
}

void DoubleLinkedList::outputList() {
    Node* node = header;
    while (node != nullptr) {
        cout << node -> value << " ";
        node = node -> next;
    }
    cout << endl;
}

void DoubleLinkedList::clean() {
    if (isEmpty()) {
        return;
    }
    Node* h = header;
    while (h -> next != nullptr) {
        header -> next -> last = nullptr;
        header = header -> next;
        delete  h;
        h = header;
    }
    header = nullptr;
    tail = nullptr;
    delete h;
}
