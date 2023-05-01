#ifndef CONSTITERATOR_H
#define CONSTITERATOR_H
#include<iostream>

template<class T>
class ConstIterator
{
private:
    const T* it;
public:
    using iterator_category = std::random_access_iterator_tag;
    ConstIterator();
    ConstIterator(T* i);
    ConstIterator(const ConstIterator<T>& i);
    const T* operator->();
    bool operator!=(const ConstIterator& i);
    ConstIterator& operator=(const ConstIterator& i);
    const T& operator*();
    const T* getPointer();
};

#endif // CONSTITERATOR_H
