#include <bits/stdc++.h>
#include "hash.h"
using namespace std;
Hash::Hash()
{
    for (int i = 0; i < tablesize; i++)
    {
        Hashtable[i] = new item;
        Hashtable[i]->name = "empty";
        Hashtable[i]->drink = "empty";
        Hashtable[i]->next = NULL;
    }
}
void Hash::additem(string name, string drink)
{
    int index = HashS(name);
    if (Hashtable[index]->name == "empty")
    {
        Hashtable[index]->name = name;
        Hashtable[index]->drink = drink;
    }
    else
    {
        item *ptr = Hashtable[index];
        item *n = new item;
        n->name = name;
        n->drink = drink;
        n->next = NULL;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = n;
    }
}
int Hash::numberofiteminindex(int index)
{
    int cnt = 0;
    if (Hashtable[index]->name == "empty")
    {
        return cnt;
    }
    else
    {
        cnt++;
        item *ptr = Hashtable[index];
        while (ptr->next != NULL)
        {
            cnt++;
            ptr = ptr->next;
        }
    }
    return cnt;
}

int Hash::HashS(string key)
{
    int hash = 0;
    int index;
    for (int i = 0; i < key.length(); i++)
    {
        hash += (int)key[i];
    }
    index = hash % tablesize;

    return index;
}

void Hash::printtable()
{
    int num;
    for (int i = 0; i < tablesize; i++)
    {
        num = numberofiteminindex(i);
        cout << "-----------------\n";
        cout << "index" << i << endl;
        cout << Hashtable[i]->name << endl;
        cout << Hashtable[i]->drink << endl;
        cout << "NO. of items" << num << endl;
        cout << "-----------------\n";
    }
}

void Hash::printiteminindex(int index)
{
    item *ptr = Hashtable[index];
    if (ptr->name == "empty")
    {
        cout << "index" << index << " is empty" << endl;
    }
    else
    {
        cout << "index " << index << " container the following item\n";
        while (ptr != NULL)
        {
            cout << "-----------------\n";
            cout << ptr->name << endl;
            cout << ptr->drink << endl;
            cout << "-----------------\n";
            ptr = ptr->next;
        }
    }
}

void Hash::finddrink(string name)
{
    int index = HashS(name);
    bool foundname = false;
    string drink;
    item *ptr = Hashtable[index];
    while (ptr != NULL)
    {
        if (ptr->name == name)
        {
            foundname = true;
            drink = ptr->drink;
        }
        ptr = ptr->next;
    }
    if (foundname == true)
    {
        cout << "Favorite drink = " << drink << endl;
    }
    else
    {
        cout << name << " not found" << endl;
    }
}

void Hash::removeitem(string name)
{
    int index = HashS(name);
    item *delptr;
    item *ptr1;
    item *ptr2;
    // case 0 - bucket is empty
    if (Hashtable[index]->name == "empty" && Hashtable[index]->drink == "empty")
    {
        cout << name << "was not found in the Hash Table\n";
    }
    // case 1 - only 1 item contained in the bucket and that item has mactching name
    else if (Hashtable[index]->name == name && Hashtable[index]->next == NULL)
    {
        Hashtable[index]->name = "empty";
        Hashtable[index]->drink = "empty";

        cout << name << " was removed from the Hashtable\n";
    }
    // case 2 - match is located in the first item in the bucket but there are more item in the bucket
    else if (Hashtable[index]->name == name)
    {
        delptr = Hashtable[index];
        Hashtable[index] = Hashtable[index]->next;
        delete delptr;

        cout << name << " was removed from the Hashtable\n";
    }

    // case 3 - bucket contains items bit first itme is not a match
    else
    {
        ptr1 = Hashtable[index]->next;
        ptr2 = Hashtable[index];
        while (ptr1 != NULL && ptr1->name != name)
        {
            ptr2 = ptr1;
            ptr1 = ptr1->next;
        }
        // case 3.1- no match
        if (ptr1 == NULL)
        {
            cout << name << " was not found from the Hashtable\n";
        }
        // case 3.2 match is found
        else
        {
            delptr = ptr1;
            ptr1 = ptr1->next;
            ptr2->next = ptr1;

            delete delptr;
            cout << name << " was removed from the Hashtable\n";
        }
    }
}