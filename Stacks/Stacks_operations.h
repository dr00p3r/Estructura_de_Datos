/***********************************************************************
 UFA - ESPE
 * Module:  Stack_operations.h
 * Author:  Joan Cobeña
 * Modified: jueves, 21 de diciembre de 2023
 * Purpose: Operaciones con pilas
 ***********************************************************************/

#ifndef STACKS_OPERATIONS_H_INCLUDED
#define STACKS_OPERATIONS_H_INCLUDED

#include "Stack.cpp"
#include "Node.h"
#include <cmath>

void reverse_stack_rec(Stack<int>* original_stack, Stack<int>* aux_stack1, Stack<int>* aux_stack2, bool is_reversed);
void hanoi_stack_p(int n, Stack<int>* stack_A, Stack<int>* stack_B, Stack<int>* stack_C);
void print_hanoi_stacks(Stack<int>* stack_A, Stack<int>* stack_B, Stack<int>* stack_C);
void prime_comb_rec(int aux, Stack<int>* original_stack, Stack<int>* cont_stack, Stack<int>* aux_stack, int* cont_prim, int direction);
void count_prime_comb(int value, int *contador, bool full_extracted, int cutted_first_digit, int min_digits_group_size);
bool is_prime(int value);
int count_digits(int value);
int reverse_num(int num);
void reverse_num_rec(int num, int* reversed_num, int digits_count);

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
 * @param direction (> 0 cuenta los primos del numero original, si es <0 al inverso, == 0 ambos)
 */
void comb_primes(Stack<int>* original_stack, Stack<int>* cont_stack, int direction){
    Stack<int>* aux_stack = new Stack<int>();
    cont_stack->remove_all();
    int cont_prim = 0;

    prime_comb_rec(0, original_stack, cont_stack, aux_stack, &cont_prim, direction);

    while(!aux_stack->is_stack_void()){
        original_stack->aggregate(aux_stack->take_off());
    }
    reverse_stack(cont_stack);
    delete aux_stack;

    printf("\n-----------------------\n");
}

void prime_comb_rec(int aux, Stack<int>* original_stack, Stack<int>* cont_stack, Stack<int>* aux_stack, int* cont_prim, int direction){
    if(!original_stack->is_stack_void()){
        aux = original_stack->get_top()->get_value();
        aux_stack->aggregate(aux);
        *cont_prim = 0;
        printf("\n-----------------------");

        if(direction>0){
            count_prime_comb(aux, cont_prim, false, 0, 1);
        }
        else if(direction<0){
            count_prime_comb(reverse_num(aux), cont_prim, false, 0, 1);
        }
        else{
            count_prime_comb(aux, cont_prim, false, 0, 1);
            printf("\nREGRESO");
            count_prime_comb(reverse_num(aux), cont_prim, false, 0, 2);
        }

        cont_stack->aggregate(*cont_prim);
        original_stack->remove_top();
        prime_comb_rec(aux, original_stack, cont_stack, aux_stack, cont_prim, direction);
    }
}

void count_prime_comb(int value, int *contador, bool full_extracted, int cutted_first_digit, int min_digits_group_size){
    if(value>int(pow(10, min_digits_group_size-1))){
        if(!full_extracted){
            count_prime_comb(value/10, contador, full_extracted, cutted_first_digit, min_digits_group_size);
        }

        if(is_prime(value)){
            printf("\n%d es primo", value);
            *contador = *contador + 1;
        }


        cutted_first_digit = value % int(pow(10, count_digits(value)-1));
        if(count_digits(value)-1 > count_digits(cutted_first_digit)){
            if(is_prime(cutted_first_digit)){
                *contador = *contador + count_digits(value)-count_digits(cutted_first_digit)-1;
            }
        }

        count_prime_comb(cutted_first_digit, contador, true, cutted_first_digit, min_digits_group_size);
    }
}


bool is_prime(int value){
    bool primo = true;
    if (value <= 1) {
        primo = false;
    }
    else if(value <= 3){
        primo = true;
    }
    else if (value % 2 == 0 || value % 3 == 0) {
        primo = false;
    }
    else{
        for (int i = 5; i * i <= value; i += 6) {
            if (value % i == 0 || value % (i + 2) == 0) {
                primo = false;
                break;
            }
        }
    }

    return primo;
}

int count_digits(int value){
    int contador = 0;

    do{
        value = value/10;
        contador ++;
    }while(value >= 1);

    return contador;
}

void reverse_num_rec(int num, int* reversed_num, int digits_count){
    if(num>0){
        reverse_num_rec(num/10, reversed_num, digits_count-1);
        *reversed_num = *reversed_num + (num%10)*pow(10, digits_count-1);
    }
}

int reverse_num(int num){
    if(num>0){
        int numero_invertido = 0;
        reverse_num_rec(num, &numero_invertido, count_digits(num));
        return numero_invertido;
    }
}



#endif // STACKS_OPERATIONS_H_INCLUDED
