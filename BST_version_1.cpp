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
BST::node* BST::ReturnNodePrivate(int key, node* ptr) {
	if (ptr != NULL) {
		if (ptr->key == key) {
			return ptr;
		}
		else {
			if (key < ptr->key) {
				return ReturnNodePrivate(key, ptr->left);
			}
			else {
				return ReturnNodePrivate(key, ptr->left);
			}
		}
	}
	else {
		return NULL;
	}
}
BST::node* BST::ReturnNode(int key) {
	return ReturnNodePrivate( key, root);
}
int BST::ReturnRootKey() {
	if (root != NULL) {
		return root->key;
	}
	else {
		return false;
	}
}
void BST::PrintChildren(int key) {
	node* Ptr = ReturnNode(key);
	if (Ptr != NULL) {
		cout << "Parent Node = " << key << endl;
		Ptr->left == NULL ?
			cout << "Left child = NULL\n" :
			cout << "Left child = " << Ptr->left->key << endl; 
		Ptr->left == NULL ?
			cout << "Right child = NULL\n" :
			cout << "Right child = " << Ptr->right->key << endl;
	}
	else {
		cout << "key " << key << "is not in the tree\n";
	}
}
int BST::FindSmallest() {
	return FindSmallestPrivate(root);
}
int BST::FindSmallestPrivate(node* ptr) {
	if (root == NULL) {
		cout << "The tree is empty\n";
		return false;
	}
	else {
		if (ptr->left != NULL) {
			return FindSmallestPrivate(ptr->left);
		}
		else {
			return ptr->key;
		}
	}
}
void BST::RemoveNode(int key) {
	RemoveNodePrivate(key,root);
}
void BST::RemoveNodePrivate(int key, node* parent) {
	if (root != NULL) {
		if(root->key==key){
			RemoveRootMatch();
		}
		else {
			if (key < parent->key && parent->left != NULL) {
				parent->left->key == key ?
					RemoveMatch(parent, parent->left, true) :
					RemoveNodePrivate(key, parent->left);
			}
			else if (key > parent->key && parent->right != NULL) {
				parent->left->key == key ?
					RemoveMatch(parent, parent->right, false) :
					RemoveNodePrivate(key, parent->right);
			}
			else {
				cout << "The key " << key << "was not found in the tree\n";
			}
		}
	}
	else {
		cout << "The tree is empty\n";
	}
}
void BST::RemoveRootMatch() {
	if (root!= NULL) {
		node* delptr = root;
		int rootkey = root->key;
		int smallestInRightSubtree;
		if (root->left == NULL && root->right == NULL) {
			root = NULL;
			delete root;
		}
		else if (root->left == NULL && root->right != NULL) {
			root = root->right;
			delptr->right = NULL;
			delete delptr;
			cout << "The root node with key " << rootkey << " was deleted. " <<
				"The new root contians key " << root->right << endl;

		}
		else if (root->left != NULL && root->right == NULL){
			root = root->left;
			delptr->left = NULL;
			delete delptr;
			cout << "The root node with key " << rootkey << " was deleted. " <<
			"The new root contians key " << root->left << endl;
		}
		else {
			smallestInRightSubtree = FindSmallestPrivate(root->right);
			RemoveNodePrivate(smallestInRightSubtree, root);
			root->key = smallestInRightSubtree;
			cout << "The root key contianing key " << rootkey << 
				" was overwritten " << root->key << endl;
		}
	}
	else {
		cout << "can not remove node,tree is empty\n"<<endl;
	}
}
void BST::RemoveMatch(node* parent, node* match, bool left) {
	if (root != NULL) {
		node* delptr;
		int matchKey = match->key;
		int smallestInRightSubtree;
		if (match->left == NULL && match->right==NULL) {
			delptr = match;
			left == true ? parent->left =NULL : parent->right = NULL;
			delete delptr;
			cout << "The node containing key" << matchKey <<"was removed\n";
		}
		else if (match->left ==NULL && match->right != NULL) {
			left == true ? parent->left = match->left : parent->right = match->right;
			match->right = NULL;
			delete delptr;
			cout<< "The node containing key" << matchKey <<"was removed\n";
		}
		else {
			smallestInRightSubtree = FindSmallestPrivate(match->right);
			RemoveNodePrivate(smallestInRightSubtree, match);
			match->key = smallestInRightSubtree;
		}
	}
	else {
		cout << "can not remove match.tree is empty\n";
	}
}


