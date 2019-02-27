#pragma once

template <class K, typename V>
class EntryNode {
    K key;
    V value;
    EntryNode* next;

public:
    EntryNode(K key, V value) : key(key), value(value) {
        next = nullptr;
    }

    EntryNode* getNext() {
        return next;
    }

    K getKey() {
        return key;
    }

    V* getValue() {
        return &value;
    }

    void setNext(EntryNode* next) {
        this->next = next;
    }

    void setValue(const V &value) {
        this->value = value;
    }

    void setKey(const K &key) {
        this->key = key;
    }

    ~EntryNode() {
        delete next;
    }
};