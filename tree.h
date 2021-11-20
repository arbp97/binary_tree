#ifndef _TREE_H_
#define _TREE_H_

#include <iostream>
#include <vector>

struct Node
{
  int data;
  Node *right;
  Node *left;

  Node (int data);
};

struct Tree
{
  Node *root;

  Tree (int data);
};

/******************************************************************************/

/*
  Carga el arbol con un dataset
*/
void create (Tree * tree, std::vector < int >dataset);

/*
  Utiliza la funcion search para insertar el dato que recibe
  en el arbol indicado, creando un nuevo nodo
*/
void insert (Tree * tree, int data);

/*
  Busca el lugar indicado para un nuevo nodo en el arbol, segun
  el valor del root indicado (node), y lo inserta
*/
void push (Node * node, Node * newNode);

/*
  Busca el dato indicado en el arbol
*/
bool search (Tree * tree, int data);

/******************************************************************************/

//Search Operations

void preOrder (Node * root);

void inOrder (Node * root);

bool preOrderSearch (Node * root, int data, bool * result);

void postOrder (Node * root);

#endif //_TREE_H_
