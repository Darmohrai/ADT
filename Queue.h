//
// Created by HP on 09.04.2024.
//

#ifndef ADT_QUEUE_H
#define ADT_QUEUE_H

#include "DoubleLinkedList.h"

template<typename T>
class Queue {
private:
    DoubleLinkedList<T> list;
public:
    void Enqueue(T value) {
        list.pushBack(value);
    }

    T Dequeue() {
        T date = list.index(0);
        list.popFront();
        return date;
    }

    T peek() {
        T date = list.index(0);
        return date;
    }

    void isEmpty() { return !list.isListNotEmpty(); }

    void isFull(){ return list.isListNotEmpty(); }
};

#endif //ADT_QUEUE_H
