#include <iostream>
#include <string.h>
#include "ListaSimple.h"
#include "Nodo.h"

ListaSimple::ListaSimple()
{
    cabeza = nullptr;
}

void ListaSimple::insertar_cabeza(int valor){
    Nodo* nodo_nuevo = new Nodo(valor, nullptr);
    if(esta_vacia()){
        cabeza = nodo_nuevo;
    }
    else{
        Nodo* aux = cabeza;
        cabeza = nodo_nuevo;
        cabeza->set_siguiente(aux);
    }
}

void ListaSimple::insertar_cola(int valor){
    Nodo* nodo_nuevo = new Nodo(valor, nullptr);
    if(esta_vacia()){
        cabeza = nodo_nuevo;
    }
    else{
        Nodo* aux = cabeza;
        while(aux->get_siguiente() != nullptr){
            aux = aux->get_siguiente();
        }
        aux->set_siguiente(nodo_nuevo);
    }
}

void ListaSimple::imprimir_cabeza(){
    if(!esta_vacia()){
        Nodo* aux = cabeza;
        printf("\n");
        while((aux!=nullptr)){
            printf("%d", aux->get_valor());
            aux = aux->get_siguiente();
            printf("\t");
        }
        printf("\n");
    }
    else{
        printf("\nLa lista esta vacia");
    }
}

void ListaSimple::imprimir_cola(){
    if(!esta_vacia()){
        ListaSimple reversa;
        Nodo* aux = cabeza;
        printf("\n");
        while((aux!=nullptr)){
            reversa.insertar_cabeza(aux->get_valor());
            aux = aux->get_siguiente();
        }
        reversa.imprimir_cabeza();
    }
    else{
        printf("\nLa lista esta vacia");
    }
}

void ListaSimple::buscar(int valor){
    if(!esta_vacia()){
        Nodo* aux = cabeza;
        int i = 0;
        while((aux!=nullptr)){
            if(aux->get_valor() == valor){
                printf("\n%d", aux->get_valor());
                printf("\tPosicion : %d", i);
                break;
            }
            else{
                aux = aux->get_siguiente();
                i++;
            }
        }
    }
    else{
        printf("\nLa lista esta vacia");
    }
}

void ListaSimple::eliminar_cola(){
    if(!esta_vacia()){
        Nodo* aux = cabeza;
        while((aux->get_siguiente()->get_siguiente()!=nullptr)){
            aux = aux->get_siguiente();
        }
        aux->set_siguiente(nullptr);
    }
    else{
        printf("\nLa lista esta vacia");
    }
}

void ListaSimple::eliminar_cabeza(){
    if(!esta_vacia()){
        if(cabeza->get_siguiente()!= nullptr){
            cabeza = cabeza->get_siguiente();
        }
    }
    else{
        printf("\nLa lista esta vacia");
    }
}

bool ListaSimple::esta_vacia(){
    return (cabeza == nullptr)? true:false;
}

ListaSimple::~ListaSimple()
{
    //dtor
}
