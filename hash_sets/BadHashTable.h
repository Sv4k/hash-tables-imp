#pragma once

#include <cstdlib>
#include <functional>
#include "EntryNode.h"
#include <set>

template <class Key, typename Value>
class BadHashTable {
protected:
    EntryNode<Key, Value>** entryArr;
    int arrSize;
    int elementsCount;

    int getIndexFor(const Key &key) {
        return std::hash<Key>()(key) % arrSize;
    }

    EntryNode<Key, Value>* findKey(const Key &key){
        int index = getIndexFor(key);
        EntryNode<Key, Value>* needed = entryArr[index];
        while(needed && needed->getKey() != key) {
            needed = needed -> getNext();
        }
        if(!needed)
            return nullptr;
        return needed;
    }

public:
    BadHashTable() {
        entryArr = (EntryNode<Key, Value>**) calloc(7, sizeof(EntryNode<Key, Value>*));
        arrSize = 8;
        elementsCount = 0;
    }
/*
    BadHashTable(int size) {
        arrSize = size;
        elementsCount = 0;
        entryArr = (EntryNode**) malloc(sizeof(EntryNode*) * size);
        for(int i = 0; i < size; i++) {
            entryArr[i] = nullptr;
        }
    }
*/
    ~BadHashTable() {
        for(int i = 0; i < arrSize; i++) {
            delete entryArr[i];
        }
        free(entryArr);
    }

    int add(const Key &key, const Value &value) {
        if(EntryNode<Key, Value>* tmp = findKey(key)) {
            tmp->setValue(value);
            return 0;
        }
        int index = getIndexFor(key);
        EntryNode<Key, Value> *node = new EntryNode<Key, Value>(key, value);
        node->setNext(entryArr[index]);
        entryArr[index] = node;
        elementsCount++;
        return 1;
    }

    Value* get(const Key &key) {
        EntryNode<Key, Value>* tmp = findKey(key);
        return tmp ? tmp->getValue() : nullptr;
    }

    bool containsKey(const Key &key) {
        return findKey(key) ? true : false;
    }

    int erase(const Key &key) {
        int index = getIndexFor(key);
        EntryNode<Key, Value>* needed = entryArr[index];
        EntryNode<Key, Value>* previous;
        if(needed->getKey() == key) {
            entryArr[index] = needed->getNext();
            needed->setNext(nullptr);
            delete(needed);
            return 1;
        }
        while(needed && needed->getKey() != key) {
            previous = needed;
            needed = needed->getNext();
        }
        if(!needed)
            return 0;
        previous->setNext(needed->getNext());
        needed->setNext(nullptr);
        delete needed;
        return 1;
    }

    std::set<Key> getKeySet() {
        std::set<Key> keySet;
        for(int i = 0; i < arrSize; i++) {
            EntryNode<Key, Value>* cnt = entryArr[i];
            while(cnt) {
                keySet.insert(cnt->getKey());
                cnt = cnt->getNext();
            }
        }
        return keySet;
    }
};

