#include <iostream>
#include <string.h>
using namespace std;
#include "SBB_tree.h"
#include "especific.h"

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

    //LL ok RR ok
    //LR nao ok
    tree_insert(arvore.root,10,a);
    tree_insert(arvore.root,9,a);
    tree_insert(arvore.root,17,a);
    tree_insert(arvore.root,15,a);
    tree_insert(arvore.root,19,a);
    tree_insert(arvore.root,21,a);
    tree_insert(arvore.root,20,a);


    cout<<endl;
    cout<<endl;
    tree_cout_pre(arvore.root);
    cout<<endl;


    return 0;
}

