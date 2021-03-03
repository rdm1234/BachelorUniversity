#include "string.h"

namespace mystr {

String::String()
{
    str = nullptr;
    size = 0;
}

String::String(const char *str) : String()
{
    change_size(strlen(str));
    for (int i = 0; i < this->size; i++)
        this->str[i] = str[i];
}

String::String(const String &other) : String()
{
    this->change_size(other.size);
    for (int i = 0; i < this->size; i++)
        this->str[i] = other.str[i];
}

String::~String()
{
    if (str != nullptr)
        delete[]this->str;
}

String & String::operator=(const String &other)
{
    this->change_size(other.size);
    for (int i = 0; i < this->size; i++)
        this->str[i] = other.str[i];
    return *this;
}

char String::operator[](const int index)
{
    return (char)str[index];
}

bool String::operator>(String & other)
{
    return this->getSize() > other.getSize();
}

bool String::operator<(String & other)
{
    return this->getSize() < other.getSize();
}

bool String::operator==(String &other)
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

void String::print()
{
    if(str!=nullptr)
        std::cout << str << std::endl;
}

int String::getSize()
{
    return size;
}

const char * String::getCPtr()
{
    return str;
}

Vector<int> String::find(const char * str)
{
    if (strlen(str) > this->size)
        return 0;
    Vector <int> result;
    int iThis = 0;
    int iOther = 0;
    int startFindId = 0;

    int find_string_len = strlen(str);

    while (iThis < this->size) {
        int regular_find_result = find_regular(this->str, iThis, str, iOther);

        if (regular_find_result == -2) {
            if (str[iOther] == this->str[iThis]){
                iThis++;
                iOther++;
            }
            else {
                iOther = 0;
                iThis++;
                startFindId = iThis;
            }
        }
        else {
            if (regular_find_result >= 0) {
                if (str[iOther] == '{'){
                    do {
                        iOther++;
                    }
                    while (str[iOther] != '}');
                    iOther++;
                }

                iOther++;
                iThis = regular_find_result + 1;
            }
            else {
                iOther = 0;
                iThis++;
                startFindId = iThis;
            }
        }

        if (iOther >= find_string_len) {
            result.push_back(startFindId);
            iOther = 0;
            startFindId = iThis;
        }
    }
    return result;
}

Vector<int> String::find(String & str)
{
    return find(str.str);
}

int String::replace(const char * find, const char * place)
{
    int findLength = strlen(find);
    int placeLength = strlen(place);

    if (findLength > this->size)
        return 0;

    Vector<Pair<int, int>> foundPos;

    int sp;
    bool spUsed = false;
    // Поиск подходящих под запрос (в том числе
    // шаблоный) частей строки и добавление первого
    // и последнего индекса таких частей в вектор
    // foundPos
    for (int i = 0, d = 0; i < this->size; i++) {
        int tempReg = find_regular(str, i, find, d);
        // Если подходит под шаблон с регулярным
        // выражением
        if (tempReg >= 0) {
            if (!spUsed) {
                sp = i;
                spUsed = true;
            }
            /*foundPos.push_back(pairII(i - d, tempReg));*/
            i = tempReg;
            //d = 0;
            d++;

        }
        // Если не подходит под шаблон с регулярным
        // выражением
        else if(tempReg == -1){
            d = 0;
            spUsed = false;
        }
        // Если нет регулярного выражения
        else {
            if (find[d] == str[i]) {
                if (!spUsed) {
                    sp = i;
                    spUsed = true;
                }
                d++;
            }
            else {
                // поиск: абс, строка: аабс (без i-=d)
                // не найдёт
                i -= d;
                d = 0;
                spUsed = false;
            }
        }
        if (d == findLength) {
            /*foundPos.push_back(pairII(i - findLength + 1, i));*/
            foundPos.push_back(pairII(sp, i));
            d = 0;
            spUsed = false;
        }
    }

    // Если ничего не найдено
    if (foundPos.getSize() == 0)
        return 0;
    // Поиск размера всех найденных фрагментов
    int foundLength = 0;
    for (int i = 0; i < foundPos.getSize(); i++) {
        foundLength += foundPos[i].second - foundPos[i].first + 1;
    }

    // Новый размер строки
    int newStrSize = this->size + (placeLength*foundPos.getSize() - foundLength);
    char * tempStr = new char[newStrSize + 1];
    tempStr[newStrSize] = '\0';

    // Замена найденных фрагментов
    int iOld = 0;
    int iNew = 0;
    int iF = 0;
    while (iNew < newStrSize) {
        if (iOld != foundPos[iF].first) {
            tempStr[iNew] = this->str[iOld];
            ++iNew;
            ++iOld;
        }
        else {
            for (int i = 0; i < placeLength; i++) {
                tempStr[iNew] = place[i];
                ++iNew;
            }
            iOld = foundPos[iF].second + 1;
            if (iF + 1 < foundPos.getSize())
                ++iF;
        }
    }

    delete[] str;
    str = tempStr;

    return foundPos.getSize();
}

int String::replace(String & find, String & place)
{
    return replace(find.str, place.str);
}

int String::find_amount(const char * str)
{
    return this->find(str).getSize();
}

int String::find_amount(String & str)
{
    return find_amount(str.str);
}

void String::change_size(int size)
{
    if (str != nullptr)
        delete[]this->str;
    if (size == 0){
        str = nullptr;
    }
    else{
        str = new char[size + 1];
        str[size] = '\0';
    }
    this->size = size;
}

}
