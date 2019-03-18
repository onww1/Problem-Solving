#include <cstdio>
int main() {
	char in[5], p = '0';
	scanf(" %s", in);

	int ans = 1;
	for (int i = 0; in[i]; ++i) {
		if (in[i] == 'c') {
			ans *= 26 - (in[i] == p);
			p = in[i];
		} else if (in[i] == 'd') {
			ans *= 10 - (in[i] == p);
			p = in[i];
		}
	}
	return !printf("%d\n", ans);
}