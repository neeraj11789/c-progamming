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

int IsIdentical(struct node *n1, struct node *n2){
	if(n1==NULL && n2==NULL){
		return 1;
	}
	if(n1!=NULL && n2!=NULL){
		return(
			n1->data==n2->data &&
			IsIdentical(n1->left, n2->left) &&
			IsIdentical(n1->right, n2->right)
			);
	}else{
		return 0;	
	}
}

int main(){
	struct node *root = createNewNode(1);
	root->left = createNewNode(2);
	root->right = createNewNode(3);
	root->left->left = createNewNode(7);
	root->left->right = createNewNode(5);
	root->left->left->left = createNewNode(6);

	struct node *root2 = createNewNode(1);
	root2->left = createNewNode(2);
	root2->right = createNewNode(3);
	root2->left->left = createNewNode(4);
	root2->left->right = createNewNode(5);

	printf("Is Identical : %d\n", IsIdentical(root, root2));

	return 0;
}