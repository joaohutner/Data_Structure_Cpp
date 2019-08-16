#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED
template <typename TIPO>
struct TElemento{
  TDado dado;
  int *proximo;
}

template <typename TIPO>
struct Tlista{
  TElemento<TIPO> *inicio
}

template <typename TIPO>
bool insere_fim(TLista <TIPO> &lista, TIPO dado){
  Telemento <TIPO> *navega = lista.inicio;
  if(lista.inicio =! NULL){
    while(navega->proximo != NULL){
      navega = navega->proximo;
    }
    if(navega->proximo != NULL){ //consistencia
      return false;
    }
    else{
      TElemento<TIPO> *novo = novo_elemento_lista(dado);
      novo->proximo = navega->proximo;
      navega->proxio = novo;
      return true;
    }
  }
  else{
    TElemento<TIPO> *novo = novo_elemento_lista(dado);
    novo->proximo = lista.inicio;//NULL
    lista.inicio = novo;
    return true;
  }
}

template<typename TIPO>
TElemento<TIPO> * novo_elemento_lista(TIPO dado){
  TElemento<TIPO> * novo = new TElemento<TIPO>;
  novo->dado = dado;
  novo->proximo = NULL;
  return novo;
}

#endif // LINKED_LIST_H_INCLUDED
