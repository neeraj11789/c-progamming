#include <stdio.h>

void main(){
	int start1=0;
	int start2=1;
	int maximum, counter, sum;

	printf("\nPlease enter the maximum number of Fibonacci Elements in Series");
	scanf("%d", &maximum);

	printf("\n0,1");
	for(counter=0; counter<maximum-2; counter++){
		sum = start1 + start2;
		printf(",%d", sum);
		start1 = start2;
		start2 = sum;
	}
	printf("\n");
}