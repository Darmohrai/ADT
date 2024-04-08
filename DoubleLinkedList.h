//
// Created by HP on 07.04.2024.
//

#ifndef ADT_DOUBLELINKEDLIST_H
#define ADT_DOUBLELINKEDLIST_H

#include <iostream>
#include <memory>

template<typename T>
class DoubleLinkedList {
private:
    struct Node {
        T data;
        std::shared_ptr<Node> next;
        std::weak_ptr<Node> previous;

        Node(T data) : data{data} {};
    };

    std::shared_ptr<Node> head = nullptr;
    std::shared_ptr<Node> tail = nullptr;
    size_t size = 0;
public:
    DoubleLinkedList() = default;

    void pushFront(T value) {
        std::shared_ptr<Node> newNode = std::make_shared<Node>(value);
        if (head == nullptr) {
            head = tail = newNode;
            head->next = nullptr;
            size++;
            return;
        }
        newNode->next = head;
        head->previous = newNode;
        head = newNode;
        size++;
    }

    void pushBack(T value) {
        std::shared_ptr<Node> newNode = std::make_shared<Node>(value);
        if (head == nullptr) {
            head = tail = newNode;
            head->next = nullptr;
            size++;
            return;
        }
        newNode->previous = tail;
        tail->next = newNode;
        tail = newNode;
        size++;
    }

    void popFront() {
        if (head == nullptr) return;
        if (head == tail) {
            head = tail = nullptr;
            return;
        }
        head = head->next;
    }

    [[nodiscard]] bool isListNotEmpty() {
        if (size > 0) return true;
        else return false;
    }

    friend std::ostream &operator<<(std::ostream &os, DoubleLinkedList &other) {
        Node *current = other.head.get();
        while (current != nullptr) {
            os << current->data << " ";
            current = current->next.get();
        }
        os << std::endl;
        return os;
    }

    ~DoubleLinkedList() = default;
};

#endif //ADT_DOUBLELINKEDLIST_H
