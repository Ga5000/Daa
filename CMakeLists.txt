cmake_minimum_required(VERSION 3.29)
project(DataStructures C)

set(CMAKE_C_STANDARD 23)

add_executable(MainExecutable main.c)

add_executable(LinkedListExecutable linkedList.c)
add_executable(DoublyLinkedList doublyLinkedList.c)
add_executable(BinaryTree binaryTree.c)