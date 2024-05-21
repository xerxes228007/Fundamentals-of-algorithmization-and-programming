#ifndef BINSEARCHTREE_H
#define BINSEARCHTREE_H
#include <QString>
class bst{
    struct node
    {
        int key;
        QString str;
        node * left=nullptr;
        node * right=nullptr;
        data(int key, QString s){this->key=key;str=s;}
    };
    node * root=nullptr;

    void push(node * v=root, int key, QString str)
    {

    }

public:
    bst(){}

    void insert(node * v=root,int key,QString str)
    {
        if(v==nullptr)
        {
            v=new node(key,str);
            return;
        }
        if(key<=v->key)
        {
            insert(v->left,key,str);
            return;
        }
        insert(v->right,key,str);
    }

    QString find(node * v =root,int key)
    {
        if(v==nullptr)
            return "";
        if(v->key==key)
            return v->str;
        if(key<=v->key)
        {
            find(v->left,key);
            return;
        }
        find(v->right,key);

    }

    void remove();

    int height();

    void balance();

    void Lrotate();

    void Rrotate();

    int leaves();

    //orders
    void preOrder();

    void inOrder();

    void postOrder();
};

#endif // BINSEARCHTREE_H
