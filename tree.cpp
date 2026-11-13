#include <bits/stdc++.h>
using namespace std;

vector <int> a;
int n;

class Node {
public:
    int val;
    Node *left;
    Node *right;
    int l, r;
    Node(int x, int l, int r): val(x), left(nullptr), right(nullptr), l(l), r(r) {};
    ~Node() {
        delete left;
        delete right;
    }
};
class Tree {
public:
    Node *root;
    Tree(): root(nullptr) {};
    ~Tree() {
        delete root;
    }
    Node* build(int l, int r) {
        Node* node = new Node(0, l, r);
        if (l == r) {
            node->val = a[l - 1];
            return node;
        }
        int m = (l + r) / 2;
        node->left = build(l, m);
        node->right = build(m + 1, r);
        node->val = node->left->val + node->right->val;
        return node;
    }
    void update(Node* node, int x, int data) {
        if (node->l == node->r) {
            node->val = data;
            return;
        }
        int m = (node->l + node->r) / 2;
        if (x <= m) {
            update(node->left, x, data);
        } else {
            update(node->right, x, data);
        }
        node->val = node->left->val + node->right->val;
    }
    int get(Node* node, int l, int r) {
        if (r < node->l || l > node->r) {
            return 0;
        }
        if (l <= node->l && node->r <= r) {
            return node->val;
        }
        int m = (node->l + node->r) / 2;
        return get(node->left, l, r) + get(node->right, l, r);
    }
};

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    Tree tree = Tree();
    tree.root = tree.build(1, n);
}
