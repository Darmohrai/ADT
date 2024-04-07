#include <iostream>
#include "SinglyLinkedList.h"
#include "DoubleLinkedList.h"

int main() {
    // code verification
    DoubleLinkedList<int> obj;
    obj.pushBack(9);
    obj.pushFront(3);
    obj.pushFront(8);
    obj.pushBack(2);
    obj.pushFront(1);

    std::cout << obj;
    return 0;
}