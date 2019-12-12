#ifndef HASHING_LINEAR_H_INCLUDED
#define HASHING_LINEAR_H_INCLUDED

const int tam = 8;

struct Thash{
    int chave;
    char livre;
};

int func_hash(int num){
    return num % tam;
}

void inicializar_thash_linear(Thash tabela[]){
    int i;
    for(i=0;i<tam;i++){
        tabela[i].livre = 'L';
    }
}

void inserir_linear(Thash tabela[], int n){
    int i=0;
    int pos = func_hash(n);

    ///h'(x) = (h(x)+i) mod m, para 1 <= i <= m-1, sendo que h(x) = x%m.
    while(i<tam && tabela[pos].livre == 'O'){ ///Em caso de colisão
        i++;
        pos = func_hash(n+i);
    }

    if(i<tam){
        tabela[pos].chave = n;
        tabela[pos].livre = 'O';
    }
    else{
        cout << "\nTabela Cheia!";
    }
}

int buscar_linear(Thash tabela[],int key){
    int i;
    int pos = func_hash(key);

    while(i<tam && tabela[pos].livre == 'O' && key != tabela[pos].chave){
        i++;
        pos = func_hash(key+i);
    }
    if(i<tam){
        pos = tam;
    }
    return pos;
}

bool remover_linear(Thash tabela[], int key){
    int pos = buscar_linear(tabela,key);
    if(pos == tam){
        cout<<"\nNao existe este item!";
        return 0;
    }
    tabela[pos].livre = 'R';
    return 1;
}

void exibir_linear(Thash tabela[]){
    int i;
    cout<<"\n\nPOS\tLIVRE\tCHAVE\n";
    for(i=0;i<tam;i++){
        if(tabela[i].livre != 'O')
            cout<<i<<"\t"<<tabela[i].livre<<"\t"<<" "<<"\n--------------\n";
        else
            cout<<i<<"\t"<<tabela[i].livre<<"\t"<<tabela[i].chave<<"\n--------------\n";
    }
}

#endif // HASHING_LINEAR_H_INCLUDED
