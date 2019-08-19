#include <iostream>
#include <windows.h>
#include "poker.h"
#include "non_generic_list.h"
using namespace std;

int main()
{
    TLista baralho;
    inicializa_baralho(baralho);
    monta_baralho(baralho);
    imprime_baralho(baralho);
    cout<<endl<<"=========================="<<endl;
    embaralha(baralho);
    imprime_baralho(baralho);

    /*
    int qtd;
    TCarta carta;
    TCarta carta2;
    carta.naipe = 2;
    carta.valor = 2;

    carta2.naipe = 1;
    carta2.valor = 3;

    insere_carta_final(baralho,carta);
    insere_carta_final(baralho,carta2);


    imprime_baralho(baralho);
    qtd = qtd_cartas(baralho);
    remove_carta_final(baralho);
    cout<<endl<<"Quantidade de Cartas no baralho: "<<qtd;
    cout<<endl<<"----------------------"<<endl;
    imprime_baralho(baralho);
    qtd = qtd_cartas(baralho);
    cout<<endl<<"Quantidade de Cartas no baralho: "<<qtd;
    cout<<endl<<"----------------------"<<endl;

    insere_inicio(baralho,carta);
    imprime_baralho(baralho);
    qtd = qtd_cartas(baralho);
    cout<<endl<<"Quantidade de Cartas no baralho: "<<qtd;
    cout<<endl<<"----------------------"<<endl;

    insere_inicio(baralho,carta2);
    imprime_baralho(baralho);
    qtd = qtd_cartas(baralho);
    cout<<endl<<"Quantidade de Cartas no baralho: "<<qtd;
    cout<<endl<<"----------------------"<<endl;

    remove_posicao(baralho,0);
    imprime_baralho(baralho);
    qtd = qtd_cartas(baralho);
    cout<<endl<<"Quantidade de Cartas no baralho: "<<qtd;
    cout<<endl<<"----------------------"<<endl;

    insere_posicao(baralho,3,carta2);
    imprime_baralho(baralho);
    qtd = qtd_cartas(baralho);
    cout<<endl<<"Quantidade de Cartas no baralho: "<<qtd;
    cout<<endl<<"----------------------"<<endl;
    */

    return 0;
}
