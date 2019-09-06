#include <iostream>
using namespace std;
//Auxiliares

struct TAtende{
    string nome;
    int boletos;
};
/*
template <typename TIPO>
bool imprime_generico(TFila<TIPO> &fila){
    if(fila.inicio == NULL){
        cout<<"\nVoce nao possui ninguem na fila!\n";
        return 0;
    }
    else{
        TElemento<TIPO> *nave = fila.inicio;
        for(int i=0;i<qtd_imprime;i++){
            imprime(nave->dado);
            cout<<endl;
            nave = nave->prox;
        }
        return 1;
    }
}
*/
void imprime(TAtende pessoa){
    cout<<"Pessoa: "<<pessoa.nome<<endl;
    for(int i=0;i<pessoa.boletos;i++){
        cout<<"Em atendimento..."<<i+1<<endl;
    }
}