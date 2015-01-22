#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int T, count;
	unsigned int N[100];
    scanf("%d", &T);
    for(count=0; count<T; count++){
    	scanf("%u", N+count);
    }
    for(count=0; count<T;count++){
    	printf("%u\n", ~N[count]);
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}