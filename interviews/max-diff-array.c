# include <stdio.h>
# include <stdlib.h>

#define SIZE 10

// Maximum difference between two elements such that larger element appears after the smaller number
// [2, 3, 10, 6, 4, 8, 1]
int maxDifference(int N[], int size){
    int max_diff=0;
    int i; // counter
    int local_min, local_max, global_min;
    local_min = local_max = global_min = 0;
    for(i=1; i<size; i++){
        if(N[i]<N[local_min]){
            local_min = i;
        }
        if(N[i]>N[local_max]){
            local_max = i;
        }
        if(N[global_min] > N[local_min] && local_max>local_min){
            global_min = local_min;
        }
    }
    // printf("Local Max : %d\n", local_max);
    // printf("Local Min : %d\n", local_min);
    // printf("Global Min : %d\n", global_min);

    return N[local_max]-N[global_min];
}

int main(){
    int N[SIZE] = {2, 3, 10, 6, 4, 8, 1};
    int R;
    
    R = maxDifference(N, SIZE);
    printf("R: %d\n", R);
    return 1;
}