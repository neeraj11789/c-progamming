/**
Program to print this : 
     1
    121
   12321
  1234321
 123454321
12345654321
**/

#include <stdio.h>

void main(){
	int height;
	int row;
	int seq;
	int space;

	printf("\nPlease Enter the height for the Sequence");
	scanf("%d", &height);
	for(row=1; row<=height; row++){
		for(space=0; space<height-row; space++){
			printf(" ");	
		}
		for(seq=1; seq<=row; seq++){
			printf("%d", seq);
		}
		for(seq=row-1;seq>=1;seq--){
			printf("%d", seq);
		}
		printf("\n");
	}
}