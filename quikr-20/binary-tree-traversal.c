#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *createNewNode(int value){
	struct node *n = (struct node *) malloc(sizeof(struct node));
	n->data = value;
	n->left = NULL;
	n->right = NULL;
	return n;
}

void inOrderTraversal(struct node *n){
	if(n == NULL){
		return;
	}
	inOrderTraversal(n->left);
	printf("%d ", n->data);
	inOrderTraversal(n->right);
}

void preOrderTraversal(struct node *n){
	if(n == NULL){
		return;
	}
	printf("%d ", n->data);
	preOrderTraversal(n->left);
	preOrderTraversal(n->right);
}

void postOrderTraversal(struct node *n){
	if(n == NULL){
		return;
	}
	postOrderTraversal(n->left);
	postOrderTraversal(n->right);
	printf("%d ", n->data);
}

int main(){
	struct node *root = createNewNode(1);
	root->left = createNewNode(2);
	root->right = createNewNode(3);
	root->left->left = createNewNode(4);
	root->left->right = createNewNode(5);
	printf("Pre-Order Traversal is : ");
	preOrderTraversal(root);
	printf("\n");

	printf("In-Order Traversal is : ");
	inOrderTraversal(root);
	printf("\n");

	printf("Post-Order Traversal is : ");
	postOrderTraversal(root);
	printf("\n");
	
;	return 0;
}