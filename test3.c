#include <stdio.h>
#include <string.h>

int main(void){
	char table[20000][51];
	int cnt=0, n;
	char input[51];
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%s", input);
		int inputlen = strlen(input);
		for(int j=0; j<cnt; j++){
			int destlen = strlen(table[j]);
			if(inputlen < destlen){
				for(int k=cnt; k>j; k--)
					strcpy(table[k], table[k-1]);
				strcpy(table[j], input);
				cnt++; break;
			} else if(inputlen == destlen && strcmp(input, table[j])<0){
				for(int k=cnt; k>j; k--)
					strcpy(table[k], table[k-1]);
				strcpy(table[j], input);
				cnt++; break;
			} else{
				strcpy(table[cnt], input);
				cnt++; break;
			}
		}
	}
	for(int i=0; i<n; i++){
		printf("%s\n", table[i]);
	}
	return 0;
}