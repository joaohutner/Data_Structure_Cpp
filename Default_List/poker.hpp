#ifndef POKER_H_INCLUDED
#define POKER_H_INCLUDED
#include <string.h>
using namespace std;

struct TCarta{
    int naipe;
    int valor;
};

void imprime_carta(TCarta carta){
    char aux[8];
    if(carta.naipe == 1){
        strcpy(aux,"Paus");
    }
    if(carta.naipe == 2){
        strcpy(aux,"Ouros");
    }
    if(carta.naipe == 3){
        strcpy(aux,"Copas");
    }
    if(carta.naipe == 4){
        strcpy(aux,"Espadas");
    }
    cout<<"Naipe: "<<aux<<"\tValor: "<<carta.valor;
}

#endif // POKER_H_INCLUDED
