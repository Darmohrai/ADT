#include <iostream>
#include "SinglyLinkedList.h"
#include "DoubleLinkedList.h"

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

    
}