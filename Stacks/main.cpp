#include <iostream>
#include "Stack.h"
#include "Stacks_operations.h"
#include "validaciones.h"

int main()
{
    Stack<int> stack1;
    Stack<int> cont_stack;

    int opcion, dato;
    do{
        system("cls");
        printf("PILAS");
        printf("\n1. Insertar a la pila");
        printf("\n2. Eliminar de la pila");
        printf("\n3. Imprimir pila");
        printf("\n4. Invertir pila");
        printf("\n5. Torres de Hanoi con pilas");
        printf("\n6. Contar primos de izquierda a derecha");
        printf("\n7. Contar primos de derecha a izquierda");
        printf("\n8. Contar primos de ida y vuelta");
        printf("\n0. Salir");

        opcion = ingresar_enteros("\nEscoja una opcion del menu");

        switch(opcion){
            case 1:
                dato = ingresar_enteros("\nIngrese el entero a insertar en la pila");
                stack1.aggregate(dato);
                printf("\n\n");
                stack1.print();
                system("pause");
                break;
            case 2:
                stack1.remove_top();
                printf("\n\n");
                stack1.print();
                system("pause");
                break;
            case 3:
                printf("\n\n");
                stack1.print();
                system("pause");
                break;
            case 4:
                reverse_stack(&stack1);
                printf("\n\n");
                stack1.print();
                system("pause");
                break;
            case 5:
                dato = ingresar_enteros("\nIngrese el numero de discos");
                hanoi_stack(dato);
                system("pause");
                break;
            case 6:
                system("cls");
                comb_primas(&stack1, &cont_stack, 1);
                printf("\n\nPila\n\n");
                stack1.print();
                printf("\nConteo Primos IZQ A DER\n\n");
                cont_stack.print();
                printf("\n");
                system("pause");
                break;
            case 7:
                system("cls");
                comb_primas(&stack1, &cont_stack, -1);
                printf("\n\nPila\n\n");
                stack1.print();
                printf("\nConteo Primos DER A IZQ\n\n");
                cont_stack.print();
                printf("\n");
                system("pause");
                break;
            case 8:
                system("cls");
                comb_primas(&stack1, &cont_stack, 0);
                printf("\n\nPila\n\n");
                stack1.print();
                printf("\nConteo Primos IDA Y VUELTA\n\n");
                cont_stack.print();
                printf("\n");
                system("pause");
                break;
        }

    }while(opcion!=0);


    system("pause");
    return 0;
}
