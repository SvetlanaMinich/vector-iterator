#include<iostream>

template<class T>
class ConstIterator
{
private:
    const T* it;
public:
    using iterator_category = std::random_access_iterator_tag;
    ConstIterator(){
        it = nullptr;
    };
    ConstIterator(T* i){
        it = i;
    };
    ConstIterator(const ConstIterator<T>& i){
        this->it = i.it;
    };
    const T* operator->(){
        return it;
    };
    bool operator!=(const ConstIterator& i){
        return it!=i.it;
    };
    ConstIterator& operator=(const ConstIterator& i){
        it = i.it;
        return *this;
    };
    const T& operator*(){
        return *it;
    };
    const T* getPointer(){
        return it;
    };
};
