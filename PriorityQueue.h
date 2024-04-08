//
// Created by HP on 09.04.2024.
//

#ifndef ADT_PRIORITYQUEUE_H
#define ADT_PRIORITYQUEUE_H

#include "DoubleLinkedList.h"

template<typename T>
class PriorityQueue {
private:
    struct Priority {
        int priority = 0;
        T data;

        Priority(int priority, T data) : priority{priority}, data{data} {};
    };

    DoubleLinkedList<Priority> list;
public:
    void Enqueue(int priority, T value) {
        Priority search(priority, 0);
        int i = 0;
        if (list.isListNotEmpty()) {
            while (priority >= search.priority) {
                if (i < list.size_list()) {
                    search = list.index(i);
                    i++;
                } else {
                    break;
                }
            }
        }
        if(i > list.size_list()) list.insertAtIndex(i, Priority(priority, value));
        else { list.insertAtIndex(i - 1, Priority(priority, value)); }

    }

    T Dequeue() {
        Priority search(0, 0);
        search = list.index(0);
        list.popFront();
        return search.data;
    }

    T peek() {
        Priority search(0, 0);
        search = list.index(0);
        return search.data;
    }

    void isEmpty() { return !list.isListNotEmpty(); }

    void isFull() { return list.isListNotEmpty(); }
};


#endif //ADT_PRIORITYQUEUE_H
