#include <stdio.h>
long long S, N;
char in[10005];
int main() {
	while (~scanf(" %s", in)) {
		for (int i = 0; in[i]; ++i) {
			if (in[i] == ',') {
				S += N;
				N = 0;
			} else {
				N = N * 10 + in[i] - '0';
			}
		}
	}
	S += N;
	printf("%lld\n", S);
	return 0;
}