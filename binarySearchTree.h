#pragma once
class binarySearchTree
{
public:
	void start();
	void inorder(struct node *root);
	void preOrder(struct node *root);
	void postOrder(struct node *root);
	binarySearchTree();
	~binarySearchTree();
};

