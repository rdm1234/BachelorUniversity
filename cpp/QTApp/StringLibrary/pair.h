#pragma once
#ifndef PAIR_H
#define PAIR_H

template <typename T1, typename T2>
class Pair
{
public:
    T1 first;
    T2 second;
    Pair();
    Pair(T1 first, T2 second);
    ~Pair();
};

template <>
class Pair<int[2], int> {
public:
    int first[2];
    int second;
    Pair();
    Pair(int f0, int f1, int s);
    Pair(int f0);
    Pair<int[2], int> &operator=(const Pair<int[2], int> &);
};

inline Pair<int[2], int>::Pair() {
    first[0] = 0;
    first[1] = 0;
    second = 0;
}

inline Pair<int[2], int>::Pair(int f0, int f1, int s) {
    first[0] = f0;
    first[1] = f1;
    second = s;
}

inline Pair<int[2], int>::Pair(int f0) {
    first[0] = f0;
    first[1] = 0;
    second = 0;
}

inline Pair<int[2], int> & Pair<int[2], int>::operator=(const Pair<int[2], int> &other)
{
    this->first[0] = other.first[0];
    this->first[1] = other.first[1];
    this->second = other.second;
    return *this;
}

template<typename T1, typename T2>
inline Pair<T1, T2>::Pair()
{
}

template<typename T1, typename T2>
inline Pair<T1, T2>::Pair(T1 first, T2 second)
{
    this->first = first;
    this->second = second;
}

template<typename T1, typename T2>
inline Pair<T1, T2>::~Pair()
{
}

#endif // PAIR_H
