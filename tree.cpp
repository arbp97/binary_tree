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
  push(tree->root, newNode);
}

void push(Node* node, Node* newNode)
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
        push(node->left, newNode);
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
        push(node->right, newNode);
      }
    }
    else
    {
    	std::cout << "Node not created: " << newNode->data
			<< " Node already exists..." << std::endl;
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

void inOrder(Node* root)
{
	/*
		Recorrido en Orden:
			1. recorre subarbol izquierdo en simetrico
			2. visita la raiz
			3. recorre subarbol derecho en simetrico
	*/

	// si existe hijo izquierdo de root, entramos en su subarbol
	if (root->left) inOrder(root->left);

	// si ya no existe un hijo izquierdo, se imprime el root actual,
	// que seria el hijo izquierdo del root anterior
	std::cout << "[" << root->data << "], ";

	// luego de verificar el hijo izquierdo, se pasa por el derecho
	// hasta llegar al fondo
	if(root->right) inOrder(root->right);
}

bool preOrderSearch(Node* root, int data, bool * result)
{
	/* Si se encuentra el dato, se levanta el flag */
	if (root->data == data) *result = true;

	/*
		Si el dato aun no se ha encontrado, sigue recorriendo los
		subarboles
	*/
	if(root->left && !(*result)) preOrderSearch(root->left, data, result);

	if(root->right && !(*result)) preOrderSearch(root->right, data, result);

	return result;
}

void postOrder(Node* root)
{
	/*
		Recorrido en postOrden:
			1.recorre subarbol izquierdo en orden final
			2. recorre subarbol derecho en orden final
			3. visita la raiz
	*/

	// si existe hijo izquierdo de root, entramos en su subarbol
	if (root->left) postOrder(root->left);

	// luego de verificar el hijo izquierdo, se pasa por el derecho
	if(root->right) postOrder(root->right);

	/*
		cuando agotamos las posibilidades, llegando al fondo del arbol,
		se imprime la raiz
	*/
	std::cout << "[" << root->data << "], ";
}

bool search(Tree* tree, int data)
{
	bool result = false;

	if (!tree->root)
		std::cout << "\nError: empty tree" << '\n';

	preOrderSearch(tree->root, data, &result);

	return result;
}
