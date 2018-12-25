#include "regularfunctions.h"

// -2: нет регулярного выражения
// -1: не подходит под шаблон
// >=0: индекс последнего символа шаблонной части
int mystr::find_regular(const char * str, int str_index, const char * find, int find_index)
{
    switch (find[find_index])
    {
    case '.':
        if (point(str, str_index, find, find_index) == 0) {
            return str_index;
        }
        return -1;
    case '*':
        return star(str, str_index, find, find_index);
    case '{':
        repeat(str, str_index, find, find_index);
    default:
        return -2;
    }
}

bool mystr::point(const char * str, int str_index, const char * find, int find_index)
{
    if (strlen(find) == 1) {
        return str_index;
    }
    return mystr::strlen(str)<=str_index;
}

int mystr::star(const char * str, int str_index, const char * find, int find_index)
{
    int findLength = strlen(find);
    int strLength = strlen(str);

    if (findLength == 1) {
        return strLength - 1;
    }

    if (find_index == findLength - 1) {
        return strLength-1;
    }

    while (str_index < strLength){
        if (find[find_index + 1] == str[str_index]) {
            return str_index - 1;
        }

        ++str_index;
    }
    return -1;
}

int mystr::repeat(const char * str, int str_index, const char * find, int find_index)
{
    int findLength = strlen(find);
    int strLength = strlen(str);

    int secondBracket;
    bool correctly = false;
    int commaPos = -1;
    for (int i = find_index+1; i < findLength; i++)
    {
        if (find[i] == '}'){
            correctly = true;
            secondBracket = i;
        }
        if (find[i] == ',') {
            commaPos = i;
        }
    }
    if (!correctly) {
        return -1;
    }

    /* type:
    *	0: {n,m}
    *	1: {n,}
    *	2: {,m}
    *	3: {n}
    */
    int type = 0;
    if (commaPos == -1) {
        type = 3;
    }
    else if (commaPos == secondBracket - 1) {
        type = 1;
    }
    else if (commaPos == find_index + 1) {
        type = 2;
    }
    else {
        type = 0;
    }

    int n = 0;
    int m = 0;
    bool wasComma = false;
    int tempCharSize = secondBracket - find_index - 1;
    char *tempChar = new char[tempCharSize];
    for (int i = find_index + 1, j = 0; i < secondBracket; i++, j++) {
        tempChar[j] = find[i];
    }
    switch (type)
    {
    case 0:
        for (int i = tempCharSize - 1; i > 0; --i)
        {
            if (tempChar[i] == ',') {
                wasComma = 1;
            }
            else {
                if (!wasComma) {
                    m += pow(10, i)*(int)(tempChar[i] - '0');
                }
                else {
                    n += pow(10, i)*(int)(tempChar[i] - '0');
                }
            }
        }
        break;
    case 1:
        for (int i = tempCharSize-2; i >= 0; --i)
        {
            n += pow(10, i)*(int)(tempChar[i] - '0');
        }
        m = INT_MAX;
        break;
    case 2:
        for (int i = tempCharSize-1; i > 0; --i)
        {
            m += pow(10, i)*(int)(tempChar[i] - '0');
        }
        n = 0;
        break;
    case 3:
        for (int i = tempCharSize - 1; i >= 0; --i)
        {
            n += pow(10, i)*(int)(tempChar[i] - '0');
        }
        m = n;
        break;
    }
    delete[]tempChar;

    int repeats = 0;
    const char letter = find[find_index - 1];
    int i = str_index + 1;
    int j = 0;
    while (i < strLength && str[i] != letter)
    {
        ++i;
        ++j;
    }


    if (j >= n && j <= m) {
        return i;
    }
    else {
        return -1;
    }
}
