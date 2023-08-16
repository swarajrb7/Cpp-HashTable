#include <bits/stdc++.h>
#include "hash.h"
using namespace std;

int main(int argc, char **argv)
{
    Hash ob;
    string name = "";
    ob.additem("Paul", "L");
    ob.additem("Kim", "LM");
    ob.additem("Emma", "SS");
    ob.additem("Annie", "HC");
    ob.additem("Mike", "CT");
    ob.additem("Steve", "AC");
    ob.additem("Bill", "RB");
    ob.additem("Marie", "SL");
    ob.additem("Susan", "w");
    ob.additem("Joe", "GT");
    ob.printiteminindex(2);
    /*while (name != "exit")
    {
        cout << "Search for ";
        cin >> name;
        if (name != "exit")
        {
            ob.finddrink(name);
        }
    }*/
    while (name != "exit")
    {
        cout << "Remove  ";
        cin >> name;
        if (name != "exit")
        {
            ob.removeitem(name);
        }
    }
    ob.printiteminindex(2);
    return 0;
}