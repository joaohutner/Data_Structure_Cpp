//Structs
template <typename TIPE>
struct TElement{
  TIPE data;
  TElement<TIPE> *next;
};

template <typename TIPE>
struct TStack{
  TElement<TIPE> *front;
};
//Fim structs
//
//
//Funções auxiliares: 
//
template<typename TIPE>
TElement<TIPE> * new_element_stack(TIPE data){ //retorno do tipo TElemento
  TElement<TIPE> * new_one = new TElement<TIPE>;
  new_one->data = data;
  new_one->next = NULL;
  return new_one;
}
//
//Fim funções auxiliares
//
template <typename TIPE>
void stack_start(TStack <TIPE> &stack){
  stack.front = NULL;
}

template <typename TIPE>
bool stack_insert(TStack<TIPE> &stack, TIPE data){
  TElement<TIPE> *new_one = new_element_stack(data);
  new_one->next = stack.front;
  stack.front = new_one;
  return true;
}

template <typename TIPE>
TIPE stack_remove(TStack<TIPE> &stack){
  TIPE data = stack.front->data;
  TElement<TIPE> *aux;
  aux = stack.front->next;
  delete stack.front;
  stack.front = aux;
  return data;
}