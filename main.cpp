#include <iostream>
#include "SinglyLinkedList.h"
#include "DoubleLinkedList.h"

int main() {
    // code verification
    DoubleLinkedList<int> obj;
    obj.pushBack(9);
    std::cout << obj;
    obj.pushBack(10);
    obj.pushFront(1);
    obj.popBack();

    std::cout << obj;
    return 0;
}