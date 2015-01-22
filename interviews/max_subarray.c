#include <stdio.h>
#include <stdlib.h>

/**

 the maximum subarray problem is the task of finding the contiguous subarray within a one-dimensional array of numbers 
 (containing at least one positive number) which has the largest sum. 
 For example, for the sequence of values −2, 1, −3, 4, −1, 2, 1, −5, 4; 
 the contiguous subarray with the largest sum is 4, −1, 2, 1, with sum 6.

*/
int *getMaxSubArray(int N[]){
    int *R = (int*)malloc(sizeof(int)*3);
    int i; // counter
    int max_ending_here;
    int max_so_far;
    int st, end;
    st=0;
    max_so_far=max_ending_here=0;
    for(i=0; i<10; i++){
        max_ending_here += N[i];
        if(max_ending_here < 0){
            max_ending_here=0;
            st = i+1;
        }
        if(max_ending_here > max_so_far){
            max_so_far = max_ending_here;
            end = i;
        }
    }
    *R = st;
    *(R+1) = end;
    *(R+2) = max_so_far;
    return R;
    // printf("Indexes : %d %d \n", st, end);
    //return max_so_far;
}

int main(){
    //int; N[10];
    int i=0; // counter
    int *R; // to store indexes of sub-arrays
    // printf("Enter the 10 elements in array\n");
    // for(i=0; i<10; i++){
    //     scanf("%d", &N[i]);
    // }
    int N[10] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    R = getMaxSubArray(N);
    printf("Max SubArray is %d from %d to %d\n", *(R+2), N[*R], N[*(R+1)]);
    return 1;
}