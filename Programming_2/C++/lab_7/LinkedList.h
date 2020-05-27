//
// Created by Danil on 16.05.2020.
//

#ifndef LAB_7_LINKEDLIST_H
#define LAB_7_LINKEDLIST_H


#include <ostream>

class LinkedList {

private:
    struct Node
    {
        int value;
        Node *next;
    };

    Node *node = nullptr;

public:
    void CreateNode(int value);
    void AddLast(int value);
    void AddAfterFirst(int value);
    int Count();
    int GetIndexMin();
    void RemoveAfter(int index);
    ~LinkedList();
};


#endif //LAB_7_LINKEDLIST_H
