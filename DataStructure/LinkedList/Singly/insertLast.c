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

void insertLast(struct node *head, int new_data){
	struct node *new_node = (struct node*) malloc(sizeof(struct node));
	struct node *last_node = NULL; 

	new_node->value = new_data;
	new_node->next = NULL;

	while(head!=NULL){
		// Its a last NODE
		if(head->next == NULL){
			last_node = head;	
		}

		head = head->next;
	}

	last_node->next = new_node;
}

void insertLastOther(struct node **head_ref, int new_data){
	struct node *new_node = (struct node*) malloc(sizeof(struct node));
	struct node *last_node = *head_ref; 

	new_node->value = new_data;
	new_node->next = NULL;

	// If the list is empty
	if(*head_ref == NULL){
		*head_ref = new_node;
		//Return is Very Important Here
		return;
	}

	while(last_node->next!=NULL){
		last_node = last_node->next;		
	}
	// Update the last node's next pointer
	last_node->next = new_node;
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
	insertFirst(&HEAD, 12);
	insertFirst(&HEAD, 52);
	insertFirst(&HEAD, 62);
	// Insert at Last
	insertLast(HEAD, 10);
	insertLast(HEAD, 20);
	insertLast(HEAD, 30);
	insertLastOther(&HEAD, 70);
	insertLastOther(&HEAD, 90);
	insertLastOther(&HEAD, 80);
	// Print the List
	printLinkedList(HEAD);
}