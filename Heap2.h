#pragma once

// узел кучи
class Node {
public:
    int value;
    Node* left;
    Node* right;
    Node* parent;
    Node(int val);
    ~Node();
};

// min-куча
class Heap {
private:
    Node* root;
    Node* last;
    // ищет узел, который не имеет хотя бы одного своего потомка
    Node* find_parent();
    // ищет последний узел кучи
    Node* find_last();
    // поднимает узел наверх
    void sift_up(Node* node);
    // опускает узел вниз
    void sift_down(Node* node);
public:
    Heap();
    ~Heap();
    // добавляет значение в кучу
    void push(int val);
    // удаляет и возвращает минимум
    int pop();
    // проверяет пустая ли куча
    bool is_empty();
};
