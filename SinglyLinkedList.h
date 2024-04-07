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

        Node(T value, Node *ptr) : date{value} { next = std::make_unique<Node>(*ptr); };
    };

    std::unique_ptr<Node> head = nullptr;
    size_t size;

public:
    SinglyLinkedList() : head{nullptr}, size{0} {};

    SinglyLinkedList(SinglyLinkedList &&other) {
        head = std::move(other.head);
        size = other.size;
        other.size = 0;
    }

    void checkIndex(int index) const {
        if (index < 0 or index >= size) throw std::out_of_range("Index out of range");
    }

    void pushFront(T value) {
        if (head == nullptr) {
            head = std::make_unique<Node>(value);
            size++;
            return;
        }
        std::unique_ptr<Node> newNode = std::make_unique<Node>(value);
        newNode->next = std::move(head);
        head = std::move(newNode);
        size++;
    };

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

    void popFront() {
        if (head == nullptr)return;
        //Node* newNode = head.get();
        head = std::move(head->next);
        size--;
    }

    void popBack() {
        if (head == nullptr) return;
        if (head->next == nullptr) {
            head = nullptr;
            size--;
            return;
        }
        Node *current = head.get();
        while (current->next->next != nullptr) {
            current = current->next.get();
        }
        current->next = nullptr;
        size--;
    }

    T index(int index) {
        checkIndex(index);
        Node *current = head.get();
        for (int i = 0; i < index; i++) {
            current = current->next.get();
        }
        return current->date;
    };

    void insertAtIndex(int index, T value) {
        checkIndex(index);
        Node *current = head.get();
        if (index == 0) {
            std::unique_ptr<Node> newNode = std::make_unique<Node>(value);
            newNode->next = std::move(head);
            head = std::move(newNode);
            size++;
        } else {
            for (int i = 0; i < index - 1; i++) {
                current = current->next.get();
            }
            std::unique_ptr<Node> newNode = std::make_unique<Node>(value);
            newNode->next = std::move(current->next);
            current->next = std::move(newNode);
            size++;
        }
    }

    void removeAtIndex(int index) {
        checkIndex(index);
        if (index == 0) {
            head = std::move(head->next);
            size--;
        } else {
            Node *current = head.get();
            for (int i = 0; i < index - 1; i++) {
                current = current->next.get();
            }
            current->next = std::move(current->next->next);
            size--;
        }
    }

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

    [[nodiscard]]size_t showSize() { return size; }

    [[nodiscard]] bool isListEmpty() { if (size > 0) return true; }

    ~SinglyLinkedList() =
    default;
};


#endif //ADT_SINGLYLINKEDLIST_H
