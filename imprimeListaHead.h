#ifndef IMPRIMELISTAHEAD_H
#define IMPRIMELISTAHEAD_H

#include "Node.h"

void imprimeListaHead(struct Node *h){

  while(h != NULL){

    cout << h -> data.print(0) << endl;
    h = h -> next;

  }

}

#endif
