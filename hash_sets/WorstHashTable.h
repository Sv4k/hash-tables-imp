#pragma once

#include "EntryNode.h"

template <class Key, typename Value>
class WorstHashTable {
    EntryNode<Key, Value>* head;

    EntryNode<Key, Value>* findKey(const Key &key) {
        EntryNode<Key, Value>* needed = head;
        while(needed && needed->getKey() != key) {
            needed = needed -> getNext();
        }
        if(!needed)
            return nullptr;
        return needed;
    }
public:
    WorstHashTable() {
        head = nullptr;
    }

    ~WorstHashTable() {
        delete head;
    }

    int add(const Key &key, const Value &value) {
        if(EntryNode<Key, Value>* found = findKey(key)) {
            found->setValue(value);
            return 0;
        }
        EntryNode<Key, Value>* node = new EntryNode<Key, Value>(key, value);
        node->setNext(head);
        head = node;
        return 1;
    }

    Value* get(const Key &key) {
        EntryNode<Key, Value>* tmp = findKey(key);
        return tmp ? tmp ->getValue() : nullptr;
    }

    bool containsKey(const Key &key) {
        return findKey(key) ? true : false;
    }

    int erase(const Key &key) {
        if(head->getKey() == key) {
            EntryNode<Key, Value>* tmp = head;
            head = head->getNext();
            tmp->setNext(nullptr);
            delete tmp;
        }
        EntryNode<Key,Value>* needed = head;
        EntryNode<Key, Value>* previous;
        while(needed && needed->getKey() != key) {
            previous = needed;
            needed = needed->getNext();
        }
        if(!needed)
            return 0;
        previous->setNext(needed->getNext());
        needed->setNext(nullptr);
        delete needed;
    }


};

