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
void tree_cout_ord_recur(TNode<TIPE> *node){
    if(node!=NULL){
        cout<<node->key<<" ,";
        tree_cout_ord_recur(node->left);
        tree_cout_ord_recur(node->right);
    }
}

template<typename TIPE>
void tree_cout_ord(TNode<TIPE> node){
    
}

//Inicializa
//Insere

