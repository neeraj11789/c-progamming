#include <stdio.h>
#include <stdlib.h>

// Stack Implementation using LinkedList

struct Node{
	int value;
	struct Node *next; 
};

struct Node* createStack(){
	return NULL;
}

void push(struct Node **top, int data){
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
	if(!new_node){
		printf("StackOverFlow!");
		return;
	}
	new_node->value = data;
	new_node->next = *top;
	*top = new_node;
}

int pop(struct Node **top){
	struct Node *current;
	if(!*top){
		printf("Stack is Empty");
		return -1;
	}
	current = *top;
	*top = current->next;
	return current->value;
}

int main(){
	struct Node *top = createStack();
	push(&top, 4);
	push(&top, 3);
	push(&top, 2);
	push(&top, 1);
	printf("%d\n", pop(&top));
	printf("%d\n", pop(&top));
	printf("%d\n", pop(&top));
	printf("%d\n", pop(&top));
	return 1;
}