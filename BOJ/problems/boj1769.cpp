#include <cstdio>
#include <cstring>
char in[1000001];
int N, sum, cnt;
int main() {
	scanf("%s", in);
	if (strlen(in) == 1) {
		puts("0");
		puts((in[0] - '0') % 3 == 0 ? "YES" : "NO");
		return 0;
	}

	cnt = 1;
	for (int i = 0; in[i]; ++i) N += (in[i] - '0');
	while (N >= 10) {
		++cnt;
		sum = 0;
		while (N) {
			sum += N % 10;
			N /= 10;
		}
		N = sum;
	}
	printf("%d\n", cnt);
	puts(N % 3 == 0 ? "YES" : "NO");
	return 0;
}