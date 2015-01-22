#include <stdio.h>
#include <stdlib.h>
/**

Given a sorted array of n integers where each integer is in the range from 0 to m-1 and m > n. Find the smallest number that is missing from the array.

Examples
Input: {0, 1, 2, 6, 9}, n = 5, m = 10
Output: 3

Input: {4, 5, 10, 11}, n = 4, m = 12
Output: 0

Input: {0, 1, 2, 3}, n = 4, m = 5
Output: 4

Input: {0, 1, 2, 3, 4, 5, 6, 7, 10}, n = 9, m = 11
Output: 8

*/


void setArray(int *N, int size){
    int i; // counter
    for(i=0; i<size; i++){
        scanf("%d", N+i);
    }
}

void getArray(int *N, int size){
    int i; // counter
    for(i=0; i<size; i++){
        printf("%d ", *(N+i));
    }
    printf("\n");
}

int missing(int *N, int size){
    int i; // counter
    if(*N != 0){
        return 0;
    }
    for(i=1; i<size-1; i++){
        // compare consecutive elements and check if difference is not 1
        if(*(N+i+1)-*(N+i) != 1){
            return (*(N+i) + 1);
        }
    }
}

int main(){
    int T;
    int *N;
    int missing_element;
    
    printf("Enter the size of array");
    scanf("%d", &T);
    
    N = (int*) malloc(sizeof(int)*T);
    
    setArray(N, T);
    
    missing_element = missing(N,T);
    
    getArray(N, T);

    printf("Missing Element %d\n", missing_element);
    return 1;
}