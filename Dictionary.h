#pragma once


#include <string>
#include <sstream>
#include <fstream>
#include <set>
#include <vector>
#include <iostream>
#include "hash_sets/BetterHashTable.h"

class Dictionary {
    BetterHashTable<std::string, int>* table;
    std::string fileName;

public:
    explicit Dictionary(const std::string &fileName);

    void analyse();

    void print();

    ~Dictionary();

};

