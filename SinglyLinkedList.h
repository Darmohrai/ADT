//
// Created by HP on 07.04.2024.
//

#ifndef ADT_SINGLYLINKEDLIST_H
#define ADT_SINGLYLINKEDLIST_H

#include <iostream>
#include <memory>

template<typename T>
class SinglyLinkedList {
private:
    struct Node {
        T date;
        std::unique_ptr<Node> next;
    };
    std::unique_ptr<Node> head = nullptr;
    int size;

public:
    SinglyLinkedList() : head{nullptr}, size{0} {};

};


#endif //ADT_SINGLYLINKEDLIST_H
