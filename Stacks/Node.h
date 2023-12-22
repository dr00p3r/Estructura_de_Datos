/***********************************************************************
 UFA - ESPE
 * Module:  Node.cpp
 * Author:  Joan Cobeña, Ruben Benavides
 * Modified: jueves, 21 de diciembre de 2023
 * Purpose: Declaracion de Nodo
 ***********************************************************************/

#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

template <typename T>
class Node{
private:
    T value;
    Node<T>* below;
public:
    Node();
    Node(T, Node<T>*);
    ~Node();
    T get_value();
    void set_value(T);
    Node<T>* get_below();
    void set_below(Node<T>*);
};

#endif // NODE_H_INCLUDED
