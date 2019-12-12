#ifndef SBB_TREE_H_INCLUDED
#define SBB_TREE_H_INCLUDED
template <typename TIPE>
struct TNode{
    int key;
    TIPE data;
    int right_ori;
    int lori;
    TNode<TIPE> *right;
    TNode<TIPE> *left;
};

template <typename TIPE>
struct TTree{
    TNode<TIPE> *root;
};

//
///FUNCTS
//
template<typename TIPE>
void tree_init(TTree<TIPE> &tree){
    tree.root = NULL;
}


//pre fixed to left
template<typename TIPE>
void tree_cout_pre(TNode<TIPE> *node){
    if(node!=NULL){
        cout<<node->key<<" ,";
        tree_cout_pre(node->left);
        tree_cout_pre(node->right);
    }
}


//center to left
template<typename TIPE>
void tree_cout_center(TNode<TIPE> *node){
    if(node!=NULL){
        tree_cout_center(node->left);
        cout<<node->key<<" ,";
        tree_cout_center(node->right);
    }
}

//Post fixed to left
template<typename TIPE>
void tree_cout_pos(TNode<TIPE> *node){
    if(node!=NULL){
        tree_cout_pos(node->left);
        tree_cout_pos(node->right);
        cout<<node->key<<" ,";
    }
}

//
//
///SBB
//
//

template<typename TIPE>
int tree_insert(TNode <TIPE> *&node, int key, TIPE data){
    int n = 0;
    if(node == NULL){
        node = new TNode<TIPE>;
        node->key = key;
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        return 1;
    }
    else{
        if(key > node->key){
            n = tree_insert(node->right, key, data);
            if(n == 1){
                node->right_ori = 1;
                n++;
            }
            else{
                if(n == 2 && node->right_ori == 1){
                    n=1;
                    right_balance(node, key);
                }
                else{
                    n=0;
                }
            }
        }
        else{
            if(key < node->key){
                n = tree_insert(node->left,key,data);
                if(n==1){
                    node->lori = 1;
                    n++;
                }
                else{
                    if(n == 2 && node->lori == 1){
                        n=1;
                        left_balance(node, key);
                    }
                    else{
                        n=0;
                    }
                }
            }
        }
        return n;
    }
}

///Ajustar para SBB
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
void right_balance(TNode <TIPE> *&node, int key){
    if(node->right->right_ori == 1){
        RR_rotation(node);
    }
    else if(node->right->right_ori == 0){
        RL_rotation(node);
    }
}

template<typename TIPE>
void left_balance(TNode <TIPE> *&node, int key){
    if(node->left->lori == 1){
        LL_rotation(node);
    }
    else if(node->left->lori == 0){
        LR_rotation(node);
    }
}

template<typename TIPE>
void LL_rotation(TNode <TIPE> *&node){
    TNode<TIPE> *m = node;
    TNode<TIPE> *h = node->left;
    TNode<TIPE> *f = node->left->left;
    m->left = h->right;
    h->right = m;
    h->left = f;

    m->lori = 0;
    h->lori = 0;
    node = h;
}

template<typename TIPE>
void RR_rotation(TNode <TIPE> *&node){
    TNode<TIPE> *f = node;
    TNode<TIPE> *h = node->right;
    TNode<TIPE> *m = node->right->right;
    f->right = h->left;
    h->left = f;
    h->right = m;

    f->right_ori = 0;
    h->right_ori = 0;
    node = h;
}


template<typename TIPE>
void LR_rotation(TNode <TIPE> *&node){
    TNode<TIPE> *m = node; //a
    TNode<TIPE> *f = node->left; //b
    TNode<TIPE> *h = node->left->right; //c
    f->right = h->left;
    m->left = h->right;
    h->left = f;
    h->right = m;

    f->right_ori = 0;
    m->lori = 0;
    node = h;
}

template<typename TIPE> //com problema
void RL_rotation(TNode <TIPE> *&node){
    TNode<TIPE> *f = node; //a
    TNode<TIPE> *m = node->right; //b
    TNode<TIPE> *h = node->right->left; //c
    m->left = h->right;
    f->right = h->left;
    h->left = f;
    h->right = m;

    f->right_ori = 0;
    m->lori = 0;
    node = h;
}

#endif // SBB_TREE_H_INCLUDED
