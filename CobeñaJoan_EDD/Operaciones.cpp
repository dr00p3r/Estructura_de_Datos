#include <iostream>
#include "Operaciones.h"

template <typename T>
void Operaciones<T>::calculo(){
    std::cout<<valor1<<"+"<<valor2<<" = "<<sumar()<<std::endl;
    std::cout<<valor1<<"-"<<valor2<<" = "<<restar()<<std::endl;
    std::cout<<valor1<<"*"<<valor2<<" = "<<multiplicar()<<std::endl;
    std::cout<<valor1<<"/"<<valor2<<" = "<<dividir()<<std::endl;
}

template <typename T>
T Operaciones<T>::sumar(){
    return valor1 + valor2;
}

template <typename T>
T Operaciones<T>::restar(){
    return valor1 - valor2;
}

template <typename T>
T Operaciones<T>::multiplicar(){
    return valor1 * valor2;
}

template <typename T>
T Operaciones<T>::dividir(){
    return valor1/valor2;
}
