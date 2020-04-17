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
