#ifndef POKER_H_INCLUDED
#define POKER_H_INCLUDED
#include <string.h>
#include <time.h> 


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

void monta_baralho(TLista<TCarta> &lista){
    TCarta aux;
    for(int i=0;i<=6;i+=2){
        for(int j=1;j<=13;j++){
            aux.naipe = i;
            aux.valor = j;
            insere_inicio(lista,aux);
        }
    }
}

template <typename TIPO>
bool embaralhar(TLista<TIPO> &lista){
    srand(time(NULL));
    int tam = qtd(lista);
    TElemento<TIPO> *nave = lista.inicio;
    TElemento<TIPO> *troca = lista.inicio;
    if(tam==0){
        cout<<"Nao existe cartas nesse baralho!";
        return false;
    }
    else{
        for(int i=0;i<tam;i++){
            for(int j=0;j<(rand()%(tam-1));j++){
                troca->prox;
            }
            swap(nave.dado,troca.dado);
            troca = lista.inicio;
            nave = nave->prox;
        }
        return true;
    }
}

template <typename TIPO>
bool distribuir_cartas(TLista<TIPO> &origem, TLista<TIPO> &destino, int quantas){
    int qtd_origem = qtd(origem);
    if(quantas>qtd_origem){
        cout<<"\nCartas insuficientes!\n";
        return false;
    }
    TElemento<TIPO> *de = origem.inicio;
    for(int i=0;i<quantas;i++){
        insere_inicio(destino,de.dado);
        remove_inicio(origem);
        de = origem.inicio;
    }
    return true;
}

template <typename TIPO>
bool imprime_generico(TLista<TIPO> &lista){
    int qtd_imprime = qtd(lista);
    TElemento<TIPO> *nave = lista.inicio;
    if(lista.inicio == NULL){
        cout<<"\nVoce nao possui itens na lista!\n";
        return 0;
    }
    for(int i=0;i<qtd_imprime;i++){
        imprime_carta(nave->dado);
        cout<<endl;
        nave = nave->prox;
    }
    return 1;
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

template <typename TIPO>
void ordenar_cartas_bubble(TLista<TIPO> &lista){//Bubble Sort
    int i,j;
    int qtd_lista = qtd(lista);
    TElemento<TIPO> *nave1 = lista.inicio;
    TElemento<TIPO> *nave2 = lista.inicio;
    for(i=0;i<qtd_lista;i++){
        for(j=0;j<qtd_lista;j++){
            if(nave1->dado < nave2->dado){
                swap(nave1->dado,nave2->dado);
            }
            nave2=nave2->prox;
        }
        nave2 = lista.inicio;
        nave1 = nave1->prox;
    }
}

/*
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
*/
#endif // POKER_H_INCLUDED
