#include <stdio.h>
/**
Selection Sort: 
65, 75, 90, 12 , 27

0 => 65, 75, 27, 12, 90
1 => 65, 12, 27, 75, 90
2 => 27, 12, 65, 75, 90
3 => 12, 27, 65, 75, 90 
*/

void printArray(int a[], int size){
	int i=0;
	for(i=0; i<size; i++){
		printf("%d  ", a[i]);
	}
	printf("\n");
	return 0;
}

void selectionSort(int a[], int size){
	int i,j;
	int minIndex;
	int temp;
	for(i=0; i<size; i++){
		minIndex = i;
		for(j=0; j<(size-i); j++){
			if(a[minIndex]<a[j]){
				minIndex = j;
			}
		}
		// Swap size-i and minIndex
		temp = a[size-i];
		a[size-i] = a[minIndex];
		a[minIndex] = temp;
		// print array after i iteration
		printArray(a, size);
	}
}

int main(){
	int a[10] = {65, 75, 27, 12, 90};
	int i,j;

	printArray(a, 5);
	selectionSort(a, 5);
	return 1;
}