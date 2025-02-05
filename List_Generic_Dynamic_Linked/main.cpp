#include <iostream>
using namespace std;
#include "linked_list.hpp"
#include "poker.hpp"

int main(){
  /*
  TLista<TCarta> baralho;
  inicializa_lista(baralho);
  monta_baralho(baralho);
  embaralhar(baralho);
  imprime_generico(baralho);
  cout<<"Organizando!"<<endl<<endl;
  ordenar_cartas_quick(baralho,0,qtd(baralho)-1);
  imprime_generico(baralho);
  */
  
  TLista<TCarta> jogador;
  inicializa_lista(jogador);
  cout<<"\nCartas jogador:\n";
  TCarta dado;
  dado.naipe = 0;
  dado.valor = 1;
  TCarta dado2;
  dado2.naipe = 0;
  dado2.valor = 2;
  TCarta dado3;
  dado3.naipe = 0;
  dado3.valor = 3;
  cout<<"\nInserindo 3 no inicio: \n";
  insere_inicio(jogador,dado);
  insere_inicio(jogador,dado2);
  insere_inicio(jogador,dado3);
  imprime_generico(jogador);

  cout<<"\nRemovendo no final: \n";
  remove_final(jogador);
  imprime_generico(jogador);

  cout<<"\nRemovendo no inicio: \n";
  remove_inicio(jogador);
  imprime_generico(jogador);

  cout<<"\nInserindo 3 na posicao 1:\n";
  insere_posicao(jogador,1,dado3);
  imprime_generico(jogador);

  cout<<"\nRemovendo da posicao 1: \n";
  remove_posicao(jogador,1);
  imprime_generico(jogador);

  cout<<"\nInserindo 1 na posicao 1:\n";
  insere_posicao(jogador,1,dado);
  imprime_generico(jogador);

  cout<<"\nInserindo 2 na posicao 2:\n";
  insere_posicao(jogador,2,dado2);
  imprime_generico(jogador);

  cout<<"\nInserindo 3 na posicao 2:\n";
  insere_posicao(jogador,2,dado3);
  imprime_generico(jogador);

  cout<<"\nRemovendo da posicao 1: \n";
  remove_posicao(jogador,1);
  imprime_generico(jogador);

  cout<<"\nRemovendo da posicao 3: \n";
  remove_posicao(jogador,3);
  imprime_generico(jogador);







  
  
  

  return 0;
}
