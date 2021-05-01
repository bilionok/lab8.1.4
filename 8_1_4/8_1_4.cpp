// Дано літерний рядок, який містить послідовність символів s0, ..., sn, ... .
// 1. Вияснити, чи є серед цих символів пара сусідніх букв “no” або “on”.
// 2. Замінити кожну пару сусідніх букв “no” трійкою зірочок “ ***”.
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>

using namespace std;

void Change(char* str, char* str2, int i, int j, const int d);

int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);
    int d;

    char str2[50]; // допоміжний масив

    d = strlen(str); // довжина рядка str

    Change(str, str2, 0, 0, d);

    cout << str << endl;
}


void Change(char* str, char* str2, int i, int j, const int d) {
    if (i < d)
    {
        if (str[i] == 'n' && str[i + 1] == 'o') // провірка на одинакові символи
        {
            str2[j++] = '*';
            str2[j++] = '*';
            str2[j++] = '*';
            Change(str, str2, i + 2, j, d);
        }
        else
        {
            str2[j++] = str[i]; // якщо не проходить умова, то символ записується в масив
            Change(str, str2, i + 1, j, d);
        }
    }
    else
    {
        str2[j] = '\0'; // додає символ кінця рядка
        strcpy(str, str2); // копіює допоміжний масив у вихідний
    }
}
