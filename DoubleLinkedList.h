//
// Created by HP on 07.04.2024.
//

#ifndef ADT_DOUBLELINKEDLIST_H
#define ADT_DOUBLELINKEDLIST_H

#include <iostream>
#include <memory>

template<typename T>
class DoubleLinkedList{
private:
    struct Node{
        T data;
        std::shared_ptr<Node> next;
        std::weak_ptr<Node> previous;

        Node(T data) : data{data}{};
    };

    std::unique_ptr<Node> head = nullptr;
    std::unique_ptr<Node> tail = nullptr;
    size_t size = 0;
public:
    DoubleLinkedList() = default;

    ~DoubleLinkedList() = default;
};

#endif //ADT_DOUBLELINKEDLIST_H
