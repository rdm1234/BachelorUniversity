#pragma once
#ifndef WORD_H
#define WORD_H

#include "string.h"

namespace mystr
{

class Word : public String
{
public:
    Word();
    Word(const char * word);
    Word(Word & other);
    Word & operator=(const Word & other);
    Word & operator=(const char *);
    bool operator>(Word & other);
    bool operator<(Word & other);
    bool operator==(Word & other);
};

}

#endif // WORD_H
