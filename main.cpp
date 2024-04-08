#include <iostream>
#include "SinglyLinkedList.h"
#include "DoubleLinkedList.h"
#include "Stack.h"
#include "Stack_L.h"
#include "Queue.h"

class Check {
private:
    int data;
    std::string text;
public:
    Check(int data, std::string text) : data{data}, text{text} {};

    friend std::ostream &operator<<(std::ostream &os, Check &other) {
        os << other.data << " " << other.text << std::endl;
        return os;
    }
};

int main() {
    // code verification
    /*
    SinglyLinkedList<Check> first_list;
    Check first_check(3, "lalala");
    Check second_check(14, "tratatatata");
    first_list.pushFront(first_check);
    first_list.pushFront(second_check);
    std::cout << first_list;
    Check third_check(4, "bumbumbum");
    first_list.insertAtIndex(1, third_check);
    first_list.removeAtIndex(0);
    std::cout << first_list;
    return 0;*/

    // code verification
    /*Stack<3, int> first_stack;
    first_stack.push(1);
    first_stack.push(2);
    first_stack.push(3);
    if (first_stack.isFull()) {
        for (int i = 0; i < 3; i++) {
            std::cout << first_stack.peek() << " ";
            first_stack.pop();
        }
    }
    if (first_stack.isEmpty()) std::cout << "\nyes";*/

    // code verification
    /*
    Stack_L<int> first_stack_l;
    first_stack_l.push(1);
    first_stack_l.push(2);
    first_stack_l.push(3);
    for (int i = 0; i < 3; i++) {
        std::cout << first_stack_l.peek() << " ";
        first_stack_l.pop();
    }
    if (first_stack_l.isEmpty()) std::cout << "\nyes";*/

    // code verification Queue
    /*Queue<int> first_queue;
    first_queue.Enqueue(1);
    first_queue.Enqueue(2);
    first_queue.Enqueue(3);
    for (int i = 0; i < 3; i++) {
        std::cout << first_queue.peek() << " ";
        first_queue.Dequeue();
    }
    */

    // code verification Queue
}