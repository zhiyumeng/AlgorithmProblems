//
// Created by fyyc on 2018/10/17.
//

#ifndef LAI_YE_STACK_H
#define LAI_YE_STACK_H

#include <iostream>

template <typename T>
class Stack {

public:
    Stack();
    ~Stack();

    void push(const T &data);
    void pop();
    T top();
    void clear();
    bool empty();
    int getSize();

private:

    struct node{
        T data;
        node *next;
        node(const T& nodeData, node *nextNode):data(nodeData),next(nextNode){}
    };
    node * headNode;
    int size;
};


template<typename T>
Stack<T>::Stack():headNode(NULL),size(0) {

}

template<typename T>
Stack<T>::~Stack() {
    clear();
}

template<typename T>
void Stack<T>::push(const T &data) {
    headNode = new node(data,headNode);
    size++;
}

template<typename T>
void Stack<T>::pop() {
    if(!empty())
    {
        node *temp = headNode;
        headNode = headNode->next;
        delete temp;
        temp = NULL;
        size--;
    }
}

template<typename T>
T Stack<T>::top() {
    return headNode->data;
}

template<typename T>
void Stack<T>::clear() {
    while (!empty()) pop();
}

template<typename T>
bool Stack<T>::empty() {
    return size==0;
}

template<typename T>
int Stack<T>::getSize() {
    return size;
}


#endif //LAI_YE_STACK_H
