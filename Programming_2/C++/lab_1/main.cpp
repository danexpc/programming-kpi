#include <iostream>
#include "function.h"


int main() {
    int num1, num2;
    std::cin >> num1 >> num2;
    std::cout << addition(num1, num2) << std::endl;
    std::cout << comparison(num1, num2) << std::endl;
    return 0;
}
