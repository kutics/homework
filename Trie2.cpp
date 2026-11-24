#include "Trie.h"
using namespace std;

Node::Node(): is_end(false) {}

Trie::Trie(): root(new Node()) {}

Trie::~Trie() {
    delete root;
}

void Trie::insertt(string s) {
    Node* node = root;
    for (char c: s) {
        if (node->ch.find(c) == node->ch.end()) {
            node->ch[c] = new Node();
        }
        node = node->ch[c];
    }
    node->is_end = true;
}

bool Trie::contains(string s) {
    Node* node = root;
    for (auto c: s) {
        if (node->ch.find(c) == node->ch.end()) {
            return false;
        }
        node = node->ch[c];
    }
    return node->is_end;
}

bool Trie::starts_with(string pref) {
    Node* node = root;
    for (auto c: pref) {
        if (node->ch.find(c) == node->ch.end()) {
            return false;
        }
        node = node->ch[c];
    }
    return true;
}
