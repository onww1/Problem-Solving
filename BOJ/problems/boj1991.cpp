#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
	char val;
	Node* leftChild;
	Node* rightChild;
};

Node* getNode(Node* left, Node* right) {
	if( left != NULL ) return left;
	return right;
}

Node* findNode(Node* node, char val) {
	if( node == NULL ) return NULL;
	if( node->val == val ) return node;
	return getNode(findNode(node->leftChild, val), findNode(node->rightChild, val));
}

void preorder(Node* node) {
	cout << node->val;
	if(node->leftChild != NULL) preorder(node->leftChild);
	if(node->rightChild != NULL) preorder(node->rightChild);
}

void inorder(Node* node) {
	if(node->leftChild != NULL) inorder(node->leftChild);
	cout << node->val;
	if(node->rightChild != NULL) inorder(node->rightChild);
}

void postorder(Node* node) {
	if(node->leftChild != NULL) postorder(node->leftChild);
	if(node->rightChild != NULL) postorder(node->rightChild);
	cout << node->val;
}

void allfree(Node* node) {
	if( node == NULL ) return;
	allfree(node->leftChild);
	allfree(node->rightChild);
	free(node);
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	char val, left, right;
	cin >> val >> left >> right;

	Node* root = (Node*)malloc(sizeof(Node));
	root->val = val;
	if( left != '.' ) {
		root->leftChild = (Node*)malloc(sizeof(Node));
		root->leftChild->val = left;
	}
	if( right != '.' ) {
		root->rightChild = (Node*)malloc(sizeof(Node));
		root->rightChild->val = right;
	}

	for(int i=1; i<N; i++) {
		cin >> val >> left >> right;
		Node* node = findNode(root, val);
		if( node == NULL ) {
			cout << "invalid input";
			exit(1);
		}

		if( left != '.' ) {
			node->leftChild = (Node*)malloc(sizeof(Node));
			node->leftChild->val = left;
		}
		if( right != '.' ) {
			node->rightChild = (Node*)malloc(sizeof(Node));
			node->rightChild->val = right;
		}
	}

	preorder(root); cout << '\n';
	inorder(root);  cout << '\n';
	postorder(root);

	allfree(root);
	return 0;
}