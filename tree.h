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

void create (Tree * tree, std::vector < int >dataset);

void insert (Tree * tree, int data);

void search (Node * node, Node * newNode);

/******************************************************************************/

//Search Operations

void preOrder (Node * root);

void inOrder (Node * root);

void postOrder (Node * root);


#endif //_TREE_H_
