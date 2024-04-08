#include <iostream>
#include "SinglyLinkedList.h"
#include "DoubleLinkedList.h"

int main() {
    // code verification
    DoubleLinkedList<int> obj;
    obj.pushBack(9);
    obj.pushBack(10);
    obj.pushFront(1);
    std::cout << obj;

    obj.removeAtIndex(2);
    std::cout << obj;
    return 0;
}