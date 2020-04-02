//
// Created by Danil on 24.03.2020.
//

#include "Characters.h"

Characters::Characters(int size, const char *array) : Rows(size, array) {}

void Characters::extend() {
    int counter = 0;

    for (int i = 0; i < size; i++)
        counter += chars[i] == 'k' ? 1 : 0;

    int new_size = counter + size;
    char *new_array = new char[new_size];

    for(int i = 0, j = 0; i < size; i++)
    {
        new_array[j] = chars[i];
        j ++;
        if (chars[i] == 'k')
        {
            new_array[j] = 'k';
            j++;
        }
    }
    size = new_size;
    memcpy(chars, new_array, size);
    chars[size] = '\0';
    delete[] new_array;
}

