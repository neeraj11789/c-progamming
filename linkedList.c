#include <stdio.h>
#include <stdlib.h>


struct node {
	int value;
	struct node *next;
};

void *createLinkedList(){
	struct node *head[10] = (struct node*)malloc(sizeof(struct node)); 
	struct node *first = (struct node*)malloc(sizeof(struct node)); 
	struct node *second = (struct node*)malloc(sizeof(struct node)); 
	
	// head->value = 1;
	// head->next = first;

	// first->value = 2;
	// first->next = second;

	// second->value = 3;
	// second->next = NULL;

	//return head;
}

void printLinkedList(struct node *n){
	while(n!=NULL){
		printf("%d\n", n->value);
		n = n->next;
	}
}

void main(){
	createLinkedList();
	//struct node *head = createLinkedList();
	//printLinkedList(head);
}