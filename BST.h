#pragma once

// Узел бинарного дерева
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int x);
    ~Node();
};

// Бинарное дерево
class BinarySearchTree {
public:
    Node* head;
    BinarySearchTree();
    ~BinarySearchTree();
    // Вставляет x, спускаясь от node
    void insertt(int x, Node* node);
    // Удаляет x из поддерева node
    Node* erasee(int x, Node* node);
    // Выводит элементы поддерева node
    void print(Node* node);
    // Проверяет пусто ли дерево
    bool emptyy();
    // Возвращает количество узлов
    int get_size();
};
