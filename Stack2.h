#pragma once

// Узел стека
struct Node {
public:
    double value;
    Node* next;
    Node(double val);
    ~Node();
};

// Стек
struct Stack {
public:
    Node* header;
    Stack();
    ~Stack();
    // Проверяет пустой ли стек
    bool isEmpty();
    // Вставляет value на начало стека
    void push(double value);
    // Возвращает и удаляет элемент с начала
    bool pop();
    // Возвращает количество элементов
    int size();
    // Возвращает элемент с начала, не удаляя ее
    double top();
    // Удаляет все элементы
    void clear();
};
