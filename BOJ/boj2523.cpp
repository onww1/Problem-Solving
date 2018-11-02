#include <cstdio>
using namespace std;

void go(int n) {
	for(int i=0; i<n; i++) {
		for(int j=0; j<=i; j++) printf("*");
		printf("\n");
	}
	for(int i=n-2; i>=0; i--) {
		for(int j=0; j<=i; j++) printf("*");
		printf("\n");
	}
}

int main() {
	int N;
	scanf("%d", &N);
	go(N);
	return 0;
}