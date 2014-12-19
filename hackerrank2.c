#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int T, i;
	long long N, orignal_number;
	int last_digit;
	int result;
	printf("Enter Number of Test Cases - T : 1 <=T <= 15\n");
	scanf("%d", &T);
	for(i=0; i<T; i++){
		result=0; 
		printf("\nEnter the Number N where 0 < N < 10^10 :");
		scanf("%lld", &N);
		orignal_number = N;
		while(N > 0){
			last_digit = N%10;
			if(last_digit==0){
				N = N/10;
				continue;
			}
			if(orignal_number%last_digit == 0){
				result++;
			}
			N = N/10;
		}	
		printf("Result: %d\t", result);
	}
	
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
