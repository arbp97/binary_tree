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
    //std::cout << newNode->data;
    if(newNode->data < node->data)
    {
        if(!node->left)
        {
            node->left = newNode;
        }
        else
        {
            search(node->left, newNode);
        }
    }
    else if(newNode->data > node->data)
    {
        if(!node->right)
        {
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
    std::cout << "[" << root->data << "], ";
    
    if(root->left) preOrder(root->left);
    
    if(root->right) preOrder(root->right);
}

void inOrder(Node* root);

void postOrder(Node* root);





