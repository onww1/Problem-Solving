#include <stdio.h>

void print(int l){
	if(l == 0) printf("  *  ");
	else if(l == 1) printf(" * * ");
	else if(l == 2) printf("*****");
}

void star(int n, int l){
	if(n == 3){print(l);}
	else{
		if(l<n/2){
			for(int i=0; i<n/2; i++) printf(" ");
			star(n/2, l);
			for(int i=0; i<n/2; i++) printf(" ");
		}
		else{
			star(n/2, l-n/2);
			printf(" ");
			star(n/2, l-n/2);
		}
	}
}

int main(void){
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++) {star(n, i); printf("\n");}
	return 0;
}