#ifndef ESPECIFIC_H_INCLUDED
#define ESPECIFIC_H_INCLUDED
struct TEspec{
    string item;
    float cost;
};


void tree_cout_ord_espec(TNode<TEspec> *node){
    if(node!=NULL){
        cout<<"Key: "<<node->key<<"| Cost: "<<node->data.cost<<" | Item: "<<node->data.item<<" |"<<endl;
        tree_cout_ord_espec(node->left);
        tree_cout_ord_espec(node->right);
    }
}

void cout_espec(TEspec data){
    cout<<endl<<"| Cost: "<<data.cost<<" | Item: "<<data.item<<" |"<<endl;
}




#endif // ESPECIFIC_H_INCLUDED
