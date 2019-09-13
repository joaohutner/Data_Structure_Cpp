#include <iostream>
using namespace std;
#include "generic_stack.hpp"
#include "esp.hpp"

int main(){
    TStack<TSla> minerar;
    stack_start(minerar);
    
    TSla objeto_1;
    TSla objeto_2;
    TSla objeto_3;
    objeto_1.cost = 1;
    objeto_1.name = "Pedra";
    objeto_2.cost = 30;
    objeto_2.name = "Ferro";
    objeto_3.cost = 200;
    objeto_3.name = "Ouro";

    stack_insert(minerar,objeto_1);
    stack_insert(minerar,objeto_2);
    stack_insert(minerar,objeto_3);

    cout_stack(stack_remove(minerar));
    cout_stack(stack_remove(minerar));
    cout_stack(stack_remove(minerar));


}