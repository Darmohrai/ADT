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

    void checkIndex(int index) const {
        if (index < 0 or index >= size) throw std::out_of_range("Index out of range");
    }

    [[nodiscard]] bool isListNotEmpty() {
        if (size > 0) return true;
        else return false;
    }

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
            size--;
            return;
        }
        head = head->next;
        size--;
    }

    void popBack() {
        if (head == nullptr)return;
        if (head == tail) {
            head = tail = nullptr;
            size--;
            return;
        }
        tail = tail->previous.lock();
        tail->next = nullptr;
        size--;
    }

    [[nodiscard]] T index(int index) {
        checkIndex(index);
        Node *newNode = head.get();
        for (int i = 0; i < index; i++) {
            newNode = newNode->next.get();
        }
        return newNode->data;
    }

    void insertAtIndex(int index, T value) {
        checkIndex(index);
        if (head == tail) {
            tail = std::make_shared<Node>(value);
            head->next = tail;
            tail->previous = head;
            return;
        }
        std::shared_ptr<Node> newNode = std::make_shared<Node>(value);
        if (index == 0) {
            newNode->next = head;
            head->previous = newNode;
            head = newNode;
            return;
        }
        std::shared_ptr<Node> current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        newNode->next = current;
        newNode->previous = current->previous;
        current->previous = newNode;
        newNode->previous.lock()->next = newNode;
    }

    void removeAtIndex(int index) {
        checkIndex(index);
        if (head == tail) return;
        if (index == 0) {
            head = head->next;
            return;
        }
        if (index == size - 1) {
            tail = tail->previous.lock();
            tail->next = nullptr;
            return;
        }
        std::shared_ptr<Node> current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        current->previous.lock()->next = current->next;
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
