#pragma once
#include <vector>
using namespace std;

// Узел дерева отрезков
class Node {
public:
    int val;
    Node *left;
    Node *right;
    int l, r;
    Node(int x, int l, int r);
};

// Дерево отрезков
class Tree {
private:
    vector<int> a;
    int n;
    // Построение дерева для отрезка [l, r]
    Node* build(int l, int r);
public:
    Node *root;
    Tree();
    // Построение дерева по массиву
    void init(vector<int> data);
    // Прибавляет data к элементу x
    void update(Node* node, int x, int data);
    // Возвращает сумму на отрезке [l, r]
    int get(Node* node, int l, int r);
};
