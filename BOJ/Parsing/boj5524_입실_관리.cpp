#include <stdio.h>

int N;
char S[25];
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf(" %s", S);
		for (int j = 0; S[j]; ++j)
			if ('A' <= S[j] && S[j] <= 'Z') 
				S[j] += 'a' - 'A';
		printf("%s\n", S);
	}
	return 0;
}