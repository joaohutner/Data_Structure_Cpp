#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

//Structs

template <typename TIPO>
struct TElemento{
  TIPO dado;
  TElemento<TIPO> *prox;
};

template <typename TIPO>
struct TLista{
  TElemento<TIPO> *inicio;
};
//Fim structs
//
//
//Funções auxiliares: 
//
template<typename TIPO>
TElemento<TIPO> * novo_elemento_lista(TIPO dado){ //retorno do tipo TElemento
  TElemento<TIPO> * novo = new TElemento<TIPO>;
  novo->dado = dado;
  novo->prox = NULL;
  return novo;
}
template <typename TIPO>
int qtd(TLista<TIPO> &lista){
  if(lista.inicio== NULL){
    return 0;
  }
  else{
    TElemento <TIPO> *busca;
    busca = lista.inicio;
    int contador = 1;
    while(busca->prox != NULL){
    contador++;
    busca=busca->prox;
    }
    return contador;
  }
}
template<typename TIPO>
TElemento<TIPO>* elem_na_posi(TLista<TIPO> &lista,int p){
  if(lista.inicio == NULL){
    return 0;
  }
  else{
    int contador = 0;
    TElemento<TIPO> *navega = lista.inicio;
    while(navega->prox != NULL && contador<p-1){
      contador++;
      navega = navega->prox;
    }
    return navega;
  }
}

//
//Fim funções auxiliares
//
template <typename TIPO>
void inicializa_lista(TLista <TIPO> &lista){
  lista.inicio = NULL;
}

template <typename TIPO>
bool insere_inicio(TLista<TIPO> &lista, TIPO dado){
  TElemento<TIPO> *novo = novo_elemento_lista(dado);
  novo->prox = lista.inicio;
  lista.inicio = novo;
  return true;
}

template <typename TIPO>
bool insere_fim(TLista <TIPO> &lista, TIPO dado){
  TElemento <TIPO> *busca;
  busca = lista.inicio;
  if(lista.inicio!=NULL){
    while(busca->prox != NULL){
      busca=busca->prox;
    }
    if(busca->prox != NULL){
      cout<<"\nProblema encontrado\n";
      return false;
    }
    else{
      TElemento<TIPO> *novo = novo_elemento_lista(dado);
      novo->prox= busca->prox;
      busca->prox= novo;
      return true;
    }
  }
  else{//inserção em uma lista nula
    TElemento<TIPO> *novo = novo_elemento_lista(dado);
    novo->prox = NULL;
    lista.inicio = novo;
    return true;
  }
}

template<typename TIPO>
bool insere_posicao(TLista<TIPO> &lista, int p, TIPO dado){
  if(p==0){
    if(lista.inicio == NULL){//sem itens na lista
      TElemento<TIPO> *novo = novo_elemento_lista(dado);
      lista.inicio = novo;
      return true;
    }
    else{//lista com itens
      TElemento<TIPO> *novo = novo_elemento_lista(dado);
      TElemento<TIPO> *aux = lista.inicio;
      novo->prox = aux;
      lista.inicio = novo;
      return true;
    }
  }
  else if(lista.inicio != NULL){
    int contador = 0;
    TElemento<TIPO> *tras = lista.inicio;
    TElemento<TIPO> *frente = lista.inicio->prox;
    while(tras->prox != NULL && contador<p-1){
      contador++;
      tras = tras->prox;
      frente = frente->prox;
    }
    if(contador<p-1 || tras==NULL){ //Terminamos o while e mesmo assim o contador não passou de posição-1, sabemos que a posição não existe.
      cout<<endl<<"Posicao inexistente!"<<endl;
      return false;
    }
    else{
      TElemento<TIPO> *novo = novo_elemento_lista(dado);
      novo->prox = tras->prox;
      tras->prox = novo;
      return true;
    }
  }
  else{
    return false;
  }
}

template <typename TIPO>
bool remove_inicio(TLista<TIPO> &lista){
  if(lista.inicio== NULL){
    cout<<"\nSem elementos na lista.\n";
    return false; //não tem item na lista
  }
  else if(lista.inicio!=NULL){
    TElemento <TIPO> *aux;
    aux = lista.inicio->prox;
    delete lista.inicio;
    lista.inicio = aux;
    return true;
  }
  else{
    return false;
  }
}

template <typename TIPO>
bool remove_final(TLista<TIPO> &lista){
  if(lista.inicio == NULL){
    cout<<"\nSem elementos na lista.\n";
    return false;
  }
  else{
    TElemento <TIPO> *primeiro = lista.inicio;
    if(primeiro->prox==NULL){
      delete primeiro;
      lista.inicio = NULL;
      return true;
    }
    else{
      TElemento <TIPO> *segundo = lista.inicio->prox;
      while(segundo->prox != NULL){
      primeiro=primeiro->prox;
      segundo=segundo->prox;
      }
      primeiro->prox = NULL;
      delete segundo;
      return true;
    }
  }
}

template<typename TIPO>
bool remove_posicao(TLista<TIPO> &lista, int p){
  if(p==0){//remove inicio
    if(lista.inicio == NULL){
    cout<<"\nSem elementos na lista.\n";
    return false;
    }
    else{//remover primeiro item da lista
      TElemento <TIPO> *aux;
      aux = lista.inicio->prox;
      delete lista.inicio;
      lista.inicio = aux;
      return true;
    }
  }
  else if(lista.inicio != NULL){
    int contador = 0;
    TElemento<TIPO> *tras = lista.inicio;
    TElemento<TIPO> *frente = lista.inicio->prox;
    while(frente->prox != NULL && contador<p-1){ //p-1>contador
      contador++;
      tras = tras->prox;
      frente = frente->prox;
    }
    if(contador<p-1){ //Terminamos o while e mesmo assim o contador não passou de posição-1, sabemos que a posição não existe.
      cout<<endl<<"Posicao inexistente!"<<endl;
      return false;
    }
    else{
      tras->prox = frente->prox;
      delete frente;
      return true;
    }
  }
  else{
    return false;
  }
}

#endif // LINKED_LIST_H_INCLUDED
