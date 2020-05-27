//
// Created by Danil on 16.05.2020.
//

#include "LinkedList.h"

void LinkedList::CreateNode(int value) {
    node = new Node;
    node->value = value;
    node->next = nullptr;
}

void LinkedList::AddLast(int value) {
    Node *current = node;
    if (node == nullptr)
    {
        node = new Node{
                .value = value,
                .next = nullptr
        };
        return;
    }
    while (current->next) current = current->next;
    current->next = new Node{
            .value = value,
            .next = nullptr,
    };

}

void LinkedList::AddAfterFirst(int value) {
    if (node == nullptr)
    {
        node = new Node{
            .value = value,
            .next = nullptr
        };
        return;
    }
    else if (node->next == nullptr)
    {
        node->next = new Node{
                .value = value,
                .next = nullptr,
        };

        return;
    }
    Node *temp = node->next;
    node->next = new Node{
            .value = value,
            .next = temp,
    };
}

int LinkedList::Count() {
    Node *current = node->next;
    if (node == nullptr)
    {
        return -1;
    }
    int counter = 0;
    while (current != nullptr)
    {
        if (current->value % 2 == 0) ++counter;
        if (current->next == nullptr) break;
        current = current->next->next;

    }
    return counter;
}

int LinkedList::GetIndexMin() {
    Node *current = node->next;
    if (node == nullptr)
    {
        return -1;
    }
    int indexMin = 0;
    int min = node->value;
    int loopCounter = 1;
    while (current != nullptr)
    {
        if (current->value < min)
        {
            min = current->value;
            indexMin = loopCounter;
        }
        loopCounter++;
        current = current->next;

    }
    return indexMin;
}

void LinkedList::RemoveAfter(int index) {
    int loopCounter = -1;
    Node *current = node;
    while (current != nullptr)
    {
        loopCounter++;
        if (loopCounter == index) {
            current->next = nullptr;
            break;
        }
        current = current->next;
    }
}

LinkedList::~LinkedList() {
    RemoveAfter(0);
    delete node;
}

