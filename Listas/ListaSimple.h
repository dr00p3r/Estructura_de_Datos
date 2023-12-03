#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H

#include "Nodo.h"

class ListaSimple
{
    public:
        void insertar_cabeza(int);
        void insertar_cola(int);
        void imprimir_cola();
        void imprimir_cabeza();
        void buscar(int);
        void eliminar_cola();
        void eliminar_cabeza();
        bool esta_vacia();
        ListaSimple();
        ~ListaSimple();
    protected:

    private:
        Nodo* cabeza;
};

#endif // LISTASIMPLE_H
