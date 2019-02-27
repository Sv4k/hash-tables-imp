cmake_minimum_required(VERSION 3.10)
project(hash_tables)

set(CMAKE_CXX_STANDARD 11)

add_executable(hash_tables main.cpp hash_sets/BadHashTable.h hash_sets/EntryNode.h hash_sets/BetterHashTable.h hash_sets/WorstHashTable.h Dictionary.cpp Dictionary.h)