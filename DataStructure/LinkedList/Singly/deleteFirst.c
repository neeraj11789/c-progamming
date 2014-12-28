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


void insertAtEnd(struct node **head_ref, int new_data){
	struct node *new_node = (struct node*) malloc(sizeof(struct node));
	struct node *last_node = *head_ref; 

	new_node->value = new_data;
	new_node->next = NULL;

	// If the list is empty
	if(*head_ref == NULL){
		*head_ref = new_node;
		return;
	}

	while(last_node->next!=NULL){
		last_node = last_node->next;		
	}
	// Update the last node's next pointer
	last_node->next = new_node;
}

void deleteFirst(struct node **head_ref){
	if(*head_ref == NULL){
		printf("Nothing to Delete");
		return;
	}
	struct node *temp = *head_ref;
	*head_ref = temp->next;
	free(temp);
}

void printLinkedList(struct node *n){
	while(n!=NULL){
		printf("%d->", n->value);
		n = n->next;
	}
	printf("\n");
}

void deleteKey(struct node **head_ref, int key){
	// If the key is there in the Head
	struct node *temp = *head_ref;
	struct node *prev = NULL;

	if (temp!=NULL && temp->value==key){
		*head_ref = temp->next;
		free(temp);
		return;
	}

	while(temp!=NULL && temp->value!=key){
		prev = temp;
		temp = temp->next;
	}

	if(temp == NULL){
		printf("Not Found");
		return;
	}

	prev->next = temp->next;
	free(temp);
	return;
}


void main(){
	struct node *HEAD = NULL;
	
	insertAtEnd(&HEAD, 7);
	insertAtEnd(&HEAD, 9);
	insertAtEnd(&HEAD, 3);
	insertAtEnd(&HEAD, 2);
	insertAtEnd(&HEAD, 12);
	insertAtEnd(&HEAD, 52);
	insertAtEnd(&HEAD, 62);
	// Insert at Last
	insertAtEnd(&HEAD, 10);
	insertAtEnd(&HEAD, 20);
	insertAtEnd(&HEAD, 30);
	insertAtEnd(&HEAD, 70);
	insertAtEnd(&HEAD, 90);
	insertAtEnd(&HEAD, 80);
	// Print the List
	printLinkedList(HEAD);
	// Delete the First Node
	deleteFirst(&HEAD);
	printLinkedList(HEAD);
	// Delete Key where element was at first place
	deleteKey(&HEAD, 9);
	printLinkedList(HEAD);
	// Delete key containing element
	deleteKey(&HEAD, 52);
	printLinkedList(HEAD);
	// Delete non-existent element
	deleteKey(&HEAD, 53);
	printLinkedList(HEAD);
}