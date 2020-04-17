#pragma once
class BST {
private:
	struct node {
		int key;
		node* left;
		node* right;
	};
	node* root;
	void destroySubTree(node *);
	void insertPrivate(int key,node* Ptr);
	node* ReturnNodePrivate(int key, node* ptr);
	int FindSmallestPrivate(node* ptr);
	void deleteNode(int, node *&);
	void makeDeletion(node *&);
	void PrintInOrder(node *) const;
	void PrintPreOrder(node *) const;
	void PrintPostOrder(node *) const;

public:
	BST(){root=nullptr;}
	~BST(){ destroySubTree(root); }
	node* CreatLeaf(int key);
	void insert(int key);
	node* ReturnNode(int key);
	int ReturnRootKey();
	void PrintChildren(int key);
	int FindSmallest();
	void PrintHierarchy();
	void RemoveNode(int key);
	void PrintInOrder() const;
	void PrintPreOrder() const;
	void PrintPostOrder() const;

};
