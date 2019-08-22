#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

using namespace std;

template <typename TIPO>
struct TElemento{
  TIPO dado;
  int *proximo;
};

template <typename TIPO>
struct TLista{
  TElemento<TIPO> *inicio;
};

template <typename TIPO>
void inicializa_lista(TLista <TIPO> &lista){
  lista.inicio = NULL;
};

template<typename TIPO>
TElemento<TIPO> * novo_elemento_lista(TIPO dado){ //retorno do tipo TElemento
  TElemento<TIPO> * novo = new TElemento<TIPO>;
  novo->dado = dado;
  novo->proximo = NULL;
  return novo;
}

template <typename TIPO>
bool insere_fim(TLista <TIPO> &lista, TIPO dado){
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
  if(lista.inicio== NULL){
    return false; //não tem item na lista
  }
  else if(lista.inicio!=NULL){
    TElemento <TIPO> *aux;
    aux = lista.inicio->prox;
    delete lista.inicio;
    lista.inicio = aux;
    return true;
  }
}

template <typename TIPO>
bool insere_inicio(TLista<TIPO> &lista, TIPO dado){
  if(lista.inicio == NULL){
    TElemento *novo = novo_elemento_lista(dado);
    novo->prox = NULL;
    lista.inicio = novo;
    return true;
  }
  else if(lista.inicio!=NULL){
    TElemento *procura;
    procura = lista.inicio;
    while(procura->prox != NULL){
      procura = procura->prox;
    }
    TElemento *novo; = novo_elemento_lista(dado);
    novo->prox = NULL;
    procura->prox = novo;
  }
  else{
    return false;
  }
}

template<typename TIPO>
bool remove_posicao(TLista<TIPO> &lista, int posicao){
  if(lista.inicio == NULL){
    return false;
    cout<<"\nSem itens na lista\n";
  }
  else if(lista.inicio =! NULL){
    int qtd = qtd(lista);
    if(p>qtd){
      cout<<"\nEssa posicao nao existe\n"
    }
    else{
      TElemento *tras = lista.inicio;
      TElemento *frente = lista.inicio->proximo
      int contador = 0;
      while(qtd!=contador){
        frente = frente->prox;
        tras = tras->prox;
        contador++;
      }
      TElemento *aux = tras->prox;
      tras->prox = frente->prox;
      delete aux;
    }
  }
  else{
    return false;
    cout<<"\nNao foi possivel achar o item";
  }
}

template<typename TIPO>
bool insere_posicao(TLista<TIPO> &lista, int p, TIPO dado){
  qtd = qtd(lista);
  if(p == 0){
    bool confere = insere_inicio(lista,dado);
    if(confere==true){
      return true;
    }
    else{
      return false;
    }
  }
  else if(p == qtd){
    bool confere2 = insere_fim(lista,dado);
    if(confere2==true){
      return true;
    }
    else{
      return false;
    }
  }
  else if(p>qtd || p<0){
    cout<<"\nPosicao inexistente\n";
    return false;
  }
  else{
    TElemento *tras = lista.inicio;
    TElemento *frente = lista.inicio->proximo
    int contador = 0;
    while(qtd!=contador){
      frente = frente->prox;
      tras = tras->prox;
      contador++;
    }
    TElemento *novo = novo_elemento_lista(dado);
    novo->prox = tras->prox;
    tras->prox = novo;
    return true;
  }
}

#endif // LINKED_LIST_H_INCLUDED
