#ifndef NODE_H
#define NODE_H
#include <memory>
template<class T, class T1>
struct Node {
    Node(T nKey, T1 nValue) : key(nKey), data(nValue), color(0), parent(std::shared_ptr<Node<T, T1>>()), left(nullptr), right(nullptr) {}
    Node() : key(), data(), color(0), parent(nullptr), left(nullptr), right(nullptr) {}
    std::shared_ptr<Node<T, T1>> left, right;
    std::weak_ptr<Node<T, T1>> parent;
    bool color;
    T key;
    T1 data;
};
#endif // NODE_H
