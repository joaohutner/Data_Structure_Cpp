template <typename TIPE>
struct TNode{
    int key;
    TIPE data;
    TNode<TIPE> *right;
    TNode<TIPE> *left;
};

template <typename TIPE>
struct TTree{
    TNode<TIPE> *root;
};

//
//AUX FUNCTS
//
template<typename TIPE>
TNode<TIPE> * new_tree_element(TIPE data, int key){
    TNode<TIPE> *new_tree = new TNode<TIPE>;
    new_tree->left = NULL;
    new_tree->right = NULL;
    new_tree->key = key;
    new_tree->data = data;
    return new_tree;
}
//
//FUNCTS
//
template<typename TIPE>
void tree_init(TTree<TIPE> &tree){
    tree.root = NULL;
}

template<typename TIPE>
bool tree_insert(TTree<TIPE> &tree, TIPE data, int key){
    if(tree.root==NULL){
        tree.root = new_tree_element(data,key);
        return true;
    }
    else{
        TNode<TIPE> *aux = tree.root;
        TNode<TIPE> *ant;
        while(aux != NULL){
            if(key > aux->key){
                ant = aux;
                aux = aux->right;
            }
            else{
                ant = aux;
                aux = aux->left;
            }
        }
        if(key > ant->key){
            ant->right = new_tree_element(data,key);
        }
        else{
            ant->left = new_tree_element(data,key);
        }
        return true;
    }

}

template <typename TIPE>
void tree_insert_recur(TNode<TIPE> *&node, TIPE data, int key){
    if(node == NULL){
        node = new_tree_element(data,key);
    }
    else{
        if(key>node->key){
            tree_insert_recur(node->right,data,key);
        }
        else{
            tree_insert_recur(node->left,data,key);
        }
    }
}

template<typename TIPE>
void tree_remove(TNode<TIPE> *&node){
    TNode<TIPE> *bigger = node->left;
    TNode<TIPE> *del;
    if(bigger == NULL){
       del = node;
       node = node->right;
       delete del;
       return;
    }
    TNode<TIPE> *dad = NULL;
    while(bigger->right!=NULL){
        dad = bigger;
        bigger = bigger->right;
    }
    bigger->right = node->right;
    if(dad != NULL){
        dad->right = bigger->left;
        bigger->left = node->left;
    }
    del = node;
    node = bigger;
    delete del;
}

template<typename TIPE>
void tree_search_remove(TNode<TIPE> *&node, int key){
    if(node != NULL){
        if(node->key == key){
            tree_remove(node);
        }
        else{
            if(key>node->key){
                tree_search_remove(node->right,key);
            }
            else{
                tree_search_remove(node->left,key);
            }
        }
    }
}

template<typename TIPE>
TIPE tree_search(TNode<TIPE> *&node, int key){
    if(node != NULL){
        if(node->key == key){
            TIPE data = node->data;
            return data;
        }
        else{
            if(key>node->key){
                tree_search(node->right,key);
            }
            else{
                tree_search(node->left,key);
            }
        }
    }
}

//pre fixed to left
//Visita a raiz. Percorre a sub-árvore esquerda. Percorre a sub-árvore direita
template<typename TIPE>
void tree_cout_pre(TNode<TIPE> *node){
    if(node!=NULL){
        cout<<node->key<<" ,";
        tree_cout_pre(node->left);
        tree_cout_pre(node->right);
    }
}

//center to left
//Percorre a sub-árvore esquerda. Visita a raiz. Percorre a sub-árvore direita 
template<typename TIPE>
void tree_cout_center(TNode<TIPE> *node){
    if(node!=NULL){
        tree_cout_center(node->left);
        cout<<node->key<<" ,";
        tree_cout_center(node->right);
    }
}

//Post fixed to left
//Percorre a sub-árvore esquerda. Percorre a sub-árvore direita. Visita a raiz
template<typename TIPE>
void tree_cout_pos(TNode<TIPE> *node){
    if(node!=NULL){
        tree_cout_pos(node->left);
        tree_cout_pos(node->right);
        cout<<node->key<<" ,";
    }
}



