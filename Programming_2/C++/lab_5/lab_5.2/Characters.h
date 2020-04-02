//
// Created by Danil on 24.03.2020.
//

#ifndef LAB_5_TASK2_CHARACTERS_H
#define LAB_5_TASK2_CHARACTERS_H


#include "Rows.h"

class Characters : public Rows{
public:
    Characters(int size, const char array[]);
    void extend() override;
};


#endif //LAB_5_TASK2_CHARACTERS_H
