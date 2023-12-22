/***********************************************************************
 UFA - ESPE
 * Module:  main.cpp
 * Author:  Joan Cobeña, Ruben Benavides
 * Modified: jueves, 21 de diciembre de 2023
 * Purpose: Declaracion de Pilas
 ***********************************************************************/

#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "Node.h"

template <typename T>
class Stack{
private:
    Node<T>* top;
public:
    Stack();
    Stack(Node<T>*);
    void aggregate(T);
    void aggregate(Node<T>*);
    void remove_top();
    void print();
    Node<T>* take_off();
    void set_top(Node<T>*);
    Node<T>* get_top();
    bool is_stack_void();
    void remove_all();
};

#endif // STACK_H_INCLUDED
