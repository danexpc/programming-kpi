//
// Created by Danil on 24.02.2020.
//

#ifndef LAB_2_OP_TEXT_H
#define LAB_2_OP_TEXT_H

#include <vector>
#include "MyString.h"
using namespace std;

class Text {
public:
    Text();
    explicit Text(vector<MyString> arr);
    void AddLine(const MyString& line);
    void DeleteLine(int index);
    void Clear();
    void PrintText();
    int TheShortestLine();
    double PercentConsonantLetter();
    void deleteExtraSpace();
    void deleteBeginEndSpace();
private:
    vector<MyString> text;
};


#endif //LAB_2_OP_TEXT_H
