#pragma once
#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
namespace mystr {


template <typename T>
class Vector
{
    T *vec;
    int size;
    int capacity;

    void change_size(int add);
    void move(unsigned int shift);
public:
    Vector();
    Vector(int size);
    ~Vector();

    Vector(const Vector &other);
    Vector & operator=(const Vector &other);

    T & operator[] (const int index);
    T & at(const int index);

    void push_back(T data);
    void push_front(T data);
    void pop_back();
    void pop_front();
    void insert(T data, int index);
    void removeAt(int index);
    void clear(bool withCapacity = 0);

    int getSize();
    int getCapacity();

    //void resize();
    void shrink_to_fit();

};

template<typename T>
void Vector<T>::change_size(int add)
{
    T *temp = vec;
    if (size + add == 0) {
        size = 0;
    }
    else if (size + add > 0) {
        size += add;
        if (size > capacity) {
            capacity = size + 10;
            vec = new T[capacity];

            for (int i = 0; i < size - add && i < size; i++) {
                vec[i] = temp[i];
            }
            delete[]temp;
        }

    }
}

template<typename T>
void Vector<T>::move(unsigned int shift)
{
    T *temp = vec;
    size += shift;
    if (size > capacity) {
        capacity = size + 10;
        vec = new T[capacity];
        for (int i = 0; i < size - shift; i++) {
            vec[i + shift] = temp[i];
        }
        for (int i = 0; i < shift; i++) {
            vec[i] = T();
        }
        delete[]temp;
    }
    else {
        for (int i = size - 1; i >= shift; i--) {
            vec[i] = vec[i - shift];
        }
        for (int i = 0; i < shift; i++) {
            vec[i] = T();
        }
    }
}

template<typename T>
Vector<T>::Vector()
{
    vec = new T[5];
    size = 0;
    capacity = 10;
}

template<typename T>
Vector<T>::Vector(int size)
{
    this->size = size;
    capacity = size + 10;
    vec = new T[size + 10];
}

template<typename T>
Vector<T>::~Vector()
{
    if (vec != nullptr)
        delete[]vec;
}

template<typename T>
Vector<T>::Vector(const Vector & other)
{
    this->size = other.size;
    this->capacity = other.capacity;
    this->vec = new T[capacity];
    for (int i = 0; i < size; i++)
        this->vec[i] = other.vec[i];
}

template<typename T>
Vector<T> & Vector<T>::operator=(const Vector<T> & other)
{
    int i = 0;

    if (this->size == other.size) {
        while (i < size)
        {
            this->vec[i] = other.vec[i];
            ++i;
        }
    }
    else {
        if (this->capacity >= other.size) {
            this->size = other.size;
            while (i < size)
            {
                this->vec[i] = other.vec[i];
                ++i;
            }
        }
        else {
            if (this->vec != nullptr)
                delete[]this->vec;
            this->size = other.size;
            this->capacity = other.capacity;
            this->vec = new T[capacity];
            for (int i = 0; i < size; i++)
                this->vec[i] = other.vec[i];
        }
    }

    return *this;
}

template<typename T>
T & Vector<T>::operator[](const int index)
{
    return vec[index];
}

template<typename T>
T & Vector<T>::at(const int index)
{
    if (size == 0)
        throw std::exception();
    if (index >= size)
        throw std::exception();
    return vec[index];
}

template<typename T>
void Vector<T>::push_back(T data)
{
    change_size(1);
    vec[size - 1] = data;
}

template<typename T>
void Vector<T>::push_front(T data)
{
    insert(data, 0);
}

template<typename T>
void Vector<T>::pop_back()
{
    --size;
}

template<typename T>
void Vector<T>::pop_front()
{
    if (size - 1 == 0) {
        size = 0;
    }
    else if (size - 1 > 0) {
        --size;
        for (int i = 0; i < size; i++) {
            vec[i] = vec[i + 1];
        }
    }
    //else {
    //    throw std::exception("size - 1 < 0!");
    //}
}

template<typename T>
void Vector<T>::insert(T data, int index)
{
    T *temp = vec;
    size++;
    if (size > capacity) {
        capacity = size + 10;
        vec = new T[capacity];
        for (int i = 0; i < index; i++)
            vec[i] = temp[i];
        for (int i = size - 1; i > index; i++)
            vec[i] = temp[i - 1];
    }
    else {
        for (int i = size - 1; i > index; i++) {
            vec[i] = vec[i - 1];
        }
    }
    vec[index] = data;
}

template<typename T>
void Vector<T>::removeAt(int index)
{
    --size;
    if (size > 0) {
        for (int i = index; i < size; i++) {
            vec[i] = vec[i + 1];
        }
    }
}

template<typename T>
void Vector<T>::clear(bool withCapacity)
{
    if (withCapacity) {
        if (vec != nullptr)
            delete[] vec;
        capacity = 0;
        vec = nullptr;
    }
    size = 0;
}

template<typename T>
int Vector<T>::getSize()
{
    return size;
}

template<typename T>
int Vector<T>::getCapacity()
{
    return capacity;
}

template<typename T>
void Vector<T>::shrink_to_fit()
{
    capacity = size;
    if (size > 0) {
        T *temp = vec;
        vec = new T[size];
        for (int i = 0; i < size; i++) {
            vec[i] = temp[i];
        }
        delete[]temp;
    }
    else if (vec != nullptr) {
        delete[]vec;
        vec = nullptr;
    }
}
}
#endif // VECTOR_H
