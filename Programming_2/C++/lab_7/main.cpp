#include <iostream>
#include "LinkedList.h"

int main() {
    LinkedList linkedList;
    linkedList.AddLast(5);
    linkedList.AddAfterFirst(4);
    linkedList.AddAfterFirst(3);
    linkedList.AddAfterFirst(2);
    std::cout << linkedList.Count() << std::endl;
    int min = linkedList.GetIndexMin();
    linkedList.RemoveAfter(min);
    return 0;
}
