#pragma once

#include "BadHashTable.h"


template<class Key, typename Value>
class BetterHashTable : public BadHashTable<Key, Value> {
    void resize() {
        int oldSize = this->arrSize;
        this->arrSize *= 2;
        EntryNode<Key, Value>** resized = (EntryNode<Key, Value>**) calloc(this->arrSize, sizeof(EntryNode<Key, Value>*));
        for(int i = 0; i < oldSize; i++) {
            EntryNode<Key, Value>* tmp = this->entryArr[i];
            while(tmp) {
                int index = BadHashTable<Key, Value>::getIndexFor(tmp->getKey());
                EntryNode<Key, Value>* c = tmp;
                tmp = tmp->getNext();
                c->setNext(resized[index]);
                resized[index] = c;
            }
        }
        this->entryArr = resized;
    }

public:
    int add(const Key &key, const Value &value) {
        int i = BadHashTable<Key, Value>::add(key, value);
        if(i && this->elementsCount / this->arrSize > 1.5) {
            resize();
        }
        return i;
    }
};
