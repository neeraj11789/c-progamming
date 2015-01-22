#include <stdio.h>
#include <limits.h>

/*
    buy[]   100     
    sell[]      360         
    local_max; 0    100     180     360                     
    local_min; INT_MAX  100      40     


*/
 // {100, 180, 360, 310, 40, 535, 695}

void stockBuySell(int N[], int size){
    int i=0;    // counter
    int local_max = 0;
    int local_min = N[0];
    int buy_sell[size];
    buy_sell[0] = N[0]; // Buy stock on day 0
    int s=1;
    for(i=0; i<size; i++){
        if(N[i] > local_max){
            local_max = N[i];
        }

        if(N[i] < local_min){
            // Sell the stock at previous max_price
            buy_sell[s++] = local_max;
            local_max = 0;
            local_min = N[i];
            // Buy the stock
            buy_sell[s++] = local_min;
        }
    }
    buy_sell[s++] = local_max;
    for(i=0; i<size; i++){
        printf("%d ", buy_sell[i]);
    }
}



int main(){
    int N[20] = {100, 180, 360, 310, 40, 535, 695};
    int R;

    stockBuySell(N, 7);
    
    return 1;
}