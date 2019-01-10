// #include <iostream>
// #include <cstdlib>
// using namespace std;

// struct Node {
// 	char val;
// 	Node* leftChild;
// 	Node* rightChild;
// };

// Node* getNode(Node* left, Node* right) {
// 	if( left != NULL ) return left;
// 	return right;
// }

// Node* findNode(Node* node, char val) {
// 	if( node == NULL ) return NULL;
// 	if( node->val == val ) return node;
// 	return getNode(findNode(node->leftChild, val), findNode(node->rightChild, val));
// }

// void preorder(Node* node) {
// 	cout << node->val;
// 	if(node->leftChild != NULL) preorder(node->leftChild);
// 	if(node->rightChild != NULL) preorder(node->rightChild);
// }

// void inorder(Node* node) {
// 	if(node->leftChild != NULL) inorder(node->leftChild);
// 	cout << node->val;
// 	if(node->rightChild != NULL) inorder(node->rightChild);
// }

// void postorder(Node* node) {
// 	if(node->leftChild != NULL) postorder(node->leftChild);
// 	if(node->rightChild != NULL) postorder(node->rightChild);
// 	cout << node->val;
// }

// void allfree(Node* node) {
// 	if( node == NULL ) return;
// 	allfree(node->leftChild);
// 	allfree(node->rightChild);
// 	free(node);
// }

// int main() {
// 	cin.tie(NULL);
// 	ios_base::sync_with_stdio(false);

// 	int N;
// 	cin >> N;

// 	char val, left, right;
// 	cin >> val >> left >> right;

// 	Node* root = (Node*)malloc(sizeof(Node));
// 	root->val = val;
// 	if( left != '.' ) {
// 		root->leftChild = (Node*)malloc(sizeof(Node));
// 		root->leftChild->val = left;
// 	}
// 	if( right != '.' ) {
// 		root->rightChild = (Node*)malloc(sizeof(Node));
// 		root->rightChild->val = right;
// 	}

// 	for(int i=1; i<N; i++) {
// 		cin >> val >> left >> right;
// 		Node* node = findNode(root, val);
// 		if( node == NULL ) {
// 			cout << "invalid input";
// 			exit(1);
// 		}

// 		if( left != '.' ) {
// 			node->leftChild = (Node*)malloc(sizeof(Node));
// 			node->leftChild->val = left;
// 		}
// 		if( right != '.' ) {
// 			node->rightChild = (Node*)malloc(sizeof(Node));
// 			node->rightChild->val = right;
// 		}
// 	}

// 	preorder(root); cout << '\n';
// 	inorder(root);  cout << '\n';
// 	postorder(root);

// 	allfree(root);
// 	return 0;
// }

#include <cstdio>
using namespace std;

struct Node { 
	char val;
	Node *left, *right;

	Node(char val): val(val), left(0), right(0){}
};

void preorder(Node *node);
void inorder(Node *node);
void postorder(Node *node);

Node *find(Node *node, char val) {
	if (node == 0 || node->val == '.') return NULL;
	if (node->val == val) return node;
	
	Node *ret = find(node->left, val);
	if (ret == NULL) ret = find(node->right, val);
	return ret;
}

void deleteNode(Node *node) {
	if (node == 0) return;

	deleteNode(node->left);
	deleteNode(node->right);
	delete(node);
}

int main(int argc, char *argv[]) {
	int n, i;
	char val, left, right;

	Node *root = 0;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf(" %c %c %c", &val, &left, &right);
		if (i) {
			Node *node = find(root, val);
			node->left = new Node(left);
			node->right = new Node(right);
		} else {
			root = new Node(val);
			root->left = new Node(left);
			root->right = new Node(right);
		}
	}

	preorder(root);		puts("");
	inorder(root);		puts("");
	postorder(root);	puts("");

	deleteNode(root);
	return 0;
}

void preorder(Node *node) {
	if (node->val == '.') return;

	printf("%c", node->val);
	preorder(node->left);
	preorder(node->right);
}

void inorder(Node *node) {
	if (node->val == '.') return;

	inorder(node->left);
	printf("%c", node->val);
	inorder(node->right);
}

void postorder(Node *node) {
	if (node->val == '.') return;

	postorder(node->left);
	postorder(node->right);
	printf("%c", node->val);
}