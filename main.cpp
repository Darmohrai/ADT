#include <iostream>
#include "SinglyLinkedList.h"

void Show(SinglyLinkedList<int> obj) {
    obj.show();
}

int main() {
    // code verification
    SinglyLinkedList<int> obj;
    obj.pushBack(7);
    obj.pushBack(6);
    obj.pushFront(1);
    obj.pushBack(8);
    obj.show();
    //obj.show();

    //Show (std::move(obj));

    obj.removeAtIndex(2);

    std::cout << std::endl;

    obj.show();

    std::cout << "\nindex - " << obj.index(7);
    return 0;
}