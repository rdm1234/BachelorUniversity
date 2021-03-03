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
        return repeat(str, str_index - 1, find, find_index);
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
            return str_index;
        }

        ++str_index;
    }

    return str_index;
}

int mystr::repeat(const char * str, int str_index, const char * find, int find_index)
{
    int findLength = strlen(find);
    int strLength = strlen(str);

    // Определение типа шаблона повторов
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

    /* Типы шаблона повторов:
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

    // Получение значений m и n в зависимости от типа шаблона
    int n = 0;
    int m = 0;
    bool wasComma = false;
    int tempCharSize = secondBracket - find_index - 1;
    char *tempChar = new char[tempCharSize];
    for (int i = find_index + 1, j = 0; i < secondBracket; i++, j++) {
        tempChar[j] = find[i];
    }

    int lastTempCharId = tempCharSize - 1;

    int pCount = 0;
    switch (type)
    {
    case 0:
        for (int i = lastTempCharId; i >= 0; --i)
        {
            if (tempChar[i] == ',') {
                wasComma = true;
                pCount = 0;
            }
            else {
                if (!wasComma) {
                    m += pow(10, pCount)*(int)(tempChar[i] - '0');
                    pCount++;
                }
                else {
                    n += pow(10, pCount)*(int)(tempChar[i] - '0');
                    pCount++;
                }
            }
        }
        break;
    case 1:
        for (int i = tempCharSize-2; i >= 0; --i)
        {
            n += pow(10, pCount)*(int)(tempChar[i] - '0');
            pCount++;
        }
        m = INT_MAX;
        break;
    case 2:
        for (int i = tempCharSize-1; i > 0; --i)
        {
            m += pow(10, pCount)*(int)(tempChar[i] - '0');
            pCount++;
        }
        n = 0;
        break;
    case 3:
        for (int i = tempCharSize - 1; i >= 0; --i)
        {
            n += pow(10, pCount)*(int)(tempChar[i] - '0');
            pCount++;
        }
        m = n;
        break;
    }
    delete[]tempChar;

    // Подсчёт максимально возможного количества повторов символа
    int repeats = 1;
    const char letter = find[find_index - 1];
    int i = str_index;
    while (i < strLength && str[i] == letter && repeats < m)
    {
        ++i;
        ++repeats;
    }

    // Если повторов было достаточно
    if (repeats >= n) {
        return i;
    }
    // Повторов было слишком мало, входная строка не подходит под шаблон
    else {
        return -1;
    }
}
