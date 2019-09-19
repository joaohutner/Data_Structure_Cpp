#include <iostream>
#include <string.h>
using namespace std;
#include "generic_stack.hpp"
#include "especi_abert.hpp"

int main(){
    TStack<TAnalise> aberturas;
    stack_start(aberturas);

    TStack<TAnalise> fechaduras;
    stack_start(fechaduras);


    TAnalise aux;
    char expre[100];
    char compare;

    int i;
    
    int contador_abre = 0;
    int contador_fecha = 0;

    cout<<"Insira a sua expressao!"<<endl;
    cin>>expre;

    for(i=0;i<strlen(expre);i++){
        if(expre[i] == '(' or expre[i] == '{' or expre[i] == '['){
            if(expre[i] == '('){
                aux.name = '(';
            }
            else if(expre[i] == '['){
                aux.name = '[';
            }
            else if(expre[i] == '{'){
                aux.name = '{';
            }
            stack_insert(aberturas,aux);
            contador_abre++;
        }
        else if(expre[i] == ')' or expre[i] == '}' or expre[i] == ']'){
            if(expre[i] == ')'){
                aux.name = ')';
            }
            else if(expre[i] == ']'){
                aux.name = ']';
            }
            else if(expre[i] == '}'){
                aux.name = '}';
            }
            stack_insert(fechaduras,aux);
            contador_fecha++;
        }
    }

    int nope = 1;

    char auxiliar_abre = ' ';
    char auxilixar_fecha = ' ';


    
    if(contador_fecha==contador_abre){
        for(i=0;i<contador_abre;i++){

            auxiliar_abre=captura_(pop(aberturas));
            auxilixar_fecha = captura_(pop(fechaduras));

            if(auxiliar_abre=='(' and auxilixar_fecha==')'){
                nope = 0;
            }
            else if(auxiliar_abre=='[' and auxilixar_fecha==']'){
                nope = 0;
            }
            else if(auxiliar_abre=='{' and auxilixar_fecha=='}' ){
                nope = 0;
            }
        }
    } 
    
    
    
    if (nope == 1){
        cout<<"\nEsta mal formado!";
    }
    else{
        cout<<"\nEsta bem formado!";
    }
    
    return 0;
}