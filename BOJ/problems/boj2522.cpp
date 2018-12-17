#include <cstdio>
using namespace std;

void go(int n) {
	int i = n-1;
	for(; i>=0; i--) {
		for(int j=0; j<i; j++) printf(" ");
		for(int j=0; j<n-i; j++) printf("*");
		printf("\n");
	}
	for(i=1; i<n; i++) {
		for(int j=0; j<i; j++) printf(" ");
		for(int j=0; j<n-i; j++) printf("*");
		printf("\n");
	}
}

int main() {
	int N;
	scanf("%d", &N);
	go(N);
	return 0;
}