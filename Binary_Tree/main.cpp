#include <iostream>
#include <string.h>
using namespace std;
#include "binary_tree.hpp"
#include "especific.hpp"

int main(){
    TTree<TEspec> arvore;
    tree_init(arvore);

    TEspec b;
    b.cost = 1;
    b.item = "Banana";

    TEspec a;
    a.cost = 2;
    a.item = "Agua";

    TEspec c;
    c.cost = 3;
    c.item = "Canela";

    TEspec d;
    d.cost = 4;
    d.item = "Dado";

   
    tree_insert(arvore,a,12);
    tree_insert(arvore,a,5);
    tree_insert(arvore,a,3);
    tree_insert(arvore,a,7);
    tree_insert(arvore,a,4);
    tree_insert(arvore,a,30);

    cout<<"Arvore balanceada: "<<endl;
    tree_cout_ord_espec(arvore.root);
    cout<<endl;
    tree_search_remove(arvore.root,12);
    cout<<"Arvore balanceada apos item removido: "<<endl;
    tree_cout_ord(arvore.root);


    //TEspec aux = tree_search(arvore.root,5);

    //cout<<"\nCusto:"<<aux.cost;
    //cout<<"\nItem: "<<aux.item;










    return 0;
}

