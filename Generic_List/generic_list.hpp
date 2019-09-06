#ifndef GENERIC_LIST_H_INCLUDED
#define GENERIC_LIST_H_INCLUDED

using namespace std;

template <typename TIPO>
struct TElemento{
    TIPO dado;
};

template <typename TIPO, int MAX>
struct TLista{
    TElemento<TIPO> elemento[MAX];
    int quantidade;
};

template <typename TIPO, int MAX>
void inicializa_lista(TLista<TIPO,MAX> &l){
    l.quantidade = 0;
}

template <typename TIPO, int MAX>
void insere_final(TLista<TIPO,MAX> &lista, TIPO dado){
    if(lista.quantidade < MAX){
        TElemento<TIPO> elemento;
        elemento.dado = dado;
        lista.elemento[lista.quantidade] = elemento;
        lista.quantidade++;
    }
    else{
        cout<<endl<<"Sem espaco no deck"<<endl;
    }
}

template <typename TIPO, int MAX>
void remove_final(TLista<TIPO,MAX> &lista){
    if(lista.quantidade > 0){
        lista.quantidade--;
    }
    else{
        cout<<endl<<"Nao possui carta"<<endl;
    }
}

template <typename TIPO, int MAX>
int qtd(TLista<TIPO,MAX> &lista){
    return lista.quantidade;
}

template <typename TIPO, int MAX>
void remove_inicio(TLista<TIPO,MAX> &lista){
    if(lista.quantidade > 0){
        for(int i=0;i<lista.quantidade;i++){
            lista.elemento[i] = lista.elemento[i+1];
        }
        lista.quantidade--;
    }
    else{
        cout<<endl<<"Nao possui carta"<<endl;
    }
}

template <typename TIPO, int MAX>
void insere_inicio(TLista<TIPO,MAX> &lista, TIPO dado){ //Bool sem o cout, nunca cout no TAD
    if(lista.quantidade < MAX){
        for(int i=lista.quantidade;i>0;i--){
            lista.elemento[i] = lista.elemento[i-1];
        }
        TElemento<TIPO> elemento;
        elemento.dado = dado;
        lista.elemento[0] = elemento;
        lista.quantidade++;
    }
    else{
        cout<<endl<<"Sem espaco no deck"<<endl;
    }
}

template <typename TIPO, int MAX>
void remove_posicao(TLista<TIPO,MAX> &lista,int p){
    if((lista.quantidade > 0) || (p < lista.quantidade)){
        for(int i=p;i<lista.quantidade;i++){
            lista.elemento[i] = lista.elemento[i+1];
        }
        lista.quantidade--;
    }
    else{
        cout<<endl<<"Nao possui carta ou posicao invalida"<<endl;
    }
}

template <typename TIPO, int MAX> //for é condicional, evitar usar lista.quantidade
void insere_posicao(TLista<TIPO,MAX> &lista,int p,TIPO dado){
    if((p<=lista.quantidade) && (lista.quantidade < MAX)){
        for(int i=lista.quantidade;i>p;i--){
            lista.elemento[i] = lista.elemento[i-1];
        }
        TElemento<TIPO> elemento;
        elemento.dado = dado;
        lista.elemento[p] = elemento;
        lista.quantidade++;
    }
    else{
        cout<<endl<<"Nao foi possivel adicionar a carta nessa posicao"<<endl;
    }
}

#endif // LISTA_TAD_H_INCLUDED
