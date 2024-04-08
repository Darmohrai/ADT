cmake_minimum_required(VERSION 3.27)
project(ADT)

set(CMAKE_CXX_STANDARD 17)

add_executable(ADT main.cpp
        SinglyLinkedList.h
        DoubleLinkedList.h
        Stack.h
        Stack_L.h
        Queue.h
        PriorityQueue.h
)
