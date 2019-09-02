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
    if(lista.inicio == NULL){
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
  int tam = qtd(lista);
  if(p>=tam){
    cout<<"\nEssa posicao nao existe!\n";
    return NULL;
  }
  else if(p<0){
    cout<<"\nEssa posicao nao existe!\n";
    return NULL;
  }
  else if(p==0){
      return lista.inicio;
  }
  else if(p==tam-1){
      return lista.fim;
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
    if(lista.inicio == NULL){
        TElemento<TIPO> *novo = novo_elemento_lista(dado);
        lista.inicio = novo;
        lista.fim = novo;
        return true;
    }
    else{
        TElemento<TIPO> *novo = novo_elemento_lista(dado);
        TElemento<TIPO> *aux = lista.inicio;
        novo->prox = aux;
        aux->ant = novo;
        lista.inicio = novo;
        novo->ant = NULL;
        return true;
    }
}

template <typename TIPO>
bool insere_fim(TLista <TIPO> &lista, TIPO dado){
    if(lista.inicio == NULL){ 
        TElemento<TIPO> *novo = novo_elemento_lista(dado);
        lista.inicio = novo;
        lista.fim = novo;
        novo->prox = NULL;
        novo->ant = NULL;
        return true;
    }
    else{
        TElemento<TIPO> *novo = novo_elemento_lista(dado);
        TElemento<TIPO> *aux = lista.fim;
        lista.fim = novo;
        novo->ant = aux;
        aux->prox = novo;
        novo->prox = NULL;
        return true;
    }
    
}

template<typename TIPO>                    
bool insere_posicao(TLista<TIPO> &lista, int p, TIPO dado){
    if(p==0){//insere inicio
        if(lista.inicio == NULL){//lista sem itens
            TElemento<TIPO> *novo = novo_elemento_lista(dado);
            lista.inicio = novo;
            lista.fim = novo;
            return true;
        }
        else{//lista com itens
            TElemento<TIPO> *novo = novo_elemento_lista(dado);
            TElemento<TIPO> *aux = lista.inicio;
            novo->prox = aux;
            aux->ant = novo;
            lista.inicio = novo;
            novo->ant = NULL;
            return true;
        }
    }
    else if(lista.inicio != NULL){
        int contador = 0;
        TElemento<TIPO> *navega = lista.inicio;
        while(navega->prox != NULL && contador<p-1){
        contador++;
        navega = navega->prox;
        }
        if(navega == NULL){
            cout<<endl<<"Posicao inexistente!"<<endl;
            return false;
        }
        else{
            TElemento<TIPO> *novo = novo_elemento_lista(dado);
            novo->prox = navega->prox;
            novo->ant = navega;
            navega->prox = novo;
            if(novo->prox == NULL){
                lista.fim = novo;
            }
            else{
                navega->prox->ant = novo;
            }
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
    else if(lista.inicio == lista.fim){
        delete lista.inicio;
        lista.inicio = NULL;
        lista.fim = NULL;
        return true;
    }
    else{
        TElemento <TIPO> *aux = lista.inicio->prox;
        delete lista.inicio;
        lista.inicio = aux;
        aux->ant = NULL;
        return true;
    }
}

template <typename TIPO>
bool remove_final(TLista<TIPO> &lista){
    if(lista.inicio == NULL){
        cout<<"\nSem elementos na lista.\n";
        return false;
    }
    else if(lista.inicio == lista.fim){
        delete lista.inicio;
        lista.inicio = NULL;
        lista.fim = NULL;
        return true;
    }
    else{
        TElemento <TIPO> *aux = lista.fim->ant;
        delete lista.fim;
        lista.fim = aux;
        aux->prox = NULL;
        return true;
    }
}

template<typename TIPO>
bool remove_posicao(TLista<TIPO> &lista, int p){
    if(p==0){//remove inicio
        if(lista.inicio== NULL){
        cout<<"\nSem elementos na lista.\n";
        return false; //não tem item na lista
        }
        else if(lista.inicio == lista.fim){ //Remover unico item da lista
            delete lista.inicio;
            lista.inicio = NULL;
            lista.fim = NULL;
            return true;
        }
        else{//Remover primeiro item da lista
            TElemento <TIPO> *aux = lista.inicio->prox;
            delete lista.inicio;
            lista.inicio = aux;
            aux->ant = NULL;
            return true;
        }
    }
    else if(lista.inicio != NULL){
        int contador = 0;
        TElemento<TIPO> *navega = lista.inicio;
        while(navega->prox != NULL && contador<p){
        contador++;
        navega = navega->prox;
        }
        if(navega == NULL){
            cout<<endl<<"Posicao inexistente!"<<endl;
            return false;
        }
        else{
            navega->ant->prox = navega->prox;
            if(navega->prox == NULL){
                lista.fim = navega->ant;
            }
            else{
                navega->prox->ant = navega->ant;
            }
            navega->ant->prox = navega->prox;
            delete navega;
            return true;
        }
    }
    else{
        return false;
    }
}

#endif // DOUBLY_LIST_H_INCLUDED