//
// Created by Danil on 24.03.2020.
//

#include "Numbers.h"

Numbers::Numbers(int size, const char *array) : Rows(size, array){}

void Numbers::extend() {
    int new_size(size*2);
    char *new_array = new char[new_size + 1];

    for(int i = 0, j = 0; i < size; i++, j+=2)
    {
        new_array[j] = new_array[j+1] = chars[i];
    }
    size = new_size;
    memcpy(chars, new_array, size);
    chars[size] = '\0';
    delete[] new_array;
}
