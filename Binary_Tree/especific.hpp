struct TEspec{
    string item;
    float cost;
};

template<typename TIPE>
void tree_cout_ord_espec(TNode<TIPE> *node){
    if(node!=NULL){
        cout<<"Key: "<<node->key<<"| Cost: "<<node->data.cost<<"| Item: "<<"|"<<node->data.item<<endl;
        tree_cout_ord_espec(node->left);
        tree_cout_ord_espec(node->right);
    }
}