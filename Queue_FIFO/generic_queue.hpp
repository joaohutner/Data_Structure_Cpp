//Structs
template <typename TIPO>
struct TElemento{
  TIPO dado;
  TElemento<TIPO> *prox;
};

template <typename TIPO>
struct TFila{
  TElemento<TIPO> *inicio;
};

//Funções
template<typename TIPO>
TElemento<TIPO> * novo_elemento_fila(TIPO dado){ //retorno do tipo TElemento
  TElemento<TIPO> * novo = new TElemento<TIPO>;
  novo->dado = dado;
  novo->prox = NULL;
  return novo;
}

template <typename TIPO>
void inicializa_fila(TFila <TIPO> &fila){
  fila.inicio = NULL;
}

template <typename TIPO>
bool Queue(TFila<TIPO> &fila, TIPO dado){
    TElemento<TIPO> *novo = novo_elemento_fila(dado);
    if(fila.inicio == NULL){
        fila.inicio = novo; //novo ja aponta para NULL
        return 0;
    }
    else{
        TElemento<TIPO> *busca = fila.inicio;
        while(busca->prox != NULL){
            busca = busca->prox;
        }
        busca->prox = novo;
        return 1;
    }
}

template<typename TIPO>
TIPO Dequeue(TFila<TIPO> &fila){
    TIPO dado = fila.inicio->dado;
    if(fila.inicio != NULL){
        TIPO dado = fila.inicio->dado;
        TElemento<TIPO> *aux = fila.inicio;
        fila.inicio = fila.inicio->prox;
        delete aux;
    }
    return dado;
}



