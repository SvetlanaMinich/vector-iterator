#ifndef REVERSEITERATOR_H
#define REVERSEITERATOR_H
#include <iostream>

template<class T>
class ReverseIterator
{
private:
    T* it;
public:
    using iterator_category = std::random_access_iterator_tag;
    ReverseIterator();
    ReverseIterator(T* i);
    ReverseIterator(const ReverseIterator& i);
    ReverseIterator<T>& operator++();
    ReverseIterator<T>& operator--();
    bool operator<(ReverseIterator i);
    bool operator>(ReverseIterator i);
    bool operator==(ReverseIterator i);
    bool operator!=(ReverseIterator i);
    ReverseIterator& operator=(const ReverseIterator& i);
    ReverseIterator& operator=(const ReverseIterator* i);
    T* operator->();
    ReverseIterator operator+(int n);
    ReverseIterator operator-(int n);
    size_t operator-(ReverseIterator i);
    T& operator*();
    T* getPointer() const;
};

#endif // REVERSEITERATOR_H
