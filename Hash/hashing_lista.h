#ifndef HASHING_LISTA_H_INCLUDED
#define HASHING_LISTA_H_INCLUDED

const int tam = 8;

struct Thash{
    int chave;
    Thash *prox;
};

int func_hash(int num){
    return num % tam;
}

void inicializar_thash_lista(Thash *tabela[]){
    int i;
    for(i=0;i<tam;i++){
        tabela[i] = NULL;
    }
}

void inserir_lista(Thash *tabela[], int num){
    Thash *novo;
    novo = new Thash();
    novo->chave = num;
    int pos = func_hash(num);
    novo->prox = tabela[pos];
    tabela[pos] = novo;
}

void remover_lista(Thash *tabela[], int num){
    int pos = func_hash(num);
    Thash *aux;
    if(tabela[pos] != NULL){
        if(tabela[pos]->chave == num){
            aux = tabela[pos];
            tabela[pos] = tabela[pos]->prox;
            delete aux;
        }
        else{
            aux = tabela[pos]->prox;
            Thash  *ant = tabela[pos];
            while(aux != NULL && aux->chave != num){
                ant = aux;
                aux = aux->prox;
            }
            if(aux !=NULL){
                ant->prox = aux->prox;
                delete aux;
            }
            else{
                cout<< "\nNumero nao encontrado";
            }
        }
    }
    else{
        cout<< "\nAAAANumero nao encontrado";
    }
}

void exibir_lista(Thash *tabela[]){
    int i;
    cout<<"\n\nPOS\tCHAVE\n";
    for(i=0;i<tam;i++){
        if(tabela[i] == NULL)
            cout<<i<<"\t"<<" "<<"\n--------------\n";
        else{
            Thash *aux;
            aux = tabela[i];
            cout<<i<<"\t"<<aux->chave;
            while(aux->prox != NULL){
                cout<<" -> "<<aux->prox->chave;
                aux = aux->prox;
            }
            cout<<"\n--------------\n";
        }
    }
}


#endif // HASHING_LISTA_H_INCLUDED
