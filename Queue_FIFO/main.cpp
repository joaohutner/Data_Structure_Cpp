#include <iostream>
using namespace std;
#include "generic_queue.hpp"
#include "atendimento.hpp"


int main(){
    int contar = 0;

    TFila<TAtende> atendimentos;
    inicializa_fila(atendimentos);
    TAtende pessoa1;
    pessoa1.nome = "Jovem";
    pessoa1.boletos = 4;
    TAtende pessoa2;
    pessoa2.nome = "Adulto";
    pessoa2.boletos = 10;
    TAtende pessoa3;
    pessoa3.nome = "Idosa";
    pessoa3.boletos = 2;

    Queue(atendimentos,pessoa1);
    Queue(atendimentos,pessoa2);
    Queue(atendimentos,pessoa3);

    int pessoas = 0;
    for(int i = 0; i<3;i++){
        imprime_PESSOA(Dequeue(atendimentos),contar);
        pessoas++;
    }

    float media = (float)contar/pessoas;
    cout<<endl<<"Numero de pessoas: "<<pessoas<<endl;
    cout<<"Numero de boletos: "<<contar<<endl;
    cout<<"Media de boletos por pessoa: "<<media<<endl;
}