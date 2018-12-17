#include <cstdio>
using namespace std;

void go(int n) {
	int i = 0 ;
	for(; i < n; i++) {
		for(int j=0; j<i; j++) printf(" ");
		for(int j=0; j<(2*(n-i)-1); j++) printf("*");
		printf("\n");
	}
	for(i = n-2; i >= 0; i--) {
		for(int j=0; j<i; j++) printf(" ");
		for(int j=0; j<(2*(n-i)-1); j++) printf("*");
		printf("\n");
	}
}

int main() {
	int N; 
	scanf("%d", &N);
	go(N);
	return 0;
}