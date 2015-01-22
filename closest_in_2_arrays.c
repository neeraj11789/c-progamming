#include <stdio.h>
#include <math.h>

int getMin(int a, int b){
	return a<b?a:b;
}

int findClosestElements(int a[], int b[]){
	int counter, min;
	int i=0;
	int j=0;
	min = (a[0]-b[0]);

	for(counter=0; counter<6; counter++){
		if((a[i]-b[j+1]) < (b[i]-a[j+1])){
			min = getMin(min, (a[i]-b[j+1]));
			j++;
		}else{
			min = getMin(min, (b[i]-a[j+1]));
			i++;
		}
	}
	return min;
}

int main(){
	int a[6] = {1,2,3,5,8,9};
	int b[6] = {3,7,9,12,14};

	int findClosestElements(a, b);
	return 0;
}