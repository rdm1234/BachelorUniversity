#pragma once
#ifndef REGULARFUNCTIONS_H
#define REGULARFUNCTIONS_H


#include "strfunctions.h"
#include <iostream>
#include <math.h>

namespace mystr {
    int find_regular(const char * str, int str_index, const char * find, int find_index);

    bool point(const char * str, int str_index, const char * find, int find_index);

    int star(const char * str, int str_index, const char * find, int find_index);

    int repeat(const char * str, int str_index, const char * find, int find_index);
    int repeat1(const char * str, int str_index, const char * find, int find_index);
}
#endif // REGULARFUNCTIONS_H
