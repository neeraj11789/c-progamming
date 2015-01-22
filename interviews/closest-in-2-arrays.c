#include <stdio.h>
#include <math.h>
#include <limits.h>

/**
1 2 3 5 8 9

3 7 9 12 14

2
1
0
2

i 	0	1 	
j	0	0	
Min 2	1 	 	

*/

int getMin(int a, int b){
	return a<b?a:b;
}

int findClosestElements(int a[], int b[]){
	int counter, min, diff;
	int ai=0;
	int bi=0;
	min = INT_MAX;
	for(counter=0; counter<6; counter++){
		diff = abs(a[ai]-b[bi]);
		if(diff < min){
			min = diff;
		}
		if(a[ai]<=b[bi]){
			ai++;
		}else{
			bi++;
		}
	}
	return min;
}

int main(){
	int a[6] = {1,5,10,15,20};
	int b[6] = {3,7,9,12,17};
	int result;
	result = findClosestElements(a, b);
	printf("%d\n", result);
	return 0;
}