#ifndef IMPRIMELISTATILE_H
#define IMPRIMELISTATILE_H

#include "Node.h"

void imprimeListaTile(struct Node *t){

  while(t != NULL){

    cout << t -> data.print(0) << endl;
    t = t -> prev;

  }

}

#endif
