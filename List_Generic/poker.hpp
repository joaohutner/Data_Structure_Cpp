#ifndef POKER_H_INCLUDED
#define POKER_H_INCLUDED
#include <string.h>
#include <time.h>
#include <stdlib.h>

struct TCarta{
    int naipe;
    int valor;
};

void imprime_carta(TCarta carta){
    char aux[8];
    if(carta.naipe == 0){
        strcpy(aux,"Paus");
    }
    if(carta.naipe == 2){
        strcpy(aux,"Ouros");
    }
    if(carta.naipe == 4){
        strcpy(aux,"Copas");
    }
    if(carta.naipe == 6){
        strcpy(aux,"Espadas");
    }
    cout<<"Naipe: "<<aux<<"\tValor: "<<carta.valor;
}

void monta_baralho(TLista<TCarta,52> &lista){
    TCarta aux;
    for(int i=0;i<=6;i+=2){
        for(int j=1;j<=13;j++){
            aux.naipe = i;
            aux.valor = j;
            insere_inicio(lista,aux);
        }
    }
}

template <typename TIPO, int MAX>
void embaralhar(TLista<TIPO,MAX> &lista){
    srand(time(NULL));
    for(int i=0;i<lista.quantidade;i++){
        swap(lista.elemento[i],lista.elemento[rand()%(lista.quantidade-1)]);
    }
}

template <typename TIPO1,int MAX1, typename TIPO2, int MAX2>
void distribuir_cartas(TLista<TIPO1,MAX1> &origem, TLista<TIPO2,MAX2> &destino, int qtd){
    for(int i=0;i<qtd;i++){
        insere_inicio(destino,origem.elemento[0].dado);
        remove_inicio(origem);
    }
}

template <typename TIPO, int MAX>
void imprime_generico(TLista<TIPO,MAX> &lista){
    for(int i=0;i<lista.quantidade;i++){
        imprime_carta(lista.elemento[i].dado);
        cout<<endl;
    }
}

bool operator < (TCarta a, TCarta b){
    return a.naipe*10+a.valor < b.naipe*10+b.valor;
}

bool operator <= (TCarta a, TCarta b){
    return a.naipe*10+a.valor <= b.naipe*10+b.valor;
}

bool operator > (TCarta a, TCarta b){
    return a.naipe*10+a.valor > b.naipe*10+b.valor;
}

template <typename TIPO, int MAX>
void ordenar_cartas_bubble(TLista<TIPO,MAX> &lista){//Bubble Sort //Melhorar
    int i,j;
    for(i=0;i<lista.quantidade;i++){
        for(j=0;j<lista.quantidade;j++){
            if(lista.elemento[i].dado < lista.elemento[j].dado){
                swap(lista.elemento[i].dado,lista.elemento[j].dado);
            }
        }
    }
}

template <typename TIPO, int MAX>
void ordenar_cartas_quick(TLista<TIPO,MAX> &lista,int first, int last){//Quick Sort
    int i, j, pivot;
    if(first<last){
        pivot=first;
        i=first;
        j=last;
        while(i<j){
            while(lista.elemento[i].dado<=lista.elemento[pivot].dado&&i<last)
                i++;
            while(lista.elemento[j].dado>lista.elemento[pivot].dado)
                j--;
            if(i<j){
                swap(lista.elemento[i].dado,lista.elemento[j].dado);
            }
        }
        swap(lista.elemento[pivot].dado,lista.elemento[j].dado);
        ordenar_cartas_quick(lista,first,j-1);
        ordenar_cartas_quick(lista,j+1,last);
    }
}


//void comparar_cartas

//void cartas_repetidas//criar jogadas possíveis(pares,trincas,quadras...).

#endif // POKER_H_INCLUDED
