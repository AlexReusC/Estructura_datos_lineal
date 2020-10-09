#ifndef INSERTANODO_H
#define INSERTANODO_H

#include "Node.h"

void insertaNodo(struct Node * &h, struct Node * &t, Registro dataNode){

  struct Node *tmp = new Node;

  tmp -> data = dataNode;
  tmp -> next = NULL;

  if(h == NULL){

    tmp -> prev = NULL;
    h = tmp;
    t = tmp;

  }
  else{

    tmp -> prev = t;
    t -> next = tmp;

    t = tmp;

  }

}

#endif
