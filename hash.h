#include <bits/stdc++.h>
using namespace std;

#ifndef HASH_H
#define HASH_H
class Hash
{
private:
    static const int tablesize = 4;
    struct item
    {
        string name;
        string drink;
        item *next;
    };

    item *Hashtable[tablesize];

public:
    Hash();
    int HashS(string key);
    void additem(string name, string drink);
    int numberofiteminindex(int index);
    void printtable();
    void printiteminindex(int index);
    void finddrink(string name);
    void removeitem(string name); 
};
#endif
