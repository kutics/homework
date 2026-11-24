#pragma once
#include <bits/stdc++.h>

// Узел бора
class Node {
public:
    bool is_end;
    std::map<char, Node*> ch;
    Node();
};

// Бор
class Trie {
public:
    Node* root;
    Trie();
    ~Trie();
    // Добавляет строку s в бор
    void insertt(std::string s);
    // Проверяет была ли строка s добавлена целиком
    bool contains(std::string s);
    // Проверяет есть ли строка с префиксом pref
    bool starts_with(std::string pref);
};
