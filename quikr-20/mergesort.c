#include <stdio.h>
// 12,11,13,5,6,7,1,5,3,2
// 12,11,13,5,6
// 12,11,13 5,6
// 12,11 13
// 12 11 13

void printArray(int N[], int size){
    int i=0; // counter
    for(i=0; i<size-1; i++){
        printf("%d ", N[i]);
    }
    printf("\n");
}

/* Function to merge the two haves arr[l..m] and arr[m+1..r] of array arr[] */
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int N[], int l, int r){
    int m;
    if(l<r){
        m = l+(r-1)/2;
        mergesort(N,l,m);
        mergesort(N,m+1,r);
        merge(N,l,m,r);
    }
}

int main(){
    int N[10] = {12,11,13,5,6,7,1,5,3,2};
    printArray(N, 10);
    mergesort(N,0,9);
    printArray(N, 10);
    return 0;
}