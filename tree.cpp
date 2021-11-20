#include "tree.h"

#include <iostream>

Node::Node(int data)
{
	this->data = data;
	this->left = NULL;
	this->right = NULL;
};

Tree::Tree(int data)
{
	this->root = new Node(data);
};

/******************************************************************************/

void create(Tree* tree, std::vector<int> dataset)
{
  for(int data : dataset)
  {
    insert(tree, data);
  }
}

void insert(Tree* tree, int data)
{
  Node* newNode = new Node(data);
  search(tree->root, newNode);
}

void search(Node* node, Node* newNode)
{
    /* Si el nuevo nodo es menor que root (node), debemos
		 colocarlo a la izquierda */
    if(newNode->data < node->data)
    {
			// Si el hijo izquierdo no ha sido seteado...
      if(!node->left)
      {
				// el nuevo nodo ocupa su lugar
        node->left = newNode;
      }
      else
      {
				/*
					Caso contrario, llamamos recursivamente a la funcion
					para buscar en el subarbol correspondiente
				*/
        search(node->left, newNode);
      }
    }
		/*
			Si el nuevo nodo es mayor que root, se debe colocar a la derecha
		*/
    else if(newNode->data > node->data)
    {
			// si el hijo derecho no ha sido seteado
      if(!node->right)
      {
				// se setea con el nuevo nodo
        node->right = newNode;
      }
      else
      {
        search(node->right, newNode);
      }
    }
    else
    {
    	std::cout << "invalid dataset";
    }
}

/******************************************************************************/

void preOrder(Node* root)
{
	/*
		Recorrido en preOrden:
			1. visita la raiz
			2. recorre subarbol izquierdo en preOrden
			3. recorre subarbol derecho en preOrden
	*/

	std::cout << "[" << root->data << "], ";

	/*
		si el hijo izquierdo del root existe, entonces
		se recorre el subarbol izquierdo recursivamente
	*/
	if(root->left) preOrder(root->left);

	/*
		si el hijo derecho del root existe, entonces
		se recorre el subarbol derecho recursivamente
	*/
	if(root->right) preOrder(root->right);
}

void inOrder(Node* root);

void postOrder(Node* root);
