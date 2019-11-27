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
void BST::AddLeaf(int key) {
	BST::AddLeafPrivate(key, root);
}
void BST::AddLeafPrivate(int key, node* Ptr) {
	if (root == nulptr) {
		root = CraetLeaf(key);
	}
	else if(key < Ptr->key){
		if (Ptr->left != nullptr) {
			AddLeafPrivate(key, Ptr->left);
		}
		else {
			Ptr->left = CreatLeaf(key);
		}
	}
	else if (key > Ptr->key) {
		if (Ptr->right != nullptr) {
			AddLeafPrivate(key, Ptr->right);
		}
		else {
			Ptr->right = CreatLeaf(key);
		}
	}
	else {
		cout << "The key " << key << "has already been added to the tree\n";
	}
}
void BST::PrintInOrder() {
	BST::PrintInOrderPrivate(root);
}
void BST::PrintInOrderPrivate(node* Ptr) {
	if (root != nullptr) {
		if (Ptr->key != nullptr) {
			PrintInOrderPrivate(Ptr->left);
		}
		cout << Ptr->key << " ";
		if (Ptr->right != nullptr) {
			PrintInOrderPrivate(Ptr->right);
		}
		cout << Ptr->key << " ";
	}
	else {
		cout << "The tree is empty.\n";
	}
}



