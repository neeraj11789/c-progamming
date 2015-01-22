#include <stdio.h>
#include <string.h>

char tracks[][80] = {
		"I left my heart in Harvard Med School",
		"Newark, Newark - a wonderful town",
		"Dancing with a Dork",
		"From here to maternity",
		"The girl from Iwo Jima",
};

void find_track(char search_for[]){
	int i;
	char *pos;
	for (i = 0; i < 5; i++){
		printf("Searching in track : %s\n", tracks[i]);
		pos = strstr(tracks[i], search_for);
		printf("Position: %p\n", pos);
		if(pos){
			printf("Track %i: '%s'\n", i, tracks[i]);
		}
	}
}
	
int main(){
	char search_for[80];
	printf("Search for string:\n");		
	fgets(search_for, 80, stdin);
	find_track(search_for);
	return 0;
}