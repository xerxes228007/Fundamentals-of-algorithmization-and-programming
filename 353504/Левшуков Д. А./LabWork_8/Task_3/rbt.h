#ifndef RBT_H
#define RBT_H
#include<memory>
template<typename T, typename T1> class RBT
{
public:
    RBT()
    {
        root = nullptr;
    }
    void add(T key, T1 value);
    void remove(T key);
    T1 findValueWithKey(T key);
    bool contains(T key);
    T1& operator[](T key);
    void clear()
    {
        clear(root);
    }

protected:

    struct node
    {
        node* left;
        node*right;
        node*parent;
        bool red;
        T key;
        T1 val;
        node(node*p,node*l,node*r,bool col,T k,T1 v): parent(p), left(l), right(r), red(col), key(std::move(k)), val(std::move(v)) {}
    };

    std::shared_ptr<node> grandparent(std::shared_ptr<node> v)//parent parent
    {
        std::shared_ptr<node>p=v->parent;
        if(p&&p->parent)
            return p->parent;
        return std::shared_ptr<node>();
    }
    std::shared_ptr<node> uncle(std::shared_ptr<node> v)//sibling of parent
    {
        std::shared_ptr<node>g=grandparent(v);
        if(g==nullptr)
            return g;
        if(v->parent==g->left)
            return g->right;
        return g->left;
    }
    std::shared_ptr<node> sibling(std::shared_ptr<node> v)
    {
        if(v->parent->left==v)
            return v->parent->right;
        return v->parent->left;
    }

    void RotateLeft(std::shared_ptr<node> v);
    void RotateRight(std::shared_ptr<node> v);

    void InsCase1(std::shared_ptr<node> v);
    void InsCase2(std::shared_ptr<node> v);
    void InsCase3(std::shared_ptr<node> v);
    void InsCase4(std::shared_ptr<node> v);
    void InsCase5(std::shared_ptr<node> v);

    void DelCase1(std::shared_ptr<node> v);
    void DelCase2(std::shared_ptr<node> v);
    void DelCase3(std::shared_ptr<node> v);
    void DelCase4(std::shared_ptr<node> v);
    void DelCase5(std::shared_ptr<node> v);
    void DelCase6(std::shared_ptr<node> v);

    void clear(node *v)
    {
        if(v==nullptr)
            return;
        clear(v->left);
        clear(v->right);
        delete v;
        v=nullptr;
    }

    std::shared_ptr<node> find(std::shared_ptr<node> v, T key);

    std::shared_ptr<node> min(std::shared_ptr<node> v);
    std::shared_ptr<node> max(std::shared_ptr<node> v);

    //Field
    std::shared_ptr<node> root;
};

#endif // RBT_H
