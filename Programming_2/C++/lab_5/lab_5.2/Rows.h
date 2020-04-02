//
// Created by Danil on 24.03.2020.
//

#ifndef LAB_5_TASK2_ROWS_H
#define LAB_5_TASK2_ROWS_H

#include <ostream>

class Rows {
public:
    Rows();
    Rows(int size, const char array[]);
    virtual int get_size();
    virtual void extend();
    [[nodiscard]] const char * getRows() const;
    friend std::ostream&operator<<(std::ostream& stream, const Rows& rows);
protected:
    char *chars{};
    int size;

};


#endif //LAB_5_TASK2_ROWS_H
