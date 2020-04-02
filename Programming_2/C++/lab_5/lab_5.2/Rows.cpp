//
// Created by Danil on 24.03.2020.
//

#include <iostream>
#include "Rows.h"
#include <string>


Rows::Rows(): size(0) {}

Rows::Rows(int size, const char *array): size(size) {
    chars = new char[size+1];
    for (int i = 0; i < size; i++)
    {
        chars[i] = array[i];
    }
    chars[size] = '\0';
}

int Rows::get_size() {
    return size;
}

void Rows::extend() {
    std::string new_add;
    std::cin >> new_add;
    int add_len(new_add.length());
    int new_size(add_len + size);
    if (!new_add.empty()) {
        char *new_chars = new char[new_size + 1];
        for (int i = 0; i < size; i++) {
            new_chars[i] = chars[i];
        }
        for (int i = 0, j = size; i < add_len; i++, j++) {
            new_chars[j] = new_add[i];
        }
        new_chars[new_size] = '\0';
        chars = new_chars;
        size = new_size;
    }

}

const char * Rows::getRows() const {
    return chars;
}

std::ostream &operator<<(std::ostream &stream, const Rows &rows) {
    stream << rows.getRows() << std::endl;
}


