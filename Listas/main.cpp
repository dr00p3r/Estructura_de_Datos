#include <iostream>
#include "Nodo.h"
#include "ListaSimple.h"
#include "../validaciones.h"

int main()
{
    int opcion, dato;
    ListaSimple lista;

    do{
        system("cls");
        printf("\n1. Insertar elementos a la lista por la cabeza");
        printf("\n2. Insertar elementos a la lista por la cola");
        printf("\n3. Imprimir elementos de la lista empezando por la cabeza");
        printf("\n4. Imprimir elementos de la lista empezando por la cola");
        printf("\n5. Buscar primera ocurrencia del elemento");
        printf("\n6. Eliminar elemento de la lista por la cola");
        printf("\n7. Eliminar elemento de la lista por la cabeza");
        printf("\n0. Salir");
        opcion = ingresar_enteros("\nIngrese una opcion del menu");
        switch(opcion){
            case 1:
                dato = ingresar_enteros("\nIngresar un entero como dato del nodo a insertar");
                printf("\n");
                lista.insertar_cabeza(dato);
                lista.imprimir_cabeza();
                system("pause");
                break;
            case 2:
                dato = ingresar_enteros("\nIngresar un entero como dato del nodo a insertar");
                printf("\n");
                lista.insertar_cola(dato);
                lista.imprimir_cabeza();
                system("pause");
                break;
            case 3:
                lista.imprimir_cabeza();
                system("pause");
                break;
            case 4:
                lista.imprimir_cola();
                system("pause");
                break;
            case 5:
                dato = ingresar_enteros("\nIngrese el numero a buscar");
                lista.buscar(dato);
                system("pause");
                break;
            case 6:
                lista.eliminar_cola();
                lista.imprimir_cabeza();
                system("pause");
                break;
            case 7:
                lista.eliminar_cabeza();
                lista.imprimir_cabeza();
                system("pause");
                break;
                break;
        }
    }while(opcion != 0);

    return 0;
}
