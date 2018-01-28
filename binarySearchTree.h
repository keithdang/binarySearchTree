#pragma once
#include <vector>
class binarySearchTree
{
public:
	void start();
	void inorder(struct node *root);
	void preOrder(struct node *root);
	void postOrder(struct node *root);
	void findKeyInorder(struct node *root, int val);
	int findLCA(struct node *root, int n1, int n2);
	bool findPath(struct node *root,std::vector<int> &path, int n);
	binarySearchTree();
	~binarySearchTree();
};

