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
    
    TEspec e;
    e.cost = 120;
    e.item = "Esmeralda";

    TEspec f;
    f.cost = 10;
    f.item = "Farinha";

    TEspec g;
    g.cost = 20;
    g.item = "Galinha";
   
    
    tree_insert(arvore,a,4);
    tree_insert(arvore,b,2);
    tree_insert(arvore,c,6);
    tree_insert(arvore,d,1);
    tree_insert(arvore,e,3);
    tree_insert(arvore,f,5);
    tree_insert(arvore,g,7);

    cout<<"Arvore balanceada: "<<endl;
    tree_cout_ord_espec(arvore.root);
    cout<<endl;
    /*
    tree_search_remove(arvore.root,12);
    cout<<"Arvore balanceada apos item removido: "<<endl;
    tree_cout_ord_espec(arvore.root); */

    cout<<endl;
    cout<<endl;
    tree_cout_pre(arvore.root);
    cout<<endl;
    tree_cout_center(arvore.root);
    cout<<endl;
    tree_cout_pos(arvore.root);

    //com erro:
    //cout_espec(tree_search(arvore.root,4));


    return 0;
}

