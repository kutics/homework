#include "SegmentTree.h"
using namespace std;

Node::Node(int x, int l, int r): val(x), left(nullptr), right(nullptr), l(l), r(r) {}

Tree::Tree(): n(0), root(nullptr) {}

void Tree::init(vector<int> data) {
    if (data.empty()) {
        throw "array is empty";
    }
    a = data;
    n = (int)a.size();
    root = build(1, n);
}

Node* Tree::build(int l, int r) {
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

void Tree::update(Node* node, int x, int data) {
    if (node == nullptr || x < 1 || x > n) {
        throw "index out of range";
    }
    if (node->l == node->r) {
        node->val += data;
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

int Tree::get(Node* node, int l, int r) {
    if (node == nullptr || l < 1 || r > n || l > r) {
        throw "invalid range";
    }
    if (r < node->l || l > node->r) {
        return l;
    }
    if (l <= node->l && node->r <= r) {
        return node->val;
    }
    int m = (node->l + node->r) / 2;
    return get(node->left, l, r) + get(node->right, l, r);
}
