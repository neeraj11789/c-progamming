/**
Program to print this : 
     *
    ***
   *****
  *******
 *********
***********
**/
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
		/** Code Split for Equal Half Triangles
		for (trip = 0; trip < (height-row+1); trip++){
			printf("*");
		}
		for (trip = 0; trip < (height-row); trip++){
			printf("*");
		}**/
		for (trip = 0; trip < (2*(height-row)+1); trip++){
			printf("*");
		}
		printf("\n");
	}
}