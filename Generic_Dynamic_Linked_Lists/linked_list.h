#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

template <typename TIPO>
struct TElemento{
  TIPO dado;
  TElemento<TIPO> *prox;
};

template <typename TIPO>
struct TLista{
  TElemento<TIPO> *inicio;
};

template <typename TIPO>
void inicializa_lista(TLista <TIPO> &lista){
  lista.inicio = NULL;
}

template<typename TIPO>
TElemento<TIPO> * novo_elemento_lista(TIPO dado){ //retorno do tipo TElemento
  TElemento<TIPO> * novo = new TElemento<TIPO>;
  novo->dado = dado;
  novo->prox = NULL;
  return novo;
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
bool insere_inicio(TLista<TIPO> &lista, TIPO dado){
  TElemento<TIPO> *novo = novo_elemento_lista(dado);
  novo->prox = lista.inicio;
  lista.inicio = novo;
  return true;
}

template<typename TIPO>
bool remove_posicao(TLista<TIPO> &lista, int p){
  if(lista.inicio == NULL){
    cout<<"\nSem elementos na lista.\n";
    return false;
  }
  else if(lista.inicio != NULL){
    int tam = qtd(lista);
    if(p>tam-1){
      cout<<"\nEssa posicao nao existe\n";
      return false;
    }
    else if(p==0){
      TElemento <TIPO> *aux;
      aux = lista.inicio->prox;
      delete lista.inicio;
      lista.inicio = aux;
      return true;
    }
    else{
      TElemento<TIPO> *tras = lista.inicio;
      TElemento<TIPO> *frente = lista.inicio->prox;
      int contador = 0;
      while(p-1>contador){
        frente = frente->prox;
        tras = tras->prox;
        contador++;
      }
      TElemento<TIPO> *aux = 
      tras->prox = frente->prox;
      delete frente;
      return true;
    }
  }
}

template<typename TIPO>
bool insere_posicao(TLista<TIPO> &lista, int p, TIPO dado){
  int tam = qtd(lista);
  if(p == 0){
    bool confere = insere_inicio(lista,dado);
    if(confere==true){
      return true;
    }
    else{
      return false;
    }
  }
  else if(p == tam){
    bool confere2 = insere_fim(lista,dado);
    if(confere2==true){
      return true;
    }
    else{
      return false;
    }
  }
  else if(p>tam || p<0){
    cout<<"\nPosicao inexistente\n";
    return false;
  }
  else{
    TElemento<TIPO> *tras = lista.inicio;
    TElemento<TIPO> *frente = lista.inicio->prox;
    int contador = 0;
    while(tam=!contador){
      frente = frente->prox;
      tras = tras->prox;
      contador++;
    }
    TElemento<TIPO> *novo = novo_elemento_lista(dado);
    novo->prox = tras->prox;
    tras->prox = novo;
    return true;
  }
}

template<typename TIPO>
TElemento<TIPO>* elem_na_posi(TLista<TIPO> &lista,int p){
  int tam = qtd(lista);
  if(p>=tam){
    cout<<"\nEssa posicao nao existe!\n";
    return NULL;
  }
  else if(p<0){
    cout<<"\nEssa posicao nao existe!\n";
    return NULL;
  }
  else{
    int aux = 0;
    TElemento<TIPO> *nave = lista.inicio;
    while(aux<p){
      aux++;
      nave = nave->prox;
    }
    return nave;
  }
}

#endif // LINKED_LIST_H_INCLUDED
