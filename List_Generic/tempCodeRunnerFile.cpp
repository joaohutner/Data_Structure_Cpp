#include <iostream>
#include "generic_list.h"
#include "poker.h"
using namespace std;

int main()
{
    TLista <TCarta,52> dealer;
    TLista <TCarta,5> mesa;
    TLista <TCarta,2> jogador;

    inicializa_lista(dealer);
    monta_baralho(dealer);
    imprime_generico(dealer);
    cout<<endl<<"----------------------------"<<endl;
    ordenar_cartas_quick(dealer,0,52);
    imprime_generico(dealer);
    cout<<endl<<"----------------------------"<<endl;

    inicializa_lista(mesa);
    distribuir_cartas(dealer,mesa,5);
    cout<<endl<<"--------DEALER("<<qtd(dealer)<<")--------"<<endl;
    imprime_generico(dealer);
    cout<<endl<<"--------MESA("<<qtd(mesa)<<")--------"<<endl;
    imprime_generico(mesa);






    return 0;
}
