//Auxiliares

struct TAtende{
    string nome;
    int boletos;
};

template <typename TIPO>
bool imprime_tudo(TFila<TIPO> &fila){
    if(fila.inicio == NULL){
        cout<<"\nVoce nao possui ninguem na fila!\n";
        return 0;
    }
    else{
        TElemento<TIPO> *nave = fila.inicio;
        while(nave != NULL){
            imprime_PESSOA(nave->dado,0);
            nave = nave->prox;
        }
        return 1;
    }
}

void imprime_PESSOA(TAtende pessoa,int &contar){
    int i;
    cout<<"Pessoa: "<<pessoa.nome<<endl;
    for(i=0;i<pessoa.boletos;i++){
        cout<<"Em atendimento..."<<i+1<<endl;
    }
    contar = contar + i;
}