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

        Node(T value) : date{value}, next{nullptr} {};
    };

    std::unique_ptr<Node> head = nullptr;
    size_t size;

public:
    SinglyLinkedList() : head{nullptr}, size{0} {};

    SinglyLinkedList(SinglyLinkedList&& other) {
        head = std::move(other.head);
        size = other.size;
        other.size = 0;
    }

    void pushBack(T value) {
        if (head == nullptr) {
            head = std::make_unique<Node>(value);
            size++;
            return;
        }
        Node *current = head.get();
        while (current->next != nullptr) {
            current = current->next.get();
        }
        current->next = std::make_unique<Node>(value);
        size++;
    };


    void show() {
        if (head == nullptr) {
            std::cout << "List is empty";
            return;
        }
        Node *current = head.get();
        while (current != nullptr) {
            std::cout << current->date << " ";
            current = current->next.get();
        }
        std::cout << "size - " << size;
    };

    ~SinglyLinkedList() = default;
};


#endif //ADT_SINGLYLINKEDLIST_H
