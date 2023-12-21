#ifndef STACKS_OPERATIONS_H_INCLUDED
#define STACKS_OPERATIONS_H_INCLUDED

#include "Stack.cpp"
#include "Node.h"
#include <cmath>

void reverse_stack_rec(Stack<int>* original_stack, Stack<int>* aux_stack1, Stack<int>* aux_stack2, bool is_reversed);
void hanoi_stack_p(int n, Stack<int>* stack_A, Stack<int>* stack_B, Stack<int>* stack_C);
void print_hanoi_stacks(Stack<int>* stack_A, Stack<int>* stack_B, Stack<int>* stack_C);
void comb_primas_rec(int aux, Stack<int>* original_stack, Stack<int>* cont_stack, Stack<int>* aux_stack, int* cont_prim, int direccion);
void contar_comb_primas(int valor, int *contador, bool paso, int valor_sin_prim, int grupos_desde);
bool es_primo(int valor);
int contar_cifras(int valor);
int invertir_num(int num);
void invertir_num_rec(int num, int* num_invertido, int num_cifras);

void hanoi_stack(int disks_number){
    Stack<int>* stack_A = new Stack<int>();
    Stack<int>* stack_B = new Stack<int>();
    Stack<int>* stack_C = new Stack<int>();

    //Llenar el stack en orden descendente
    for(int i = 0; i<disks_number; i++){
        stack_A->aggregate(disks_number-i);
    }

    hanoi_stack_p(disks_number, stack_A, stack_B, stack_C);

}

void hanoi_stack_p(int n, Stack<int>* stack_A, Stack<int>* stack_B, Stack<int>* stack_C){
    print_hanoi_stacks(stack_A, stack_B, stack_C);

    auto hanoi_stack_rec = [&stack_A, &stack_B, &stack_C](int n, Stack<int>* stack_orig, Stack<int>* stack_aux, Stack<int>* stack_dest, auto&& hanoi_stack_rec)->void{
        if (n > 0) {
            hanoi_stack_rec(n - 1, stack_orig, stack_dest, stack_aux, hanoi_stack_rec);

            stack_dest->aggregate(stack_orig->take_off());

            print_hanoi_stacks(stack_A, stack_B, stack_C);

            hanoi_stack_rec(n - 1, stack_aux, stack_orig, stack_dest, hanoi_stack_rec);
        }
    };

    hanoi_stack_rec(n, stack_A, stack_B, stack_C, hanoi_stack_rec);
}

void print_hanoi_stacks(Stack<int>* stack_A, Stack<int>* stack_B, Stack<int>* stack_C){
    Node<int>* auxA = stack_A->get_top();
    Node<int>* auxB = stack_B->get_top();
    Node<int>* auxC = stack_C->get_top();
    printf("\n\n");
    while(auxA!=nullptr || auxB!=nullptr || auxC!=nullptr){
        if(auxA!=nullptr){
            std::cout<<auxA->get_value()<<"\t|\t";
            auxA = auxA->get_below();
        }
        else if(auxA==nullptr){
            std::cout<<"  \t|\t";
        }
        if(auxB!=nullptr){
            std::cout<<auxB->get_value()<<"\t|\t";
            auxB = auxB->get_below();
        }
        else if(auxB==nullptr){
            std::cout<<"  \t|\t";
        }
        if(auxC!=nullptr){
            std::cout<<auxC->get_value()<<"\t|\t";
            auxC = auxC->get_below();
        }
        else if(auxC==nullptr){
            std::cout<<"  \t|\t";
        }
        printf("\n");
    }
    printf("\n----------------------\n");
}

void reverse_stack(Stack<int>* original_stack){
    Stack<int>* aux_stack1 = new Stack<int>();
    Stack<int>* aux_stack2 = new Stack<int>();
    reverse_stack_rec(original_stack, aux_stack1, aux_stack2, false);
    delete aux_stack1;
    delete aux_stack2;
}

void reverse_stack_rec(Stack<int>* original_stack, Stack<int>* aux_stack1, Stack<int>* aux_stack2, bool is_reversing){
    if(!original_stack->is_stack_void() && !is_reversing){
        aux_stack1->aggregate(original_stack->take_off());
        reverse_stack_rec(original_stack, aux_stack1, aux_stack2, is_reversing);
    }
    else if(!aux_stack1->is_stack_void()){
        aux_stack2->aggregate(aux_stack1->take_off());
        reverse_stack_rec(original_stack, aux_stack1, aux_stack2, is_reversing);
    }
    else if(!aux_stack2->is_stack_void()){
        original_stack->aggregate(aux_stack2->take_off());
        reverse_stack_rec(original_stack, aux_stack1, aux_stack2, true);
    }
}

/**
 * @brief Llena una pila de conteo con el numero de posibles primos
 * en los topes sucesivos de una pila de enteros
 *
 * @param original_stack
 * @param cont_stack
 * @param direccion (> 0 cuenta los primos del numero original, si es <0 al inverso, == 0 ambos)
 */
void comb_primas(Stack<int>* original_stack, Stack<int>* cont_stack, int direccion){
    Stack<int>* aux_stack = new Stack<int>();
    cont_stack->remove_all();
    int cont_prim = 0;

    comb_primas_rec(0, original_stack, cont_stack, aux_stack, &cont_prim, direccion);

    while(!aux_stack->is_stack_void()){
        original_stack->aggregate(aux_stack->take_off());
    }
    reverse_stack(cont_stack);
    delete aux_stack;

    printf("\n-----------------------\n");
}

void comb_primas_rec(int aux, Stack<int>* original_stack, Stack<int>* cont_stack, Stack<int>* aux_stack, int* cont_prim, int direccion){
    if(!original_stack->is_stack_void()){
        aux = original_stack->get_top()->get_value();
        aux_stack->aggregate(aux);
        *cont_prim = 0;
        printf("\n-----------------------");

        if(direccion>0){
            contar_comb_primas(aux, cont_prim, false, 0, 1);
        }
        else if(direccion<0){
            contar_comb_primas(invertir_num(aux), cont_prim, false, 0, 1);
        }
        else{
            contar_comb_primas(aux, cont_prim, false, 0, 1);
            printf("\nREGRESO");
            contar_comb_primas(invertir_num(aux), cont_prim, false, 0, 2);
        }

        cont_stack->aggregate(*cont_prim);
        original_stack->remove_top();
        comb_primas_rec(aux, original_stack, cont_stack, aux_stack, cont_prim, direccion);
    }
}

void contar_comb_primas(int valor, int *contador, bool paso, int valor_sin_prim, int grupos_desde){
    if(valor>int(pow(10, grupos_desde-1))){
        if(!paso){
            contar_comb_primas(valor/10, contador, paso, valor_sin_prim, grupos_desde);
        }

        if(es_primo(valor)){
            printf("\n%d es primo", valor);
            *contador = *contador + 1;
        }


        valor_sin_prim = valor % int(pow(10, contar_cifras(valor)-1));
        if(contar_cifras(valor)-1 > contar_cifras(valor_sin_prim)){
            if(es_primo(valor_sin_prim)){
                *contador = *contador + contar_cifras(valor)-contar_cifras(valor_sin_prim)-1;
            }
        }

        contar_comb_primas(valor_sin_prim, contador, true, valor_sin_prim, grupos_desde);
    }
}


bool es_primo(int valor){
    bool primo = true;
    if (valor <= 1) {
        primo = false;
    }
    else if(valor <= 3){
        primo = true;
    }
    else if (valor % 2 == 0 || valor % 3 == 0) {
        primo = false;
    }
    else{
        for (int i = 5; i * i <= valor; i += 6) {
            if (valor % i == 0 || valor % (i + 2) == 0) {
                primo = false;
                break;
            }
        }
    }

    return primo;
}

int contar_cifras(int valor){
    int contador = 0;

    do{
        valor = valor/10;
        contador ++;
    }while(valor >= 1);

    return contador;
}

void invertir_num_rec(int num, int* num_invertido, int num_cifras){
    if(num>0){
        invertir_num_rec(num/10, num_invertido, num_cifras-1);
        *num_invertido = *num_invertido + (num%10)*pow(10, num_cifras-1);
    }
}

int invertir_num(int num){
    if(num>0){
        int numero_invertido = 0;
        invertir_num_rec(num, &numero_invertido, contar_cifras(num));
        return numero_invertido;
    }
}



#endif // STACKS_OPERATIONS_H_INCLUDED
