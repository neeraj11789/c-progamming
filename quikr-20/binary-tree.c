#include <stdio.h>
#include <stdlib.h>

struct btree{
	int value;
	struct btree *left;
	struct btree *right;
};

struct btree *createBtreeNode(int value){
	struct btree *node = (struct btree *)malloc(sizeof(struct btree));
	node->left = NULL;
	node->right = NULL;
	node->value = value;
	return node;
}

int main(){
	struct btree *root = createBtreeNode(1);
	struct btree *left = createBtreeNode(2);
	struct btree *right = createBtreeNode(3);
	root->left = left;
	root->right = right;
	return 0;
}