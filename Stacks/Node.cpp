/***********************************************************************
 UFA - ESPE
 * Module:  Node.cpp
 * Author:  Joan Cobeña, Ruben Benavides
 * Modified: jueves, 21 de diciembre de 2023
 * Purpose: Implementacion de Nodo
 ***********************************************************************/

#include "Node.h"

template <typename T>
Node<T>::Node(){

}

template <typename T>
Node<T>::Node(T value, Node<T>*  below){
    this->value = value;
    this->below = below;
}

template <typename T>
void Node<T>::set_value(T value){
    this->value = value;
}

template <typename T>
void Node<T>::set_below(Node<T>* below){
    this->below = below;
}

template <typename T>
T Node<T>::get_value(){
    return value;
}

template <typename T>
Node<T>* Node<T>::get_below(){
    return below;
}

template <typename T>
Node<T>::~Node(){

}
