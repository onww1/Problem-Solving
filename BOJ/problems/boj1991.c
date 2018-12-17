#include <stdio.h>
#include <stdlib.h>

typedef struct Tree{
	char c;
	struct Tree *left;
	struct Tree *right;
} Tree;

void insert(Tree* root, char* data){
	if(root->c == data[0]){
		if(data[1] != '.'){ 
			root->left = (Tree*)malloc(sizeof(Tree)); 
			root->left->c = data[1]; 
		}
		if(data[2] != '.'){
			root->right = (Tree*)malloc(sizeof(Tree));
			root->right->c = data[2];
		}
	} else {
		if(root->left != NULL) insert(root->left, data);
		if(root->right != NULL) insert(root->right, data);
	}
}

void preorder(Tree* root){
	printf("%c", root->c);
	if(root->left != NULL) preorder(root->left);
	if(root->right != NULL) preorder(root->right);
}

void inorder(Tree* root){
	if(root->left != NULL) inorder(root->left);
	printf("%c", root->c);
	if(root->right != NULL) inorder(root->right);
}

void postorder(Tree* root){
	if(root->left != NULL) postorder(root->left);
	if(root->right != NULL) postorder(root->right);
	printf("%c", root->c);
}

void delete(Tree* root){
	if(root->left != NULL) delete(root->left);
	if(root->right != NULL) delete(root->right);
	free(root);
}

int main(void){
	int N;
	char in[3];
	Tree *root = NULL;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%c %c %c", &in[0], &in[1], &in[2]);
		if(root != NULL) insert(root, in);
		else{
			root = (Tree*)malloc(sizeof(Tree));
			root->c = in[0];
			if(in[1] != '.'){ 
				root->left = (Tree*)malloc(sizeof(Tree)); 
				root->left->c = in[1]; 
			}
			if(in[2] != '.'){
				root->right = (Tree*)malloc(sizeof(Tree));
				root->right->c = in[2];
			}
		} 
	}
	if(root != NULL) preorder(root); printf("\n");
	if(root != NULL) inorder(root); printf("\n");
	if(root != NULL) postorder(root); printf("\n");
	if(root != NULL) delete(root);
	return 0;
}