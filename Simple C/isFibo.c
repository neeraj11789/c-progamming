/*
Input : Number 
Output : Check if it is part of Fibonacci Series or Not
*/

#include <stdio.h>

void main(){
	long T, counter; // number for testcases
	long long N, sum=0; // Number to test for
	int ele1;
	int ele2;
	int flag;
	scanf("%ld", &T);
	for(counter = 0; counter<T; counter++){
		scanf("%lld", &N);
		ele1=0;
		ele2=1;
		sum=0;
		flag=0;
		while(sum<=N){
			if(sum==N){
				flag=1;
			}
			sum = ele1 + ele2;
			ele1 = ele2;
			ele2 = sum;
		}
		if(flag==1){
			printf("%s", "IsFibo\n");
		}else{
			printf("%s", "IsNotFibo\n");
		}
	}
}