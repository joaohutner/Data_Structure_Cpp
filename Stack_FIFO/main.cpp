#include <iostream>
using namespace std;
#include "generic_stack.hpp"
#include "atendimento.hpp"


int main(){
    TAtende pessoa1;
    pessoa1.nome = "Jovem";
    pessoa1.boletos = 4;
    TAtende pessoa2;
    pessoa2.nome = "Adulto";
    pessoa2.boletos = 10;
    TAtende pessoa3;
    pessoa3.nome = "Idosa";
    pessoa3.boletos = 2;

    imprime(pessoa1);
    imprime(pessoa2);
}