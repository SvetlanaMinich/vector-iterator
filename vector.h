#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <QtCore/qalgorithms.h>
#include "iterator.cpp"
#include "reverseiterator.cpp"
#include "constiterator.cpp"

template<typename T>
class Vector
{
private:
    T* arr;
    size_t _current_size;
    size_t _capacity;
public:
    Vector(int i){
        _capacity = i;
        _current_size = 0;
        arr = new T[_capacity];
    };
    Vector(Vector& add_arr){
        _current_size = add_arr.size();
        _capacity = add_arr.capacity();
        arr = new T[_capacity];
        for(int i=0; i<_current_size; i++){
            arr[i] = add_arr[i];
        }
    };
    Vector(){
        _capacity = 1;
        _current_size = 0;
        arr = new T[_capacity];
    };
    ~Vector(){
        delete[] arr;
    };
    T& operator[](int index){
        return arr[index];
    };
    void assign(Vector& add_arr){
        _capacity = add_arr.capacity();
        _current_size = add_arr.size();
        arr = new T[_capacity];
        for(int i=0; i <_current_size; i++){
            arr[i] = add_arr[i];
        }
        add_arr.clear();
        delete[] add_arr;
    };
    T& at(int index){
        if(index<_current_size){
            return arr[index];
        }
        throw 10;
    };
    T& back(){
        return arr[_current_size-1];
    };
    T* begin(){
        return &arr[0];
    };
    size_t capacity(){
        return _capacity;
    };
    ConstIterator<T> cbegin(){
        return ConstIterator(&arr[0]);
    };
    void clear(){
        _capacity = 1;
        _current_size = 0;
        delete[] arr;
        arr = new T[_capacity];
    };
    T* data(){
        return &arr[0];
    };
    void emplace(T el, int index){
        if(_current_size==_capacity){
            T* add_arr = new T[_current_size];
            for(int i=0; i<_current_size; i++){
                add_arr[i] = arr[i];
            }
            _capacity*=2;
            arr = new T[_capacity];
            for(int i=0; i<_current_size; i++){
                arr[i] = add_arr[i];
            }
            delete[] add_arr;
        }
        T* buf_arr = new T[_current_size];
        for(int i=index, j=0; j<_current_size-index && i<_current_size; i++, j++){
            buf_arr[j] = arr[i];
        }
        arr[index] = el;
        for(int i=index+1, j=0; i<_current_size+1 && j<_current_size; i++,j++){
            arr[i] = buf_arr[j];
        }
        delete[] buf_arr;
        _current_size++;
    };
    void emplace_back(T el){
        if(_current_size == _capacity){
            T* add_arr = new T[_current_size];
            for(int i=0; i<_current_size; i++){
                add_arr[i] = arr[i];
            }
            _capacity*=2;
            arr = new T[_capacity];
            for(int i=0; i<_current_size; i++){
                arr[i] = add_arr[i];
            }
            delete[] add_arr;
        }
        _current_size++;
        arr[_current_size-1] = el;
    };
    bool empty(){
        return _current_size==0;
    };
    T* end(){
        return &arr[_current_size-1];
    };
    void erase(int index){
        T* buf_arr = new T*[_current_size];
        for(int i=0, j=0;i<_current_size && j<_current_size-1;i++, j++){
            buf_arr[j] = arr[i];
            if(i==index){
                i++;
            }
        }
        _current_size--;
        arr = new T[_capacity];
        for(int i=0; i<_current_size; i++){
            arr[i] = buf_arr[i];
        }
        delete[] buf_arr;
    };
    void erase(int index_begin, int index_end); //??
    T& front(){
        return arr[0];
    };
    void insert(int index, T el){
        if(_current_size==_capacity){
            T* add_arr = new T[_current_size];
            for(int i=0; i<_current_size; i++){
                add_arr[i] = arr[i];
            }
            _capacity*=2;
            arr = new T[_capacity];
            for(int i=0; i<_current_size; i++){
                arr[i] = add_arr[i];
            }
            delete[] add_arr;
        }
        T* buf_arr = new T[_current_size];
        for(int i=index, j=0; j<_current_size-index && i<_current_size; i++, j++){
            buf_arr[j] = arr[i];
        }
        arr[index] = el;
        for(int i=index+1, j=0; i<_current_size+1 && j<_current_size; i++,j++){
            arr[i] = buf_arr[j];
        }
        delete[] buf_arr;
        _current_size++;
    };
    void insert(int index_begin, int index_end, T* els); //??
    size_t max_size(){
        return _capacity;
    };
    void pop_back(){
        _current_size--;
        T* buf_arr = new T[_current_size];
        for(int i=0; i<_current_size; i++){
            buf_arr[i] = arr[i];
        }
        arr = new T[_current_size];
        for(int i=0; i<_current_size; i++){
            arr[i] = buf_arr[i];
        }
        delete[] buf_arr;
    };
    void push_back(T el){
        if(_current_size == _capacity){
            T* add_arr = new T[_current_size];
            for(int i=0; i<_current_size; i++){
                add_arr[i] = arr[i];
            }
            _capacity*=2;
            arr = new T[_capacity];
            for(int i=0; i<_current_size; i++){
                arr[i] = add_arr[i];
            }
            delete[] add_arr;
        }
        _current_size++;
        arr[_current_size-1] = el;
    };
    ReverseIterator<T>& rbegin(){
        return ReverseIterator<T>(&arr[_current_size-1]);
    };
    ReverseIterator<T>& rend(){
        return ReverseIterator<T>(&arr[0]);
    };
    void reserve(){
        _capacity = 1;
        _current_size = 0;
        arr = new T[_capacity];
    };
    void resize(size_t new_size){
        if(new_size>=_capacity){
            _capacity*=2;
        }
        T* add_arr = new T[_current_size];
        for(int i=0; i<_current_size; i++){
            add_arr[i] = arr[i];
        }
        if(new_size>=_current_size){
            for(int i=0; i<_current_size;i++){
                arr[i] = add_arr[i];
            }
        }
        else{
            for(int i=0;i<new_size;i++){
                arr[i] = add_arr[i];
            }
        }
        _current_size = new_size;
        delete[] add_arr;
    };
    size_t size(){
        return _current_size;
    };
    void swap(Vector& add_arr){
        qSwap(add_arr, arr);
        qSwap(_current_size, add_arr.size());
        qSwap(_capacity, add_arr.capacity());
    };
};

#endif // VECTOR_H
