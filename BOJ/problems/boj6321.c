#include <stdio.h>
#include <string.h>

void transform(char* computer){
	int length = strlen(computer);
	for(int i=0; i<length; i++){
		if(computer[i] < 'Z') computer[i]++;
		else computer[i] = 'A';
	}
	return;
}

int main(void){
	int n;
	scanf("%d", &n);

	char computer[51];
	for(int i=1; i<=n; i++){
		scanf("%s", computer);
		transform(computer);
		printf("String #%d\n", i);
		printf("%s\n", computer);
		if(i<n) printf("\n");
	}
	return 0;
}