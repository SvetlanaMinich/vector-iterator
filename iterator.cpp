#include <iostream>

template<class T>
class Iterator
{
private:
    T* it;
public:
    using iterator_category = std::random_access_iterator_tag;
    Iterator(){
        it = nullptr;
    };
    Iterator(T* iter){
        it = iter;
    };
    Iterator(const Iterator<T>& another){
        this->it = another.it;
    };
    Iterator<T>& operator++(){
        it++;
        return *this;
    };
    Iterator<T>& operator--(){
        it--;
        return *this;
    };
    bool operator<(Iterator i){
        return this->it<i.it;
    };
    bool operator>(Iterator i){
        return this->it>i.it;
    };
    bool operator==(Iterator i){
        return this->it==i.it;
    };
    bool operator!=(Iterator i){
        return this->it!=i.it;
    };
    Iterator& operator=(const Iterator& i){
        it = i.it;
        return *this;
    };
    Iterator& operator=(const Iterator* i){
        it = i->it;
        return *this;
    };
    Iterator operator+(int n){
        it+=n;
        return *this;
    };
    Iterator operator-(int n){
        it-=n;
        return *this;
    };
    T* operator->(){
        return it;
    };
    size_t operator-(Iterator i){
        return it-i.it;
    };
    T& operator*(){
        return *it;
    };
    T* getPoiner() const{
        return it;
    };
};
