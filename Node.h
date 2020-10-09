#ifndef NODE_H
#define NODE_H

struct Node{
  struct Node *prev;
  Registro data;
  struct Node *next;
};

#endif
