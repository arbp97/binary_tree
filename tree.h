#ifndef _TREE_H_
#define _TREE_H_

#include <iostream>
#include <vector>

struct Node
{
  int data;
  int height;
  Node *right;
  Node *left;

  Node(int data);
};

struct Tree
{
  Node *root;

  Tree(int data);
};

/******************************************************************************/

/*
  Carga el arbol con un dataset
*/
void create(Tree *tree, std::vector<int> dataset, int threshold);

/*
  Utiliza la funcion search para insertar el dato que recibe
  en el arbol indicado, creando un nuevo nodo
*/
void insert(Tree *tree, int data, int threshold);

/*
  Busca el lugar indicado para un nuevo nodo en el arbol, segun
  el valor del root indicado (node), y lo inserta
*/
void push(Node **node, Node *newNode, int threshold);

/*
  Busca el dato indicado en el arbol
*/
bool search(Tree *tree, int data);

/*
  Devuelve el balance del nodo
*/
int getBalance(Node *node);

/*
  verifica y balancea un arbol
*/
void balance(Node **root, int threshold);

/*
  Devuelve la altura del nodo
*/
int height(Node *node);

/*
  Hace una rotacion simple a la derecha
*/
Node *rotateRight(Node *node);

/*
  Hace una rotacion simple a la izquierda
*/
Node *rotateLeft(Node *node);

/*
  Hace una rotacion doble, primero derecha y luego izquierda
*/
Node *rotateRightLeft(Node *node);

/*
  Hace una rotacion doble, primero a la izquierda y luego a la derecha
*/
Node *rotateLeftRight(Node *node);

/******************************************************************************/

//Search Operations

void preOrder(Node *root);

void inOrder(Node *root);

bool preOrderSearch(Node *root, int data, bool *result);

void postOrder(Node *root);

#endif //_TREE_H_
