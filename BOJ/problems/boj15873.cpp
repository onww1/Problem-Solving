#include <cstdio>
char in[5];
int a[2];
int main() {
	scanf("%s", in);
	for (int i = 0, idx = 0; in[i]; ++i) {
		if (in[i] > '0' && a[idx]) idx++;
		a[idx] = a[idx] * 10 + in[i] - '0';
	}
	return !printf("%d\n", a[0] + a[1]);
}