//
// Created by HP on 08.04.2024.
//

#ifndef ADT_STACK_H
#define ADT_STACK_H

#include <iostream>


template<size_t MAX_SIZE, typename T>
class Stack {
private:
    T stack[MAX_SIZE] = {};
    int top = -1;
public:
    void push(T value) {
        top++;
        stack[top] = value;
    }

    void pop() { top--; }

    
};

#endif //ADT_STACK_H
