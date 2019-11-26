#pragma once
class BST {
private:
	struct node {
		int key;
		node* left;
		node* right;
	};
	node* root;
public:
	BST();
	node* CreatLeaf(int key);

};
