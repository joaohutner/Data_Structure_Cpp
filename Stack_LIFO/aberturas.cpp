#include <iostream>
#include <locale.h>
#include <string.h>
using namespace std;
#include "generic_stack.hpp"
#include "especi_abert.hpp"

int main(){
    setlocale(LC_ALL, "Portuguese");
    TStack<TAnalise> aberturas;
    stack_start(aberturas);


    TAnalise aux;
    char expre[100];
    int i;
    char compare;
    int contador = 0;

    cout<<"Insira a sua expressão!"<<endl;
    cin>>expre;

    for(i=0;i<strlen(expre);i++){
        if(expre[i] == '(' or expre[i] == '{' or expre[i] == '[' or expre[i] == ')' or expre[i] == '}' or expre[i] == ']'){
            if(expre[i] == '('){
                aux.name = '(';
            }
            else if(expre[i] == '['){
                aux.name = '[';
            }
            else if(expre[i] == '{'){
                aux.name = '{';
            }
            else if(expre[i] == ')'){
                aux.name = ')';
            }
            else if(expre[i] == ']'){
                aux.name = ']';
            }
            else if(expre[i] == '}'){
                aux.name = '}';
            }
            stack_insert(aberturas,aux);
            contador++;
        }
    }
    return 0;
}