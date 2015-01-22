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

int sizeOFTree(struct node *n){
	if(n == NULL){
		return 0;
	}
	return sizeOFTree(n->left) + 1 + sizeOFTree(n->right);
}

int max(int a, int b){
	return a>b?a:b;
}

int heightOfTree(struct node *n){
	if(n == NULL){
		return 0;
	}
	return (max(heightOfTree(n->left), heightOfTree(n->right)) + 1);	
}

int main(){
	struct node *root = createNewNode(1);
	root->left = createNewNode(2);
	root->right = createNewNode(3);
	root->left->left = createNewNode(4);
	root->left->right = createNewNode(5);
	root->left->left->left = createNewNode(6);
	printf("Pre-Order Traversal is : ");
	preOrderTraversal(root);
	printf("\n");

	printf("In-Order Traversal is : ");
	inOrderTraversal(root);
	printf("\n");

	printf("Post-Order Traversal is : ");
	postOrderTraversal(root);
	printf("\n");
	
	printf("Size of the tree is %d\n", sizeOFTree(root));
	printf("Height of the tree is %d\n", heightOfTree(root));
	return 0;
}