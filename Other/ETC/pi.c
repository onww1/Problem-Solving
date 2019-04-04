#include <stdio.h>
#include <string.h>

void preprocessing(char* pattern, int* pi){
	int j=0, k=-1;
	pi[0] = -1;
	while(j<7){
		if(k==-1 || pattern[j] == pattern[k]){
			printf("%d\t%d\n", j, k);
			j++;
			k++;
			pi[j] = k;
		} else {
			k = pi[k];
		}
	}
	return;
}

int main(void){
	char pattern[8];
	int pi[8];
	scanf("%s", pattern);
	printf("%s\n", pattern);
	preprocessing(pattern, pi);
	for(int i=0; i<8; i++){
		printf("%d\t", pi[i]);
	}
	printf("\n");
	return 0;
}