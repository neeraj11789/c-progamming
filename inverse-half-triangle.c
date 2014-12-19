#include <stdio.h>

void main(){
	int row, height;
	int trip;
	printf("Please Enter the Height for the Triange\n");
	scanf("%d", &height);
	for(row=height; row>0; row--){
		for (trip = 0; trip < row; trip++){
			printf("*");
		}
		printf("\n");
	}
}