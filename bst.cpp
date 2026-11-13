#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int x): data(x), left(nullptr), right(nullptr) {}
    ~Node() {
        delete left;
        delete right;
    }
};
class BinarySearchTree {
public:
    Node* head;
    BinarySearchTree(): head(nullptr) {}
    ~BinarySearchTree() {
        delete head;
    }
    void insertt(int x, Node* node) {
        if (head == nullptr) {
            Node* el = new Node(x);
            head = el;
            return;
        } else {
            if (x < node->data) {
                if (node->left != nullptr) {
                    insertt(x, node->left);
                } else {
                    Node* el = new Node(x);
                    node->left = el;
                    return;
                }
            } else if (x > node->data) {
                if (node->right != nullptr) {
                    insertt(x, node->right);
                } else {
                    Node* el = new Node(x);
                    node->right = el;
                    return;
                }
            } else {
                return;
            }
        }
    }
    Node* erasee(int x, Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        if (x < node->data) {
            node->left = erasee(x, node->left);
            return node->left;
        } else if (x > node->data) {
            node->right = erasee(x, node->right);
            return node->right;
        } else {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }
            if (node->left == nullptr) {
                Node* ll = node->right;
                delete node;
                return ll;
            }
            if (node->right == nullptr) {
                Node* rr = node->left;
                delete node;
                return rr;
            }
            Node* mn = node->right;
            while (mn->left != nullptr) {
                mn = mn->left;
            }
            node->data = mn->data;
            node->right = erasee(mn->data, node->right);
            return node;
        }
    }
    void print(Node* node) {
        if (node == nullptr) {
            cout << "empty";
            return;
        }
        if (node->left != nullptr) {
            print(node->left);
        }
        cout << node->data << " ";
        if (node->right != nullptr) {
            print(node->right);
        }
    }
    bool emptyy() {
        if (head == nullptr) {
            return true;
        } else {
            return false;
        }
    }
    int get_size() {
        if (head == nullptr) {
            return 0;
        }
        int cnt = 0;
        queue <Node*> q;
        q.push(head);
        while (!q.empty()) {
            Node* v = q.front();
            q.pop();
            cnt ++;
            if (v->left != nullptr) {
                q.push(v->left);
            }
            if (v->right != nullptr) {
                q.push(v->right);
            }
        }
        return cnt;
    }
};

int main() {}
