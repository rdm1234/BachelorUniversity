#pragma once
#ifndef TEXT_H
#define TEXT_H

#include "string.h"
#include "vector.h"

namespace mystr {
class Text
{
public:
    Vector<String> text;

    Text();
    Text(int str_amount);
    ~Text();

    Text & operator=(const Text & other);

    bool operator==(Text & other);
    bool operator>(Text & other);
    bool operator<(Text & other);

    Vector<Vector<int>> find(const char *str);
    Vector<Vector<int>> find(String &str);

    int replace(const char * find, const char * place);
    int replace(String &find, String &place);

    int find_amount(const char *str);
    int find_amount(String &str);

    int get_length();
};
}

#endif // TEXT_H
