#include "binarySearchTree.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
struct  node
{
	int key;
	struct node *left, *right;
};
struct node *newNode(int item)
{
	struct node *temp = (struct node * )malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}
struct node *insert(struct node* node, int key)
{
	if (node == NULL) return newNode(key);
	
	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	return node;
}
void binarySearchTree::inorder(struct node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		std::cout << root->key<<"\n";
		inorder(root->right);
	}
}
void binarySearchTree::preOrder(struct node *root)
{
	if (root == NULL)
	{
		return;
	}
	std::cout << root->key << "\n";
	preOrder(root->left);
	preOrder(root->right);
}
void binarySearchTree::postOrder(struct node *root)
{
	if (root == NULL)
	{
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	std::cout << root->key << "\n";
}
void binarySearchTree::start()
{
	std::cout << "Binary Search Tree\n";
	struct node * root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);
	std::cout << "\nInorder\n";
	inorder(root);
	std::cout << "\nPreOrder\n";
	preOrder(root);
	std::cout << "\nPostOrder\n";
	postOrder(root);
	findKeyInorder(root, 60);
	findLCA(root, 20, 70);
}
void binarySearchTree::findKeyInorder(struct node *root, int val)
{
	if (root != NULL)
	{
		findKeyInorder(root->left,val);
		if (root->key == val)
		{
			std::cout <<"Found "<< root->key << " in tree\n";
		}
		findKeyInorder(root->right,val);
	}
}
bool binarySearchTree::findPath(struct node *root, std::vector<int> &path, int n)
{
	//base case
	if (root == NULL)
	{
		return false;
	}
	path.push_back(root->key);
	if (root->key == n)
	{
		return true;
	}
	if ((findPath(root->left, path, n)) || (findPath(root->right, path, n)))
	{
		return true;
	}
	path.pop_back();
	return false;
}
int binarySearchTree::findLCA(struct node *root, int n1, int n2)
{
	//storing the paths of each key
	std::vector<int> path1, path2;
	if (!findPath(root, path1, n1) || (!findPath(root, path2, n2)))
	{
		return -1;
	}
	int i;
	for (i = 0; i < path1.size() && i < path2.size(); i++)
	{
		if (path1[i] != path2[i])
		{
			break;
		}
	}
	std::cout<<"LCA: of ("<<n1<<","<<n2<<"):"<< path1[i - 1];
	return path1[i - 1];
	
}
binarySearchTree::binarySearchTree()
{
}


binarySearchTree::~binarySearchTree()
{
}
