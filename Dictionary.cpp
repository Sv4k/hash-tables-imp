//
// Created by goust on 21.12.2018.
//

#include "Dictionary.h"

Dictionary::Dictionary(const std::string &fileName) {
    this->fileName = fileName;
    table = new BetterHashTable<std::string, int>();
}

void Dictionary::analyse() {
    std::ifstream in(fileName);
    while(!in.eof()) {
        std::string word;
        in >> word;
        int *tmp = table->get(word);
        table->add(word, tmp ? (*tmp + 1) : 1);
    }
}

void Dictionary::print() {
    std::set<std::string> keys = table->getKeySet();
    for(std::string i : keys) {
        std::cout << i << " " << *(table->get(i)) <<"\n";
    }
}
Dictionary::~Dictionary() {
    delete table;
}
