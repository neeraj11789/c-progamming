#include <stdio.h>

int computeSum(int n){
    return ((n * (n+1))/2);
}

int main(){
    int N[10];
    int counter;
    int sum, n_sum, missing_index=-1;
    for(counter=0; counter<10; counter++){
        scanf("%d", &N[counter]);
    }
    
    sum = computeSum(10);
    n_sum = 0;
    for(counter=0; counter<10; counter++){
        n_sum += N[counter];
        if(N[counter]<=0){
            missing_index = counter;
        }
    }
    
    if(sum==n_sum){
        printf("No Missing Element");
    }else{
        printf("Missing Element is %d and missing index is: %d", sum-n_sum, missing_index);
    }
    
    return 1;
}