#include <iostream>
#include "Rows.h"
#include "Numbers.h"
#include "Characters.h"

int main() {
    char* arr = new char[4]{'k', 'e', 'k', '\0'};
    Characters row(3, arr);
    std::cout << row << row.get_size() << std::endl;
    row.extend();
    std::cout << row << row.get_size();
    return 0;
}
