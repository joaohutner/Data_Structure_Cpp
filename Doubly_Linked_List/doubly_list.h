#ifndef DOUBLY_LIST_H_INCLUDED
#define DOUBLY_LIST_H_INCLUDED
//
//Structs
//
template <typename TIPO>
struct TElemento{
    TIPO dado;
    TElemento<TIPO> *prox;
    TElemento<TIPO> *ant;
};

template <typename TIPO>
struct TLista{
    TElemento<TIPO> *inicio;
    TElemento<TIPO> *fim;
};
//
//Fim structs
//
//
//Funções auxiliares: 
//
template <typename TIPO>
TElemento<TIPO> * novo_elemento_lista(TIPO dado){//Meu retorno é um ponteiro tipo TElemento.
    TElemento<TIPO> * novo = new TElemento<TIPO>;
    novo->dado = dado;
    novo->prox = NULL;
    novo->ant = NULL;
    return novo;
}

template <typename TIPO>
int qtd(TLista<TIPO> &lista){
    continue;
}

template<typename TIPO>
TElemento<TIPO>* elem_na_posi(TLista<TIPO> &lista,int p){
    continue;
}
//
//Fim funções auxiliares
//
template <typename TIPO>
void inicializa_doubly(TLista<TIPO> &lista){
    lista.inicio = NULL;
    lista.fim = NULL;
}

template <typename TIPO>
bool insere_inicio(TLista<TIPO> &lista, TIPO dado){
    continue
}

template <typename TIPO>
bool insere_fim(TLista <TIPO> &lista, TIPO dado){
    continue;
}

template <typename TIPO>
bool insere_posicao(TLista<TIPO> &lista,int p, TIPO dado){
    continue;
}

template <typename TIPO>
bool remove_inicio(TLista<TIPO> &lista){
    continue
}

template <typename TIPO>
bool remove_fim(TLista<TIPO> &lista){
    continue;
}

template <typename TIPO>
bool remove_posicao(TLista<TIPO> &lista, int p){
    continue;
}







#endif // DOUBLY_LIST_H_INCLUDED