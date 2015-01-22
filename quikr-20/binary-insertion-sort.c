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

int binarySearch(int N[], int l, int r, int key){
    int mid = l + (r-l+1)/2;
    if(r<l){
        return -1;
    }
    if(key==N[mid]){
        return 0;
    }
    if(key>N[mid]){
        return binarySearch(N,mid+1,r,key);
    }else{
        return binarySearch(N,l,mid-1,key);
    }
}

void insertElementInSortedArray(int N[], int maxIndex){
    printf("Going to Sort Array : ");
    printArray(N,maxIndex+1);
    int key = N[maxIndex];
    printf("Key is %d\n", key);
    int key_position = binarySearch(N,0,maxIndex-1,key);
    printf("KeyPosition is %d\n", key_position);
    int i;
    for(i=maxIndex; i>key_position; i++){
        N[maxIndex] = N[maxIndex-1];
    }
    N[key_position] = key;
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
    insertionSort(N,10);
    printArray(N,10);
    return 0;
}