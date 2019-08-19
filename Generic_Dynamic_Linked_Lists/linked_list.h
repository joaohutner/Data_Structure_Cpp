#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

template <typename TIPO>
struct TElemento{
  TIPO dado;
  int *proximo;
} //testeseses

template <typename TIPO>
struct TLista{
  TElemento<TIPO> *inicio
}

template <typename TIPO>
void inicializa_lista(TLista <TIPO> &lista){
  lista.inicio = NULL;
}

template <typename TIPO>
bool insere_f(TLista <TIPO> &lista, TIPO dado){
  TElemento <TIPO> *busca;
  busca = lista.inicio;
  if(lista.inicio!=NULL){
    while(busca->proximo != NULL){
      busca=busca->proximo;
    }
    if(busca->proximo != NULL){
      cout<<"\nProblema encontrado\n"
      return false;
    }
    else{
      TElemento<TIPO> *novo = novo_elemento_lista(dado);
      novo->proximo = busca->proximo;
      busca->proximo = novo;
      return true;
    }
  }
  else{//inserção em uma lista nula
    TElemento<TIPO> *novo = novo_elemento_lista(dado);
    novo->proximo = NULL;
    lista.inicio = novo;
    return true;
  }
}

template<typename TIPO>
TElemento<TIPO> * novo_elemento_lista(TIPO dado){ //returno do tipo TElemento
  TElemento<TIPO> * novo = new TElemento<TIPO>;
  novo->dado = dado;
  novo->proximo = NULL;
  return novo;
}


template <typename TIPO>
bool remove_final(TLista<TIPO> &lista){
  if(lista.inicio == NULL){
    return false;
  }
  else{
    TElemento <TIPO> *primeiro;
    primeiro = lista.inicio;
    if(busca->proximo==NULL){
      busca->proximo = NULL;
      delete busca;
      return true;
    }
    else{
      TElemento <TIPO> *segundo;
      segundo = lista.inicio->proximo;
      while(segundo->proximo != NULL){
      primeiro=primeiro->proximo;
      segundo=segundo->proximo;
      }
      primeiro->proximo = NULL;
      delete segundo;
      return true;
    }
  }
}



template <typename TIPO>
  int qtd(TLista<TIPO> &lista){
  if(lista.inicio->proximo == NULL){
    return 0;
  }
  else{
    TElemento <TIPO> *busca;
    busca = lista.inicio;
    int contador = 0;
    while(busca->proximo != NULL){
    contador++;
    busca=busca->proximo;
    }
    return contador;
  }
}

template <typename TIPO>
bool remove_inicio(TLista<TIPO> &lista){
  if(lista.inicio->proximo == NULL){
    return false; //não tem item na lista
  }
  else()


}



/*
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
void insere_inicio(TLista<TIPO,MAX> &lista, TIPO dado){
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

template <typename TIPO, int MAX>
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
} */

#endif // LINKED_LIST_H_INCLUDED
