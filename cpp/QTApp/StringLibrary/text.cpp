#include "text.h"


mystr::Text::Text()
{
}

mystr::Text::Text(int str_amount)
{
    if(str_amount > 0){
        text = Vector<String>(str_amount);
    }
}

mystr::Text::~Text()
{
}

mystr::Text & mystr::Text::operator=(const Text & other)
{
    this->text = other.text;
    return *this;
}

bool mystr::Text::operator==(mystr::Text &other)
{
    if(this->get_length()!=other.get_length()){
        return false;
    }
    for(int i = 0; i < this->text.getSize(); i++){
        if(!(this->text[i] == other.text[i])){
            return false;
        }
    }
    return true;
}

bool mystr::Text::operator>(Text & other)
{
    return this->get_length() > other.get_length();
}

bool mystr::Text::operator<(Text & other)
{
    return this->get_length() < other.get_length();
}

mystr::Vector<mystr::Vector<int>> mystr::Text::find(const char * str)
{
    mystr::Vector<mystr::Vector<int>> result;
    for (int i = 0; i < text.getSize(); i++) {
        result[i] = text[i].find(str);
    }
    return result;
}

mystr::Vector<mystr::Vector<int>> mystr::Text::find(String & str)
{
    return find(str.getCPtr());
}

int mystr::Text::replace(const char * find, const char * place)
{
    int result = 0;
    for (int i = 0; i < text.getSize(); i++) {
        result += text[i].replace(find, place);
    }
    return result;
}

int mystr::Text::replace(String & find, String & place)
{
    return replace(find.getCPtr(), place.getCPtr());
}

int mystr::Text::find_amount(const char * str)
{
    int result = 0;
    for (int i = 0; i < text.getSize(); i++) {
        result += text[i].find_amount(str);
    }
    return result;
}

int mystr::Text::find_amount(String & str)
{
    return find_amount(str.getCPtr());
}

int mystr::Text::get_length()
{
    int result = 0;
    for (int i = 0; i < text.getSize(); i++)
        result += text[i].getSize();
    return result + text.getSize();
}
