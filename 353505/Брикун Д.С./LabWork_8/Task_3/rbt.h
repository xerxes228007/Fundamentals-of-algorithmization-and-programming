#ifndef RBT_H
#define RBT_H
#include "node.h"
#include <memory>
template<class T, class T1>
class RBT {

protected:
    std::shared_ptr<Node<T, T1>> root;

public:
    RBT() : root(nullptr) {}
    ~RBT() {
        clear();
    }
    void add(T key, T1 value){
        std::shared_ptr<Node<T, T1>> tmp = root, p = std::shared_ptr<Node<T, T1>>();

        while (tmp) {
            p = tmp;

            if (tmp->key > key) {
                tmp = tmp->left;
            } else if (tmp->key < key) {
                tmp = tmp->right;
            } else {
                return;
            }
        }

        tmp = std::shared_ptr<Node<T, T1>>(new Node<T, T1>(key, value));
        tmp->parent = p;

        if (p) {
            if (tmp->key > p->key) {
                p->right = tmp;
            } else {
                p->left = tmp;
            }
        } else {
            root = tmp;
        }

        InsCase1(tmp);
        return;
    }
    void remove(T key){
        std::shared_ptr<Node<T, T1>> tmp = root ? find(root, key) : std::shared_ptr<Node<T, T1>>(); // Ищем узел с нужным ключем
        // Повезло повезло, ниче делать не надо если такого узла нет
        if (!tmp) {
            return;
        }

        // Случай, когда дерево состоит из одного узла
        if (tmp->parent.expired() && !tmp->left && !tmp->right) {
            root = std::shared_ptr<Node<T, T1>>(); // Обнуляем корень
            return;
        }

        // Если у узла есть и левый и правый потомок
        if (tmp->left && tmp->right)  {
            // Ищем самый правый узел в левом поддереве
            // Этот узел будет ближайшим меньшим к удаляемому, по значнию ключа
            // Что дает нам возможность переместить его значение в удаляемый узел, и удалять уже новый, но у которого будет либо один, либо ноль потомков
            // При таком способе прийдется рассматривать намного меньшее количество вариантов
            std::shared_ptr<Node<T, T1>> removed = tmp->left;
            while (removed->right) {
                removed = removed->right;
            }
            tmp->data = removed->data;
            tmp->key = removed->key;
            tmp = removed;
        }
        std::shared_ptr<Node<T, T1>> child = tmp->left ? tmp->left : tmp->right;
        // Ищем потомка, если таково имеется
        // Случай, когда потомков нет
        if (!child) {
            if (tmp->color) {// Удаление красного узла не привело бы к разбалансировке дерева
                DelCase1(tmp); // А вот удаление черного узла нарушает свойства красно-черного дерева об одинаковой длинне черных путей
            }
            std::shared_ptr<Node<T, T1>> p = tmp->parent.lock();

            if (p->left == tmp) {// Меняем связи, тем самым удаляя узел, после чего тот выйдет из области видимости
                p->left = child;
            } else {
                p->right = child;
            }
        }
        // Случай, когда потомок есть
        else {
            child->parent = tmp->parent; // Меняем связи
            std::shared_ptr<Node<T, T1>> p = tmp->parent.lock();

            // Меняем связи
            if (tmp->parent.lock()) {
                if (tmp == p->left) {
                    p->left = child;
                } else {
                    p->right = child;
                }
            } else {
                root = child; // Если надо, меняем корень дерева
                // Если удаляемы узел был красным, то никакие свойства не нарушаются
                if (tmp->color) {
                    if (!child->color) {// Если удаляемый узел был черным, а потомок красный, то можем сохранить свойстав дерева, перекрасив потомка в черныйё
                        child->color = 1;
                    } else {
                        DelCase1(child);
                    }
                }
            }
        }
    }
    T1 findValueWithKey(T key){
        auto node = find(root, key);
        if (!node) {
            throw "Key not found";
        }
        return node->data;
    }
    bool contains(T key){
        return find(root, key) != nullptr;
    }
    T1& operator[](T key){
        auto node = find(root, key);
        if (node) {
            return node->data;
        } else {
            add(key, T1());
            node = find(root, key);
            return node->data;
        }
    }
    void clear() {
        clear(root);
        root = nullptr;
    }

protected:
    void clear(std::shared_ptr<Node<T, T1>> node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            node.reset();
        }
    }

    std::shared_ptr<Node<T, T1>> grandparent(std::shared_ptr<Node<T, T1>> node){
        std::shared_ptr<Node<T, T1>> p = node->parent.lock();
        if (p && !p->parent.expired()) {
            return p->parent.lock();
        } else {
            return std::shared_ptr<Node<T, T1>>();
        }
    }

    std::shared_ptr<Node<T, T1>> uncle(std::shared_ptr<Node<T, T1>> node){
        std::shared_ptr<Node<T, T1>> tmp = grandparent(node);

        if (tmp) {
            if (tmp->left == node->parent.lock()) {
                return tmp->right;
            } else {
                return tmp->left;
            }
        }

        return std::shared_ptr<Node<T, T1>>();
    }
    std::shared_ptr<Node<T, T1>> sibling(std::shared_ptr<Node<T, T1>> node){
        if (node->parent.expired()) {
            return std::shared_ptr<Node<T, T1>>();
        }

        std::shared_ptr<Node<T, T1>> p = node->parent.lock();

        if (node == p->left) {
            return p->right;
        } else {
            return p->left;
        }
    }

    void RotateLeft(std::shared_ptr<Node<T, T1>> node){
        std::shared_ptr<Node<T, T1>> right = node->right;

        right->parent = node->parent;
        if (!node->parent.expired()) {
            std::shared_ptr<Node<T, T1>> p = node->parent.lock();

            if (p->left == node) {
                p->left = right;
            } else {
                p->right = right;
            }
        } else {
            root = right;
        }

        node->right = right->left;
        if (right->left) {
            right->left->parent = node;
        }

        node->parent = right;
        right->left = node;
    }
    void RotateRight(std::shared_ptr<Node<T, T1>> node){
        std::shared_ptr<Node<T, T1>> left = node->left;

        left->parent = node->parent;
        if (!node->parent.expired()) {
            std::shared_ptr<Node<T, T1>> p = node->parent.lock();

            if (p->left == node) {
                p->left = left;
            } else {
                p->right = left;
            }
        } else {
            root = left;
        }

        node->left = left->right;
        if (left->right) {
            left->right->parent = node;
        }

        node->parent = left;
        left->right = node;
    }

    void InsCase1(std::shared_ptr<Node<T, T1>> node){
        if (node->parent.expired()) {
            node->color = 1;
        }
        else {
            InsCase2(node);
        }
    }
    void InsCase2(std::shared_ptr<Node<T, T1>> node){
        if (node->parent.lock()->color) {
            return;
        } else {
            InsCase3(node);
        }
    }
    void InsCase3(std::shared_ptr<Node<T, T1>> node){
        std::shared_ptr<Node<T, T1>> u = uncle(node);

        if (u && !u->color) {
            node->parent.lock()->color = 1;
            u->color = 1;
            std::shared_ptr<Node<T, T1>> g = grandparent(node);
            g->color = 0;
            InsCase1(g);
        } else {
            InsCase4(node);
        }
    }
    void InsCase4(std::shared_ptr<Node<T, T1>> node){
        std::shared_ptr<Node<T, T1>> g = grandparent(node), tmp = node;
        std::shared_ptr<Node<T, T1>> p = node->parent.lock();
        if (node == p->right && p == g->left) {
            RotateLeft(p);
            tmp = node->left;
        } else if (node == p->left && p == g->right) {
            RotateRight(p);
            tmp = node->right;
        }

        InsCase5(tmp);
    }
    void InsCase5(std::shared_ptr<Node<T, T1>> node){
        std::shared_ptr<Node<T, T1>> g = grandparent(node);
        std::shared_ptr<Node<T, T1>> p = node->parent.lock();
        p->color = 1;
        g->color = 0;

        if (node == p->left) {
            RotateRight(g);
        } else {
            RotateLeft(g);
        }
    }

    void DelCase1(std::shared_ptr<Node<T, T1>> node){
        if (!node->parent.expired()) {
            DelCase2(node);
        }
    }
    void DelCase2(std::shared_ptr<Node<T, T1>> node){
        std::shared_ptr<Node<T, T1>> s = sibling(node);
        std::shared_ptr<Node<T, T1>> p = node->parent.lock();
        bool scol = s ? s->color : 1;

        if (!scol) {
            p->color = 0;
            s->color = 1;

            if (node == p->left) {
                RotateLeft(p);
            } else {
                RotateRight(p);
            }
        }

        DelCase3(node);
    }
    void DelCase3(std::shared_ptr<Node<T, T1>> node){
        std::shared_ptr<Node<T, T1>> s = sibling(node);
        std::shared_ptr<Node<T, T1>> p = node->parent.lock();

        bool scol = s ? s->color : 1;
        bool lcol = s && s->left ? s->left->color : 1;
        bool rcol = s && s->right ? s->right->color : 1;

        if (p->color && scol && lcol && rcol) {
            if (s) {
                s->color = 0;
            }
            DelCase1(p);
        } else {
            DelCase4(node);
        }
    }
    void DelCase4(std::shared_ptr<Node<T, T1>> node){
        std::shared_ptr<Node<T, T1>> s = sibling(node);
        std::shared_ptr<Node<T, T1>> p = node->parent.lock();

        bool scol = s ? s->color : 1;
        bool lcol = s && s->left ? s->left->color : 1;
        bool rcol = s && s->right ? s->right->color : 1;

        if (!p->color && scol && lcol && rcol) {
            if (s) {
                s->color = 0;
            }
            p->color = 1;
        } else {
            DelCase5(node);
        }
    }
    void DelCase5(std::shared_ptr<Node<T, T1>> node){
        std::shared_ptr<Node<T, T1>> s = sibling(node);
        std::shared_ptr<Node<T, T1>> p = node->parent.lock();

        bool lcol = s->left ? s->left->color : 1;
        bool rcol = s->right ? s->right->color : 1;

        if (s->color) {
            if (node == p->left && rcol && !lcol) {
                s->color = 0;
                s->left->color = 1;
                RotateRight(s);
            } else if (node == p->right && lcol && !rcol) {
                s->color = 0;
                s->right->color = 1;
                RotateLeft(s);
            }
        }

        DelCase6(node);
    }
    void DelCase6(std::shared_ptr<Node<T, T1>> node){
        std::shared_ptr<Node<T, T1>> s = sibling(node);
        std::shared_ptr<Node<T, T1>> p = node->parent.lock();
        s->color = p->color;
        p->color = 1;

        if (node == p->left) {
            if (s->right) {
                s->right->color = 1;
            }
            RotateLeft(p);
        } else {
            if (s->left) {
                s->left->color = 1;
            }
            RotateRight(p);
        }
    }

    std::shared_ptr<Node<T, T1>> find(std::shared_ptr<Node<T, T1>> node, T key){
        while (node) {
            if (node->key > key) {
                node = node->left;
            } else if (node->key < key) {
                node = node->right;
            } else {
                return node;
            }
        }
        return nullptr;
    }

    std::shared_ptr<Node<T, T1>> min(std::shared_ptr<Node<T, T1>> node){
        if (!node) {
            return nullptr;
        }
        while (node->left) {
            node = node->left;
        }
        return node;
    }
    std::shared_ptr<Node<T, T1>> max(std::shared_ptr<Node<T, T1>> node){
        if (!node) {
            return nullptr;
        }
        while (node->right) {
            node = node->right;
        }
        return node;
    }

};

#endif // RBT_H
