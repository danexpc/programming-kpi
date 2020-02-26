//
// Created by Danil on 24.02.2020.
//

#ifndef LAB_2_OP_MYSTRING_H
#define LAB_2_OP_MYSTRING_H


class MyString {
    friend class Text;
public:
    MyString();
    explicit MyString(char *arr);
    MyString(const MyString &myString);
    MyString &operator=(const MyString& myString);
    void deleteSpace();
    void deleteBeginEndSpace();
    int getSize();
    const char* getString();
    ~MyString();
private:
    char *str;
    int size;
};


#endif //LAB_2_OP_MYSTRING_H
