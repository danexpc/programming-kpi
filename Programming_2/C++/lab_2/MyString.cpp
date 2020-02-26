//
// Created by Danil on 24.02.2020.
//

#include "MyString.h"
#include <cstring>
#include <iostream>

MyString::MyString() {
    str = nullptr;
    size = 0;
}

MyString::MyString(char *arr) {
    size = strlen(arr);
    str =  new char[size+1];
    for (int i = 0; i < size; ++i) {
        str[i] = arr[i];
    }
    str[size] = '\0';
}

MyString::~MyString() {
    delete [] str;
}

const char *MyString::getString() {
    return str;
}

MyString::MyString(const MyString &myString) {
    size = strlen(myString.str);
    str = new char[size + 1];
    for (int i = 0; i < size; ++i) {
        str[i] = myString.str[i];
    }
    str[size] = '\0';
}

int MyString::getSize() {
    return size;
}

void MyString::deleteSpace() {
    int countSpace = 0;
    for (int i = 0; i < size; ++i) {
        if (str[i] == ' ' and str[i+1] == ' ')
        {
            countSpace++;
        }
    }
    char* temp = new char[size+1-countSpace];

    for (int j = 0, k = 0; j < size; ++j) {
        if (str[j] == ' ' and str[j+1] == ' ')
        {
            continue;
        }
        temp[k] = str[j];
        k++;
    }

    temp[size-countSpace] = '\0';
    delete[] str;
    str = temp;

}

void MyString::deleteBeginEndSpace() {
    int count1(0);
    int count2(0);
    for (int i = 0; str[i] == ' ' ; ++i, count1++);
    for (int j = size-1; str[j] == ' '; --j, count2++);
    char* temp = new char[size+1-count1-count2];

    for (int j = count1, k = 0; k != size-count1-count2; ++j) {
        temp[k] = str[j];
        k++;
    }
    temp[size-count1-count2] = '\0';
    delete[] str;
    str = temp;
}

MyString &MyString::operator =(const MyString &myString) {
    this->size = myString.size;
    if (this->str != nullptr)
    {
        delete[] str;
    }
    str = new char[size+1];
    for (int i = 0; i < size; ++i) {
        str[i] = myString.str[i];
    }
    str[size] = '\0';
}

