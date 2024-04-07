#include <iostream>
#include "SinglyLinkedList.h"

void Show(SinglyLinkedList<int>obj){
    obj.show();
}

int main() {
    SinglyLinkedList<int> obj;
    obj.pushBack(7);
    obj.pushBack(6);
    obj.pushFront(1);
    obj.pushBack(8);
    obj.pushFront(2);
    //obj.show();

    //Show (std::move(obj));

    obj.popBack();
    obj.show();
    return 0;
}