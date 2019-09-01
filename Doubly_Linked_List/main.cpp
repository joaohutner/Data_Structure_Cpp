#include <iostream>
using namespace std;
#include "doubly_list.h"
#include "poker.h"

int main(){
    /*
  TLista<TCarta> baralho;
  inicializa_doubly(baralho);
  monta_baralho(baralho);
  embaralhar(baralho);
  imprime_generico(baralho);
  cout<<"Organizando!"<<endl<<endl;
  ordenar_cartas_quick(baralho,0,qtd(baralho)-1);
  imprime_generico(baralho);
    */

  TLista<TCarta> jogador;
  inicializa_doubly(jogador);
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
  cout<<"\nInserindo varios no inicio!\n";
  insere_inicio(jogador,dado);
  insere_inicio(jogador,dado2);
  insere_inicio(jogador,dado3);
  imprime_generico(jogador);
  cout<<"\nRemovendo 1 no Fim: \n";
  remove_final(jogador);
  //imprime_generico(jogador);
  //remove_inicio(jogador);
  imprime_generico(jogador);
  cout<<"\nRemovendo 1 no Inicio: \n";
  remove_inicio(jogador);
  imprime_generico(jogador);
  cout<<"\nInserindo 1 no inicio e 1 no fim!: \n";
  insere_inicio(jogador,dado);
  insere_fim(jogador,dado3);
  imprime_generico(jogador);

  cout<<"\nInserindo na posicao 1:\n";
  insere_posicao(jogador,1,dado);
  imprime_generico(jogador);
  cout<<"E ai";
  cout<<"\nRemovendo da posicao 2: \n";
  remove_posicao(jogador,2);
  imprime_generico(jogador);
  cout<<"\nRemovendo da posicao 2: \n";
  remove_posicao(jogador,2);
  imprime_generico(jogador);
  cout<<"\nInserindo na posicao 3:\n";
  insere_posicao(jogador,3,dado);
  imprime_generico(jogador);
  */


  return 1;
}
