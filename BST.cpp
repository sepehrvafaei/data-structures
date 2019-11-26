#include<iostream>
#include<cstdlib>
using namespace std;
#include"BST.h"

BST::BST() {
	root = nullptr;
}
BST::node* BST::CreatLeaf(int key) {
	node* n = new node;
	n->key = key;
	n->left = nullptr;
	n->right = nullptr;
}


