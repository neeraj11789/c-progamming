#include <stdio.h>
#include <stdlib.h>

struct Stack
{
	int topIndex;
	int stackSize;
	int *elements;
};

struct Stack *createStack(int size){
	struct Stack *S = malloc(sizeof(struct Stack));
	if(!S){
		printf("No Memory for creating Stack");
		return;
	}
	S->topIndex = -1;
	S->stackSize = size;
	S->elements = malloc(size * sizeof(int));
	return S;
}

int push(struct Stack *S, int ele){
	if(isFullStack(S)){
		printf("Stack is FULL");
		return 0;
	}
	S->topIndex++;
	S->elements[S->topIndex] = ele;
	return 1;
}

int pop(struct Stack *S){
	if(isEmptyStack(S)){
		printf("Stack is Empty");
		return 0;
	}
	return S->elements[S->topIndex--];
}

int isEmptyStack(struct Stack *S){
	return (S->topIndex==-1);
}

int isFullStack(struct Stack *S){
	return (S->topIndex == S->stackSize-1);
}

void main(){
	int i;
	struct Stack *stack = createStack(100);
	for (i = 0; i < 100; i++)
	{
		push(stack, i*10);
	}
	while(!isEmptyStack(stack)){
		printf("%d\n", pop(stack));
	}
}