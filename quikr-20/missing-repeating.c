#include <stdio.h>
#include <stdlib.h>
/**
Given an unsorted array of size n. Array elements are in range from 1 to n. One number from set {1, 2, …n} is missing and one number occurs twice in array. Find these two numbers.

Example: 
	arr[] = {3, 1, 3}
	Output: 2, 3   // 2 is missing and 3 occurs twice 

	arr[] = {4, 3, 6, 2, 1, 1}
	temp[1, 0, 0, 0, -1, 0]
	Output: 1, 5  // 5 is missing and 1 occurs twice 
*/
void printArray(int N[], int size){
    int i=0;
    int maxIndex = size;
    for(i=0; i<maxIndex; i++){
        printf("%d ", N[i]);
    }
    printf("\n");
}

int* findMissingRepeating(int N[], int size){
	int static result[2] = {0,0};
	int temp[size+1];
	int i;
	// Initiliaze all to zero
	for(i=1; i<=size; i++){
		temp[i] = -1;
	}
	//map the new array to number of occurences
	for(i=0; i<size; i++){
		temp[N[i]] += 1;
	}
	//map the new array to number of occurences
	for(i=1; i<=size; i++){
		if(temp[i] == -1){
			result[0] = i;
		}
		if(temp[i] == 1){
			result[1] = i;
		}
	}
	return result;
}

int main(){
	int N[10] = {4, 3, 6, 2, 1, 1};
	int *result = (int*)malloc(sizeof(int)*2);
	printArray(N,6);
	result = findMissingRepeating(N,6);
	printf("Result is the following : 1st is missing 2nd is repeatetive : ");
	printArray(result,2);
	return 0;
}