#include <stdio.h>

void main(){
	int row, height;
	int trip;
	printf("Please Enter the Height for the Triange\n");
	scanf("%d", &height);
	for(row=height; row>0; row--){
		for (trip = 0; trip < row-1; trip++){
			printf(" ");
		}
		for (trip = 0; trip < (height-row+1); trip++){
			printf("*");
		}
		printf("\n");
	}
}