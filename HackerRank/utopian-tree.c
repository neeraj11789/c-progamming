#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int utopianTreeHeight(int cycles){
	int height=1;
	int i;
	for(i=1; i<=cycles; i++){
		if(i%2==0){
			height = height+1;
		}else{
			height = height*2;
		}
	}
	return height;
}

int main() {
	int T, count; // Test-cases
	int N[60]; // Array containing number of cycles for test cases
	// GET the test cases
	scanf("%d", &T);
	if(T<1 || T>10){
		printf("Wrong Input");
	}
	// Get the cycles for the test cases
	for(count=0; count<T; count++){
		scanf("%d", N+count);
		if(N[count]<0 || N[count]>60){
			printf("Wrong Input");
		}
	}
	for(count=0; count<T; count++){
		printf("%d\n", utopianTreeHeight(N[count]));
	}
    return 0;
}
