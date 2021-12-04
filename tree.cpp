#include "tree.h"

#include <iostream>

Node::Node(int data)
{
	this->data = data;
	this->height = 0;
	this->left = NULL;
	this->right = NULL;
};

Tree::Tree(int data)
{
	this->root = new Node(data);
};

/******************************************************************************/

void create(Tree *tree, std::vector<int> dataset, int threshold)
{
	for (int data : dataset)
	{
		insert(tree, data, threshold);
		std::cout << "inserted "<< data << std::endl;
		getchar();
	}

	std::cout << "AFTER CREATING, tree root: "<< tree->root->data << std::endl;
	std::cout << "tree root left: "<< tree->root->left->data << std::endl;
	std::cout << "tree root right: "<< tree->root->right->data << std::endl;
}

void insert(Tree *tree, int data, int threshold)
{
	Node *newNode = new Node(data);
	std::cout << "BEFORE PUSH ROOT!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!111:  "<< tree->root->data << std::endl;
	push(tree->root, newNode, threshold);
	std::cout << "AFTER PUSH ROOT!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!111  "<< tree->root->data << std::endl;
}

void push(Node *node, Node *newNode, int threshold)
{
	/* Si el nuevo nodo es menor que root (node), debemos
		 colocarlo a la izquierda */
	std::cout << "entering push" << std::endl;
	if (newNode->data < node->data)
	{
		std::cout << "newnode "<< newNode->data << " is less than root " << node->data << std::endl;
		// Si el hijo izquierdo no ha sido seteado...
		if (!node->left)
		{
			std::cout << "found place to put node in LEFT" << std::endl;
			// el nuevo nodo ocupa su lugar
			node->left = newNode;

			newNode->height = 1 +
							  std::max(height(newNode->left), height(newNode->right));

			//balance(newNode, threshold);
		}
		else
		{
			/*
				Caso contrario, llamamos recursivamente a la funcion
				para buscar en el subarbol correspondiente
			*/
			std::cout << "going down left" << std::endl;
			push(node->left, newNode, threshold);
		}
	}
	/*
			Si el nuevo nodo es mayor que root, se debe colocar a la derecha
		*/
	else if (newNode->data > node->data)
	{
		std::cout << "newnode "<< newNode->data << " is greater than root " << node->data << std::endl;
		// si el hijo derecho no ha sido seteado
		if (node->right)
		{
			std::cout << "found place to put node in RIGHT" << std::endl;
			// se setea con el nuevo nodo
			node->right = newNode;

			newNode->height = 1 +
							  std::max(height(newNode->left), height(newNode->right));

			//balance(newNode, threshold);
		}
		else
		{
			std::cout << "going down right" << std::endl;
			push(node->right, newNode, threshold);
		}
	}
	else
	{
		std::cout << "Node not created: " << newNode->data
				  << " Node already exists..." << std::endl;
	}

	std::cout << "past if/else block" << std::endl;
	node->height = 1 +
				   std::max(height(node->left), height(node->right));
	std::cout << "balancing node: "<< node->data << std::endl;
	balance(node, threshold);
	std::cout << "balanced node now is: "<< node->data << std::endl;
}

int height(Node *node)
{
	int h;

	if (node)
		h = node->height;
	else
		h = -1;

	return h;
}

int getBalance(Node *node)
{
	int b;

	if (node)
		b = height(node->left) - height(node->right);
	else
		b = 0;

	return b;
}

void balance(Node *root, int threshold)
{	//AFTER EXITING BALANCE, NODE DOESNT CHANGE, HERE IS THE BUG?????????????????????????
	std::cout << "entering balance" << std::endl;
	int rootBalance = getBalance(root);
	std::cout << "got balance" << std::endl;
	/*
	si el balance del nodo es mayor a nuestro limite,
	entonces el arbol esta desbalanceado hacia la izquierda.
	tenemos que mover nodos hacia la derecha para tener balance.
	*/
	if (rootBalance > threshold)
	{
		std::cout << "balance is greather than threshold" << std::endl;
		std::cout << "before rotation: root: "<< root->data << std::endl;
		if (getBalance(root->left) >= 0)
			root = rotateRight(root);
		else
			root = rotateLeftRight(root);
		std::cout << "after rotation: root: "<< root->data << std::endl;
		std::cout << "after rotation: root-right: "<< root->right->data << std::endl;
	}
	/*
	si el balance del nodo es menor que nuestro limite,
	el arbol esta desbalanceado hacia la derecha.
	tenemos que mover nodos hacia la izquierda.
	*/
	else if (rootBalance < -threshold)
	{
		std::cout << "balance is less than threshold" << std::endl;
		if (getBalance(root->right) <= 0)
			root = rotateLeft(root);
		else
			root = rotateRightLeft(root);
	}
	std::cout << "exit balance" << std::endl;
}

Node *rotateRight(Node *node)
{
	std::cout << "rotating right" << std::endl;
	Node *tmp = node->left;

	node->left = tmp->right;
	tmp->right = node;

	node->height = 1 +
				   std::max(height(node->left), height(node->right));

	tmp->height = 1 +
				  std::max(height(tmp->left), height(tmp->right));

	return tmp;
}

Node *rotateLeft(Node *node)
{
	std::cout << "rotating left" << std::endl;
	Node *tmp = node->right;

	node->right = tmp->left;
	tmp->left = node;

	node->height = 1 +
				   std::max(height(node->left), height(node->right));

	tmp->height = 1 +
				  std::max(height(tmp->left), height(tmp->right));

	return tmp;
}

Node *rotateRightLeft(Node *node)
{
	node->right = rotateRight(node->right);

	return rotateLeft(node);
}

Node *rotateLeftRight(Node *node)
{
	node->left = rotateLeft(node->left);

	return rotateRight(node);
}

/******************************************************************************/

void preOrder(Node *root)
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
	if (root->left)
		preOrder(root->left);

	/*
		si el hijo derecho del root existe, entonces
		se recorre el subarbol derecho recursivamente
	*/
	if (root->right)
		preOrder(root->right);
}

void inOrder(Node *root)
{
	/*
		Recorrido en Orden:
			1. recorre subarbol izquierdo en simetrico
			2. visita la raiz
			3. recorre subarbol derecho en simetrico
	*/

	// si existe hijo izquierdo de root, entramos en su subarbol
	if (root->left)
		inOrder(root->left);

	// si ya no existe un hijo izquierdo, se imprime el root actual,
	// que seria el hijo izquierdo del root anterior
	std::cout << "[" << root->data << "], ";

	// luego de verificar el hijo izquierdo, se pasa por el derecho
	// hasta llegar al fondo
	if (root->right)
		inOrder(root->right);
}

bool preOrderSearch(Node *root, int data, bool *result)
{
	/* Si se encuentra el dato, se levanta el flag */
	if (root->data == data)
		*result = true;

	/*
		Si el dato aun no se ha encontrado, sigue recorriendo los
		subarboles
	*/
	if (root->left && !(*result))
		preOrderSearch(root->left, data, result);

	if (root->right && !(*result))
		preOrderSearch(root->right, data, result);

	return result;
}

void postOrder(Node *root)
{
	/*
		Recorrido en postOrden:
			1.recorre subarbol izquierdo en orden final
			2. recorre subarbol derecho en orden final
			3. visita la raiz
	*/

	// si existe hijo izquierdo de root, entramos en su subarbol
	if (root->left)
		postOrder(root->left);

	// luego de verificar el hijo izquierdo, se pasa por el derecho
	if (root->right)
		postOrder(root->right);

	/*
		cuando agotamos las posibilidades, llegando al fondo del arbol,
		se imprime la raiz
	*/
	std::cout << "[" << root->data << "], ";
}

bool search(Tree *tree, int data)
{
	bool result = false;

	if (!tree->root)
		std::cout << "\nError: empty tree" << '\n';

	preOrderSearch(tree->root, data, &result);

	return result;
}
