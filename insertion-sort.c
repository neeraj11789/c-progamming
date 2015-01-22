#include <stdio.h>
// 12,2,4,54,5,35,34,33,4,5
// 2,12 ...
// 2,4,12 ...
// 2,4,12,54 ... => 2,4,12,54,5 => 
// 2,4,5,12,54 .. 

void printArray(int N[], int size){
    int i=0;
    int maxIndex = size-1;
    for(i=0; i<maxIndex; i++){
        printf("%d ", N[i]);
    }
    printf("\n");
}

void insertElementInSortedArray(int N[], int size){
    int i=0, temp;
    for(i=size; i>=0; i--){
        if(N[i-1] < N[i]){
            // swap the elements
            temp = N[i];
            N[i] = N[i-1];
            N[i-1] = temp 
        }
    }
}

void insertionSort(int N[], int size){
    int i;
    int maxIndex = size-1;
    for(i=1; i<maxIndex; i++){
        // Insert i in the sorted array
        insertElementInSortedArray(N, i);
    }
}

int main(){
    int N[10] = {12,2,4,54,5,35,34,33,4,5};
    printArray(N,10);
    insertionSort(N);
    printArray(N,10);
    return 0;
}