#ifndef STACK_H
#define STACK_H

template<typename T>
class stack
{
    long long size_=0;
    T data[__INT16_MAX__];
public:
    stack(){}
    void clear()
    {
        while(!empty())
            pop();
    }

    void push(const T& value)
    {
        //size_++;
        data[size_++]=value;
    }

    void pop()
    {
        size_--;
    }

    T &peek()
    {
        if(size_>0)
        return data[size_-1];
        throw "Stack empty";
    }
    bool empty()
    {
        return size_==0;
    }
    int size()
    {
        return size_;
    }
};

#endif // STACK_H
