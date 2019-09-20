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

    
    tree_insert(arvore,b,10);
    tree_insert(arvore,a,5);
    tree_insert(arvore,c,12);
    tree_insert(arvore,d,11);
    /*
    tree_insert_recur(arvore.root,b,10);
    tree_insert_recur(arvore.root,a,5);
    tree_insert_recur(arvore.root,c,12);
    tree_insert_recur(arvore.root,d,11);
    */


    tree_cout_ord_recur(arvore.root);







    return 0;
}

