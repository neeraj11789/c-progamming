#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *arr, int count){
  int i=0;
  int j=0;
  int temp;
  for(i=0; i<count; i++){
    j=i;
    while(j>0 && *(arr+j)<*(arr+j-1)){
        temp = *(arr+j);
        *(arr+j) = *(arr+j-1);
        *(arr+j-1) = temp;
        j--;
    }
  }
}


void binaryInsertionSort(int *arr, int count){
  int i=0;
  int j=0;
  int temp;
  int ele;
  int pos;
  for(i=1; i<count; i++){
    j=i;
    ele = *(arr+j);
    pos = InsertionbinarySearch(arr,0,j,ele);

    while(j>=pos){
      *(arr+j+1) = *(arr+j);
      j--;
    }
    arr[pos] = ele;
  }
}

int InsertionbinarySearch(int *arr, int st, int end, int key){
  int mid = st + (end-st+1)/2;
  if(end<st){
    return (key>*(arr+st)?st+1:st);
  }
  if(*(arr+mid)==key){
    return mid;
  }
  if(key > *(arr+mid)){
    return binarySearch(arr, mid+1, end, key);
  }
  if(key < *(arr+mid)){
    return binarySearch(arr, st, mid-1, key);
  }
}


int binarySearch(int *arr, int st, int end, int key){
  int mid = st + (end-st+1)/2;
  if(end<st){
    return -1;
  }
  if(*(arr+mid)==key){
    return mid;
  }
  if(key > *(arr+mid)){
    return binarySearch(arr, mid+1, end, key);
  }
  if(key < *(arr+mid)){
    return binarySearch(arr, st, mid-1, key);
  }
} 
 
int main()
{
  int count=6, i=0;

  printf("Enter the number of Elements\n");
  scanf("%d", &count);

  int *arr = (int*)malloc(count*sizeof(int));

  for(i=0; i<count; i++){
    scanf("%d", arr+i);
  }

  printf("Input Array: \n");
  for(i=0; i<count; i++){
    printf("%d\n", *(arr+i));
  }

  binaryInsertionSort(arr, count);


  printf("Output Array\n");
  for(i=0; i<count; i++){
    printf("%d\n", *(arr+i));
  }

  return 0;
}