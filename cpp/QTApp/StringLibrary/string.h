#pragma once
#ifndef STRING_H
#define STRING_H
#include <iostream>
#include "strfunctions.h"
#include "vector.h"
#include "regularfunctions.h"
#include "pair.h"

typedef mystr::Vector<Pair<int, int>> vecPairII;
typedef Pair<int[2], bool> pairI2B;
typedef Pair<int, int> pairII;

namespace mystr {

class String
{
public:
    String();
    String(const char *str);
    //String(const int size);
    String(const String &other);

    ~String();

    String & operator = (const String &other);

    char operator[](const int index);

    bool operator>(String & other);
    bool operator<(String & other);
    bool operator==(String & other);

    void print();

    int getSize();
    const char* getCPtr();

    Vector<int> find(const char *str);
    Vector<int> find(String &str);

    int replace(const char *find, const char *place);
    int replace(String &find, String &place);

    int find_amount(const char *str);
    int find_amount(String &str);

protected:
    char *str;
    int size;

    void change_size(int size);
};
}
#endif // STRING_H
