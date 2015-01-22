#include <stdio.h>
void main(){
	char output[10000][100];
	output[0] = 'This works fine';
	output[1] = 'This is great';
	output[5900] = 'This is stunning';

	printf("%s\n", output[0]);
	printf("%s\n", output[1]);
	printf("%s\n", output[5900]);
}