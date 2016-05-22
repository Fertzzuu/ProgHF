//
// Created by mmarci on 2016.05.16..
//

#ifndef PROGHF_VECTORF_H
#define PROGHF_VECTORF_H

#include <iostream>

template <class T>
class Vector {
    unsigned int _size;
    T* buffer;

public:

    typedef T* Iterator;

    Vector();
    Vector(unsigned int );
    Vector(unsigned int size, const T & initial){
        _size = size;
        buffer = new T[_size];
        for (unsigned int i = 0; i < size; i++)
            buffer[i] = initial;
    }
    Vector(const Vector<T>& v);
    ~Vector();

    unsigned int size() const;
    bool empty() const;
    Iterator begin();
    Iterator end();
    T& front();
    T& back();
    void push_back( T const &v);
    void pop_back();

    void reserve(unsigned int );
    void resize(unsigned int );

    T & operator[](unsigned int );
    Vector<T> & operator=(const Vector<T> &);
    void clear();


};

using namespace std;

template<class T>
Vector<T>::Vector() {
    _size = 0;
    buffer = 0;
}


template<class T>
Vector<T>::Vector(const Vector<T> & v) {
    _size = v._size;
    buffer = new T[_size];
    for (unsigned int i = 0; i < _size; i++)
        buffer[i] = v.buffer[i];
}

template<class T>
Vector<T>::Vector(unsigned int size) {
    _size = size;
    buffer = new T[_size];
}

template<class T>
bool Vector<T>::empty() const {
    return _size == 0;
}

//template<class T>
//Vector<T>::Vector(unsigned int size, const T& initial) {
//    _size = size;
//    buffer = new T[_size];
//    for (unsigned int i = 0; i < size; i++)
//        buffer[i] = initial;
//}

template<class T>
Vector<T>& Vector<T>::operator=(const Vector<T> & v) {
    delete[] buffer;
    _size = v._size;
    buffer = new T [_size];
    for (unsigned int i = 0; i < _size; i++)
        buffer[i] = v.buffer[i];
    return *this;
}

template<class T>
typename Vector<T>::Iterator Vector<T>::begin() {
    return buffer;
}

template<class T>
typename Vector<T>::Iterator Vector<T>::end() {
    return buffer + size();
}

template<class T>
T& Vector<T>::front() {
    return buffer[0];
}

template<class T>
T& Vector<T>::back() {
    return buffer[_size - 1];
}

template<class T>
void Vector<T>::push_back( T const&  v) {
    reserve(_size + 1);
    buffer [_size++] = v;
}

template<class T>
void Vector<T>::pop_back() {
    _size--;
}

template<class T>
void Vector<T>::reserve(unsigned int capacity) {
    T * newBuffer = new T[capacity];

    for (unsigned int i = 0; i < _size; i++)
        newBuffer[i] = buffer[i];

    delete[] buffer;
    buffer = newBuffer;
}

template<class T>
unsigned int Vector<T>::size() const {
    return _size;
}

template<class T>
void Vector<T>::resize(unsigned int size) {
    if (size > _size) {
        reserve(size);
        _size = size;
    }

}

template<class T>
T& Vector<T>::operator[](unsigned int index) {
    return buffer[index];
}

template<class T>
Vector<T>::~Vector() {
    delete[] buffer;
}

template <class T>
void Vector<T>::clear() {
    _size = 0;
    buffer = 0;
}


#endif //PROGHF_VECTORF_H
