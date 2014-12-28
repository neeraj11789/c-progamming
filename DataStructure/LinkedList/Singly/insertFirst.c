#include <stdio.h>
#include <stdlib.h>

/**

Head -> 2 -> 3 -> 9 -> 7 -> NULL

After Inserting 5 becomes

Head -> 5 -> 2 -> 3 -> 9 -> 7 -> NULL

*/

struct node{
	int value;
	struct node *next;
};

void insertFirst(struct node **head_ref, int new_data){
	struct node *new_node = (struct node*) malloc(sizeof(struct node));
	new_node->value = new_data;
	new_node->next = (*head_ref);
	*head_ref = new_node;
}

void printLinkedList(struct node *n){
	while(n!=NULL){
		printf("%d->", n->value);
		n = n->next;
	}
	printf("\n");
}

void main(){
	struct node *HEAD = NULL;

	insertFirst(&HEAD, 7);
	insertFirst(&HEAD, 9);
	insertFirst(&HEAD, 3);
	insertFirst(&HEAD, 2);

	printLinkedList(HEAD);
}