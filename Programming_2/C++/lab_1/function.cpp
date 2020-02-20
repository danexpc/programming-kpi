//
// Created by Danil on 12.02.2020.
//

#include "function.h"

int addition(int a, int b)
{
    int sum = a;
    while(b != 0)
    {
        sum = ~-sum;
        b = -~b;
    }
    return sum;
}

bool comparison(int a, int b)
{
    return (a ^ b) == 0;
}
