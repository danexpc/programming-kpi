//
// Created by Danil on 24.03.2020.
//

#ifndef LAB_5_TASK2_NUMBERS_H
#define LAB_5_TASK2_NUMBERS_H


#include "Rows.h"

class Numbers  : public Rows{
public:
    Numbers(int size, const char array[]);
    void extend() override;
};


#endif //LAB_5_TASK2_NUMBERS_H
