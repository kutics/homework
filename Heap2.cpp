#include "Heap.h"
#include <bits/stdc++.h>
using namespace std;

Node::Node(int val): value(val), left(nullptr), right(nullptr), parent(nullptr) {}

Node::~Node() {
    delete left;
    delete right;
}

Heap::Heap(): root(nullptr), last(nullptr) {}

Heap::~Heap() {
    delete root;
}

Node* Heap::find_parent() {
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        if (node->left == nullptr || node->right == nullptr) {
            return node;
        }
        q.push(node->left);
        q.push(node->right);
    }
    return nullptr;
}

Node* Heap::find_last() {
    queue<Node*> q;
    q.push(root);
    Node* node = nullptr;
    while (!q.empty()) {
        node = q.front();
        q.pop();
        if (node->left) {
            q.push(node->left);
        }
        if (node->right) {
            q.push(node->right);
        }
    }
    return node;
}

void Heap::sift_up(Node* node) {
    while (node->parent != nullptr && node->parent->value > node->value) {
        int a = node->value;
        node->value = node->parent->value;
        node->parent->value = a;
        node = node->parent;
    }
}

void Heap::sift_down(Node* node) {
    while (true) {
        Node* a = node;
        if (node->left != nullptr) {
            if (node->left->value < a->value) {
                a = node->left;
            }
        }
        if (node->right != nullptr) {
            if (node->right->value < a->value) {
                a = node->right;
            }
        }
        if (a == node) {
            break;
        }
        int s = node->value;
        node->value = a->value;
        a->value = s;
        node = a;
    }
}

void Heap::push(int val) {
    Node* node = new Node(val);
    if (root == nullptr) {
        root = node;
        last = node;
        return;
    }
    Node* p = find_parent();
    if (p->left == nullptr) {
        p->left = node;
    } else {
        p->right = node;
    }
    node->parent = p;
    last = node;
    sift_up(node);
}

int Heap::pop() {
    if (root == nullptr) {
        throw "heap is empty";
    }
    int res = root->value;
    Node* r = find_last();
    if (r == root) {
        delete root;
        root = nullptr;
        last = nullptr;
        return res;
    }
    root->value = r->value;
    if (r->parent->left == r) {
        r->parent->left = nullptr;
    } else {
        r->parent->right = nullptr;
    }
    r->left = nullptr;
    r->right = nullptr;
    delete r;
    last = find_last();
    sift_down(root);
    return res;
}

bool Heap::is_empty() {
    if (root == nullptr) {
        return true;
    }
    return false;
}
