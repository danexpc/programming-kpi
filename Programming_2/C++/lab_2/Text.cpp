//
// Created by Danil on 24.02.2020.
#include <cstring>
#include <iostream>
#include <utility>
#include "Text.h"
#include <cctype>
using namespace std;

Text::Text() = default;

Text::Text(vector<MyString> arr) {
    text = move(arr);
}

void Text::AddLine(const MyString& line) {
    text.push_back(line);
}

void Text::DeleteLine(int index) {
    text.erase(text.begin() + index);
}

void Text::Clear() {
    text.clear();
}

int Text::TheShortestLine() {
    int min = text[0].getSize();
    for (MyString string : text)
    {
        if (string.getSize() < min)
        {
            min = string.getSize();
        }
    }
    return min;
}

double Text::PercentConsonantLetter() {
    vector<char> letters{'a', 'e', 'i', 'o', 'u', 'y'};
    int allLetter(0);
    double countConsonant(0);
    for (MyString string : text)
    {
        for (int i = 0; i < string.getSize(); ++i) {
            if (isalpha(string.str[i])) {
                allLetter++;
                bool ifConsonant = true;
                for (char c : letters)
                {
                    if (c == string.str[i])
                    {
                        ifConsonant = false;
                        break;
                    }
                }
                if (ifConsonant)
                {
                    countConsonant++;
                }
            }
        }
    }
    return (countConsonant / allLetter) * 100;
}

void Text::deleteExtraSpace() {
    for (int i = 0; i < text.size(); ++i)
    {
        text[i].deleteSpace();
    }
}

void Text::deleteBeginEndSpace() {
    for (int i = 0; i < text.size(); ++i)
    {
        text[i].deleteBeginEndSpace();
    }
}

void Text::PrintText() {
    for (MyString string : text)
    {
        cout << string.getString() << endl;
    }
}





