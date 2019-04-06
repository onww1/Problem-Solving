#include <stdio.h>

int calRoot_int(int n){
	int root = 0;
	while(n>0){
		root += n%10;
		n/=10;
	}
	return root;
}

int calRoot_char(char* arr){
	int root = 0;
	for(int i=0; arr[i] != '\0'; i++){
		root += arr[i] - '0';
	}
	return root;
}

int main(void){
	char input[1001];
	int root;
	while(1){
		scanf("%s", input);
		if(input[0] == '0') break;
		root = calRoot_char(input);
		while(root >= 10){
			root = calRoot_int(root);
		}
		printf("%d\n", root);
	}
	return 0;
}