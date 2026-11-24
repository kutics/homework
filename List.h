#pragma once

// Узел двусвязного списка
class Node {
public:
    double value;
    Node* next;
    Node* last;
    Node(double val);
    ~Node();
};

// Двусвязный список
class DoubleLinkedList {
public:
    Node* header;
    Node* tail;
    DoubleLinkedList();
    ~DoubleLinkedList();
    // Проверяет пуст ли список
    bool isEmpty();
    // Добавляет элемент в начало
    void addToBegin(double value);
    // Добавляет элемент в конец
    void addToEnd(double value);
    // Добавляет элемент на место перед i
    void addBefore(double value, int i);
    // Добавляет элемент на место после i
    void addAfter(double value, int i);
    // Возвращает длину списка
    int lengthList();
    // Заменяет элемент с индексом i на новый эелемент
    bool changeElement(double value, int i);
    // Удаляет первый элемент
    bool deleteToBegin();
    // Удаляет последний элемент
    bool deleteToEnd();
    // Удаляет элемент с индексом i
    bool deleteByIndex(int i);
    // Удаляет первое вхождение value
    bool deleteFirstValue(double value);
    // Удаляет все вхождения value
    bool deleteAllValue(double value);
    // Проверяет наличие элемента со значением value
    bool valueInList(double value, bool fromBegin = true);
    // Возвращает максимум
    double getMax();
    // Проверяет отстортирован ли список
    bool ListIsSorted();
    // Присоединяет list1 в конец списка
    void addList(DoubleLinkedList* list1);
    // Выводит все элементы
    void outputList();
    // Удаляет все элементы
    void clean();
};
