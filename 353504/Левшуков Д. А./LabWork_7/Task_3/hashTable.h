#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "stack.h"
#include <QVector>
class HashTable
{
protected:
    int mod=3;
    QVector<stack<int>>table;

    bool prime(int x)
    {
        for(int i=2;i*i<=x;i++)
        {
            if(x%i==0)
                return false;
        }
        return true;
    }
    void updMod()
    {
    do{
        mod++;
    }while(!prime(mod));
    }
public:
    int hash(int key)
    {
        return key%mod;
    }
    HashTable(int tableSize)
    {
        mod=tableSize;
        updMod();
        table.resize(mod);
    }
    void insert(int key,int data)
    {
        table[hash(key)].push(data);
    }
    void remove(int key)
    {
        table[hash(key)].pop();
    }
    int size()
    {
        return mod;
    }
    void clear()
    {
        for(int i=0;i<mod;i++)
        {
            while(!table[i].empty())
            table[i].pop();
            //qDebug()<<table[i].size();
        }
    }
    QVector<stack<int>> getTable() const
    {
        return table;
    }
};

#endif // HASHTABLE_H
