#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    double value;
    Node* next;
    Node* last;
    Node(double val): value(val), next(nullptr), last(nullptr) {}
    ~Node() {
        delete next;
        delete last;
    }
};

class DoubleLinkedList {
public:
    Node* header;
    Node* tail;
    DoubleLinkedList(): header(nullptr), tail(nullptr) {}
    ~DoubleLinkedList() {
        delete header;
        delete tail;
    }

    bool isEmpty() {
        if (header == nullptr) {
            return true;
        }
        return false;
    }

    void addToBegin(double value) {
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

    void addToEnd(double value) {
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

    void addBefore(double value, int i) {
        Node* node = new Node(value);
        if (!isEmpty()) {
            if (i < 0) {
                return;
            }
            if (i == 0) {
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
                return;
            }
            h -> last -> next = node;
            node -> next = h;
            node -> last = h -> last;
            h -> last = node;
        }
    }

    void addAfter(double value, int i) {
        Node* node = new Node(value);
        if (!isEmpty()) {
            if (i < 0) {
                return;
            }
            int len = 0;
            Node* h = header;
            while (h != nullptr and len != i) {
                h = h -> next;
                len ++;
            }
            if (len != i or h == nullptr) {
                return;
            }
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
    }

    int lengthList() {
        Node* h = header;
        int len = 0;
        while (h != nullptr) {
            h = h -> next;
            len ++;
        }
        return len;
    }

    bool changeElement(double value, int i) {
        Node* h = header;
        int len = 0;
        while (h != nullptr and len != i) {
            h = h -> next;
            len ++;
        }
        if (len != i or h == nullptr) {
            return false;
        }
        h -> value = value;
        return true;
    }

    bool deleteToBegin() {
        if (isEmpty()) {
            return false;
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

    bool deleteToEnd() {
        if (isEmpty()) {
            return false;
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

    bool deleteByIndex(int i){
        if (isEmpty()) {
            return false;
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
            return false;
        }
        h -> last -> next = h -> next;
        h -> next -> last = h -> last;
        delete h;
        return true;
    }

    bool deleteFirstValue(double value) {
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

    bool deleteAllValue(double value) {
        int cnt = 0;
        while (deleteFirstValue(value) == true) {
            cnt ++;
        }
        if (cnt == 0) {
            return false;
        }
        return true;
    }

    bool valueInList(double value, bool fromBegin = true) {
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

    double getMax() {
        if (isEmpty()) {
            return -1;
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

    bool ListIsSorted() {
        if (isEmpty() || lengthList() == 1) {
            return true;
        }
        Node* h = header;
        while (h -> next != nullptr) {
            if (h -> value > h -> next -> value) {
                return false;
            }
            h = h -> next;
        }
        return true;
    }

    void addList(DoubleLinkedList* list1) {
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

    void outputList() {
        Node* node = header;
        while (node != nullptr) {
            cout << node -> value << " ";
            node = node -> next;
        }
        cout << endl;
    }

    void clean() {
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
};

int main() {}
