#include <iostream>

template<class T>
class ReverseIterator
{
private:
    T* it;
public:
    using iterator_category = std::random_access_iterator_tag;
    ReverseIterator(){
        it = nullptr;
    };
    ReverseIterator(T* i){
        it = i;
    };
    ReverseIterator(const ReverseIterator& i){
        this->it = i.it;
    };
    ReverseIterator<T>& operator++(){
        it++;
        return *this;
    };
    ReverseIterator<T>& operator--(){
        it--;
        return *this;
    };
    bool operator<(ReverseIterator i){
        return this->it<i.it;
    };
    bool operator>(ReverseIterator i){
        return this->it>i.it;
    };
    bool operator==(ReverseIterator i){
        return this->it==i.it;
    };
    bool operator!=(ReverseIterator i){
        return this->it!=i.it;
    };
    ReverseIterator& operator=(const ReverseIterator& i){
        it = i.it;
        return *this;
    };
    ReverseIterator& operator=(const ReverseIterator* i){
        it = i->it;
        return *this;
    };
    T* operator->(){
        return it;
    };
    ReverseIterator operator+(int n){
        it+=n;
        return *this;
    };
    ReverseIterator operator-(int n){
        it-=n;
        return *this;
    };
    size_t operator-(ReverseIterator i){
        return it-i.it;
    };
    T& operator*(){
        return *it;
    };
    T* getPointer() const{
        return it;
    };
};
