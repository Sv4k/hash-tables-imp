#include <iostream>
#include "hash_sets/BetterHashTable.h"
#include "hash_sets/WorstHashTable.h"
#include "Dictionary.h"
#include "ctime"

void editText(std::string input, std::string output)
{
    std::ifstream infile(input);
    std::ofstream outfile(output);

    while (!infile.eof()) {

        std::string str;
        infile >> str;
        for (unsigned int i = 0; i < str.length(); ++i) {

            if ((str[i] >= 'a' && str[i] <= 'z')) {
                continue;
            }

            else if (str[i] >= 'A' && str[i] <= 'Z')
                str[i] = str[i] - 'A' + 'a';

            else str[i] = ' ';

        }
        outfile << str << " ";
    }

    infile.close();
    outfile.close();
}

void test(std::string fileName) {
    WorstHashTable<std::string, int>* worst = new WorstHashTable<std::string, int>();
    BadHashTable<std::string, int>* bad = new BadHashTable<std::string, int>();
    BetterHashTable<std::string, int>* better = new BetterHashTable<std::string, int>();

    long maxForWget = 0;
    long avgForWget = 0;
    long maxForBget = 0;
    long avgForBget = 0;
    long maxForBetterGet = 0;
    long avgForBetterGet = 0;
    long maxForWadd = 0;
    long avgForWadd = 0;
    long maxForBadd = 0;
    long avgForBadd = 0;
    long maxForBetterAdd = 0;
    long avgForBetterAdd = 0;
    int cnt = 0;

    std::ifstream in(fileName);
    while(!in.eof()) {
        std::string word;
        in >> word;

        cnt++;

        long t = clock();
        int *tmpW = worst->get(word);
        t = (clock() - t);
        avgForWget += t / cnt;
        if(maxForWget < t)
            maxForWget = t;


        t = clock();
        int* tmpBad = bad->get(word);
        t = (clock() - t);
        avgForBget += t / cnt;
        if(maxForBget < t)
            maxForBget = t;


        t = clock();
        int* tmpBet = better->get(word);
        t = (clock() - t);
        avgForBget += t / cnt;
        if(maxForBget < t)
            maxForBget = t;

        t = clock();
        worst->add(word, tmpW ? (*tmpW + 1) : 1);
        t = (clock() - t);
        avgForWadd += t / cnt;
        if(maxForWadd < t)
            maxForWadd = t;

        t = clock();
        bad->add(word, tmpBad ? (*tmpBad + 1) : 1);
        t = (clock() - t);
        avgForBadd += t / cnt;
        if(maxForBadd < t)
            maxForBadd = t;

        t = clock();
        better->add(word, tmpBet ? (*tmpBet + 1) : 1);
        t = (clock() - t);
        avgForBetterAdd += t / cnt;
        if(maxForBetterAdd < t)
            maxForBetterAdd = t;
    }
    std::cout << "max time for worst hash table:\n" << "add: " << maxForWadd << "\nget: " << maxForWget << "\navg time for worst hash table:\n" << "add: " << avgForWadd << "\nget: " << avgForWget;
    std::cout << "\nmax time for bad hash table:\n" << "add: " << maxForBadd << "\nget: " << maxForBget << "\navg time for bad hash table:\n" << "add: " << avgForBadd << "\nget: " << avgForBget;
    std::cout << "\nmax time for better hash table:\n" << "add: " << maxForBetterAdd << "\nget: " << maxForBetterGet << "\navg time for better hash table:\n" << "add: " << avgForBetterAdd << "\nget: " <<avgForBetterGet;
}




int main() {
    /*
    WorstHashTable<std::string, int>* worst = new WorstHashTable<std::string, int>();
    BadHashTable<int, int>* bad = new BadHashTable<int, int>();
    BetterHashTable<std::string, int>* better = new BetterHashTable<std::string, int>();

    std::string win = "winter";
    std::string spr = "spring";
    std::string sum = "summer";
    std::string aut = "autumn";

    int winter = 1;
    int spring = 2;
    int summer = 3;
    int autumn = 4;

    worst->add(win, winter);
    worst->add(spr, spring);
    worst->add(aut, autumn);

    bad->add(21, winter);
    bad->add(22, summer);
    bad->add(23, spring);
    bad->add(24, autumn);

    better->add(win, winter);
    better->add(aut, autumn);
    better->add(sum, summer);
    better->add(sum, winter);

    std::cout << *(bad->get(22));
    std::cout << *(better->get(aut));
     */

    std::string str = "D:\\programs\\2.1\\hash_tables\\input.txt";
/*
    Dictionary dictionary("D:\\programs\\2.1\\hash_tables\\output.txt");
    dictionary.analyse();
    dictionary.print();
*/
    editText(str, "D:\\programs\\2.1\\hash_tables\\output.txt");
    test("D:\\programs\\2.1\\hash_tables\\output.txt");
}