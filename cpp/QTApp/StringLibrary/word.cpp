#include "word.h"

namespace mystr {

Word::Word() : String()
{
}

Word::Word(const char * word) : String ()
{
    int i = 0;
    while (i < mystr::strlen(word)) {
        if (word[i] == ' ')
            break;
        i++;
    }
    char *a = new char[i + 1];
    for (int j = 0; j < i; j++)
        a[j] = word[j];
    a[i] = '\0';
    this->str = a;
}

Word::Word(Word &other)
{
    this->change_size(other.size);
    for(int i = 0; i < this->size; i++){
        this->str[i] = other.str[i];
    }
}

Word &Word::operator=(const Word &other)
{
    this->change_size(other.size);
    for(int i = 0; i < this->size; i++){
        this->str[i] = other.str[i];
    }
    return *this;
}

Word &Word::operator=(const char * word)
{
    this->change_size(strlen(word));
    for (int i = 0; i < this->size; i++){
        this->str[i] = word[i];
    }
}

bool Word::operator>(Word &other)
{
    if(this->size > other.size){
        return true;
    }
    else{
        return  false;
    }
}

bool Word::operator<(Word &other)
{
    if(this->size < other.size){
        return true;
    }
    else{
        return  false;
    }
}


bool Word::operator==(Word &other)
{
    if(this->size != other.size){
        return false;
    }
    for(int i = 0; i < this->size; i++){
        if (this->str[i] != other.str[i]){
            return false;
        }
    }
    return true;
}


}
