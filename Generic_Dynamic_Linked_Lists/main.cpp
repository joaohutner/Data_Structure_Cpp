#include <iostream>
using namespace std;
#include "linked_list.h"
#include "poker.h"

int main(){
  TLista<TCarta> baralho;
  inicializa_lista(baralho);
  monta_baralho(baralho);
  imprime_generico(baralho);
  embaralhar(baralho);
  cout<<"\nDepois de embaralhar\n";
  imprime_generico(baralho);
  TLista<TCarta> jogador;
  inicializa_lista(jogador);







  return 1;
}
