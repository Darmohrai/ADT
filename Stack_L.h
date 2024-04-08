//
// Created by HP on 08.04.2024.
//

#ifndef ADT_STACK_L_H
#define ADT_STACK_L_H

#include "DoubleLinkedList.h"

template<typename T>
class Stack_L {
private:
    DoubleLinkedList<T> list;
public:
    void push(T value) { list.pushFront(value); }

    void pop() { list.popBack(); }

    T peek() { return list.index(list.showSize() - 1); }

    bool isEmpty() { return !list.isListNotEmpty(); }
};


#endif //ADT_STACK_L_H
