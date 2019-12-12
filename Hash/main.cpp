#include <iostream>
using namespace std;
#include "hashing_lista.h"


int main()
{
    Thash *tabela[8];

    inicializar_thash_lista(tabela);


    inserir_lista(tabela,10);
    inserir_lista(tabela,20);
    inserir_lista(tabela,30);
    inserir_lista(tabela,40);
    inserir_lista(tabela,50);
    inserir_lista(tabela,60);
    inserir_lista(tabela,70);
    inserir_lista(tabela,80);
    cout<<"\nLISTA COMPLETA\n";
    exibir_lista(tabela);

    cout<<"\nREMOVENDO 10\n";
    remover_lista(tabela,10);
    exibir_lista(tabela);

    cout<<"\nINSERINDO 10\n";
    inserir_lista(tabela,10);
    exibir_lista(tabela);


    /*
    inserir_lista(tabela,14);
    inserir_lista(tabela,20);
    inserir_lista(tabela,36);

    cout<<"\nLISTA COMPLETA\n";
    exibir_lista(tabela);

    cout<<"\nREMOVENDO 36\n";
    remover_lista(tabela,36);
    exibir_lista(tabela);

    cout<<"\nREMOVENDO 20\n";
    remover_lista(tabela,20);
    exibir_lista(tabela);
    */






    return 0;
}
