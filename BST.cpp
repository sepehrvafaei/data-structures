#include<iostream>
#include<cstdlib>
using namespace std;
#include"BST.h"

void BST::destroySubTree(node *nodePtr)
{
   if (nodePtr)
   {
      if (nodePtr->left)
         destroySubTree(nodePtr->left);
      if (nodePtr->right)
         destroySubTree(nodePtr->right);
      delete nodePtr;
   }
BST::node* BST::CreatLeaf(int key) {
	node* n = new node;
	n->key = key;
	n->left = nullptr;
	n->right = nullptr;
}
void BST::insert(int key) {
	BST::AddLeafPrivate(key, root);
}
void BST::insertPrivate(int key, node* Ptr) {
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
void BST::remove(int num)
{
   deleteNode(num, root);
}
void IntBinaryTree::deleteNode(int num, TreeNode *&nodePtr){
   if (num < nodePtr->value)
      deleteNode(num, nodePtr->left);
   else if (num > nodePtr->value)
      deleteNode(num, nodePtr->right);
   else
      makeDeletion(nodePtr);
}
void BST::makeDeletion(BST *&nodePtr){
   BST *tempNodePtr = nullptr;
   if (nodePtr == nullptr){
      cout << "Cannot delete empty node.\n";}
   else if (nodePtr->right == nullptr){
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->left;   
      delete tempNodePtr;
   }
   else if (nodePtr->left == nullptr){
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->right;  
      delete tempNodePtr;
   }
   else{
      tempNodePtr = nodePtr->right;
      while (tempNodePtr->left)
         tempNodePtr = tempNodePtr->left;
      tempNodePtr->left = nodePtr->left;
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->right;
      delete tempNodePtr;
   }
}



