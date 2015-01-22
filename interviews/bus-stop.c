#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int N;
	scanf("%d", &N);
	char A[2*N];
	int G[N], i=0;
	
	gets(A);

	for (i=0; i<N; i++){
		int *tmp = atoi(A[i]);
		sscanf(A, "%d", tmp);
		i = i +2;
	}
	//printf("%s\n", A);
	// for(i=0; i<N; i++){

	// }

	return 0;
}