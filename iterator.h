#ifndef ITERATOR_H
#define ITERATOR_H
#include <iostream>

template<class T>
class Iterator
{
private:
    T* it;
public:
    using iterator_category = std::random_access_iterator_tag;
    Iterator();
    Iterator(T* iter);
    Iterator(const Iterator<T>& another);
    Iterator<T>& operator++();
    Iterator<T>& operator--();
    bool operator<(Iterator i);
    bool operator>(Iterator i);
    bool operator==(Iterator i);
    bool operator!=(Iterator i);
    Iterator& operator=(const Iterator& i);
    Iterator& operator=(const Iterator* i);
    Iterator operator+(int n);
    Iterator operator-(int n);
    T* operator->();
    size_t operator-(Iterator i);
    T& operator*();
    T* getPoiner() const;
};



#endif // ITERATOR_H
