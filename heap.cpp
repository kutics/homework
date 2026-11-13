#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;
    Node* parent;
    Node(int val): value(val), left(nullptr), right(nullptr), parent(nullptr) {}
    ~Node() {
        delete left;
        delete right;
    }
};

class Heap {
public:
    Node* root;
    Node* last;
    Heap(): root(nullptr), last(nullptr) {};
    ~Heap() {
        delete root;
    }
    Node* find_parent() {
        queue <Node*> q;
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
    Node* find_last() {
        queue <Node*> q;
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
    void sift_up(Node* node) {
        while (node->parent != nullptr && node->parent->value > node->value) {
            int a = node->value;
            node->value = node->parent->value;
            node->parent->value = a;
            node = node->parent;
        }
    }
    void sift_down(Node* node) {
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
    void push(int val) {
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
    int pop() {
        if (root == nullptr) {
            return -1;
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
    bool is_empty() {
        if (root == nullptr) {
            return true;
        }
        return false;
    }
};

int main() {}
