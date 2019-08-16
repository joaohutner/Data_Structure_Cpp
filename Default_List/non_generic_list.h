#ifndef NON_GENERIC_LIST_H_INCLUDED
#define NON_GENERIC_LIST_H_INCLUDED
#include <time.h>

const int MAX = 52;

struct TLista{
    TCarta elemento[MAX];
    int tam_lista;
};

void inicializa_baralho(TLista &lista){
    lista.tam_lista = 0;
}

void insere_carta_final(TLista &lista, TCarta carta){
    if(lista.tam_lista < MAX){
        lista.elemento[lista.tam_lista] = carta;
        lista.tam_lista++;
    }
    else{
        cout<<endl<<"Sem espaco no deck"<<endl;
    }
}

void remove_carta_final(TLista &lista){
    if(lista.tam_lista > 0){
        lista.tam_lista--;
    }
    else{
        cout<<endl<<"Nao possui carta"<<endl;
    }
}

int qtd_cartas(TLista &lista){
    return lista.tam_lista;
}

void remove_inicio(TLista &lista){
    if(lista.tam_lista > 0){
        for(int i=0;i<lista.tam_lista;i++){
            lista.elemento[i] = lista.elemento[i+1];
        }
        lista.tam_lista--;
    }
    else{
        cout<<endl<<"Nao possui carta"<<endl;
    }
}

void insere_inicio(TLista &lista, TCarta carta){
    if(lista.tam_lista < MAX){
        for(int i=lista.tam_lista;i>0;i--){
            lista.elemento[i] = lista.elemento[i-1];
        }
        lista.elemento[0] = carta;
        lista.tam_lista++;
    }
    else{
        cout<<endl<<"Sem espaco no deck"<<endl;
    }
}

void remove_posicao(TLista &lista,int p){
    if(lista.tam_lista > 0){
        for(int i=p;i<lista.tam_lista;i++){
            lista.elemento[i] = lista.elemento[i+1];
        }
        lista.tam_lista--;
    }
    else{
        cout<<endl<<"Nao possui carta"<<endl;
    }
}


void insere_posicao(TLista &lista,int p,TCarta carta){
    if((p<=lista.tam_lista) && (lista.tam_lista < MAX)){
        for(int i=lista.tam_lista;i>p;i--){
            lista.elemento[i] = lista.elemento[i-1];
        }
        lista.elemento[p] = carta;
        lista.tam_lista++;
    }
    else{
        cout<<endl<<"Nao foi possivel adicionar a carta nessa posicao"<<endl;
    }
}

//Específicas do jogo de poker:

void monta_baralho(TLista &lista){
    TCarta aux;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            aux.naipe = i;
            aux.valor = j;
            insere_inicio(lista,aux);
        }
    }
}

void embaralha(TLista &lista){
    srand(time(NULL));
    for(int i=0;i<lista.tam_lista;i++){
        swap(lista.elemento[i],lista.elemento[rand()%(lista.tam_lista-1)]);
    }
}

void distribuir_cartas(TLista &baralho, TLista &destino, int qtd){
    for(int i=0;i<qtd;i++){
        insere_inicio(destino,baralho.elemento[0]);
        remove_inicio(baralho);
    }
}


void imprime_baralho(TLista &lista){
    for(int i=0;i<lista.tam_lista;i++){
        imprime_carta(lista.elemento[i]);
        cout<<endl;
    }
}

void ordenar_cartas_bubble(TLista &lista){//Bubble Sort
    int i,j;
    for(i=0;i<lista.tam_lista-1;i++){
        for(j=1;j<lista.tam_lista;k++){
            if(lista.elemento[i].naipe < lista.elemento[j].naipe){
                swap(lista.elemento[i].naipe,lista.elemento[j].naipe);
            }
        }
    }
    for(i=0;i<lista.tam_lista-1;i++){
        for(j=1;j<lista.tam_lista;k++){
            if(lista.elemento[i].valor < lista.elemento[j].valor){
                swap(lista.elemento[i].valor,lista.elemento[j].valor);
            }
        }
    }
}

/*void ordenar_cartas_quick(TLista &lista){//Quick Sort
}*/


//void comparar_cartas

//void cartas_repetidas//criar jogadas possíveis(pares,trincas,quadras...).

#endif // NON_GENERIC_LIST_H_INCLUDED
