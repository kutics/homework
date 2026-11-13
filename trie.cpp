#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    bool is_end;
    map <char, Node*> ch;
    Node(): is_end(false) {}
};

class Trie {
public:
    Node* root;
    Trie(): root(new Node()) {}
    ~Trie() {
        delete root;
    }
    void insertt(string s) {
        Node* node = root;
        for (char c: s) {
            if (node->ch.find(c) == node->ch.end()) {
                node->ch[c] = new Node();
            }
            node = node->ch[c];
        }
        node->is_end = true;
    }
    bool contains(string s) {
        Node* node = root;
        for (auto c: s) {
            if (node->ch.find(c) == node->ch.end()) {
                return false;
            }
            node = node->ch[c];
        }
        return node->is_end;
    }
    bool starts_with(string pref) {
        Node* node = root;
        for (auto c: pref) {
            if (node->ch.find(c) == node->ch.end()) {
                return false;
            }
            node = node->ch[c];
        }
        return true;
    }
};

int main() {}
