#include <cstdio>
char in[51];
int cnt[26], L, odd = -1;
int main() {
	scanf(" %s", in);
	for (L = 0; in[L]; ++L) cnt[in[L] - 'A']++;
	for (int i = 0; i < 26; ++i) {
		if (cnt[i] % 2) {
			if (odd == -1) odd = i;
			else return !printf("I'm Sorry Hansoo\n");
		}
	}

	if (L % 2 == 0 && odd != -1) return !printf("I'm Sorry Hansoo\n");
	for (int i = 0, idx = 0; i < 26;) {
		if (cnt[i] <= 1) {
			++i;
			continue;
		}
		in[idx] = in[L - idx - 1] = i + 'A';
		cnt[i] -= 2;
		idx++;
	}
	if (odd != -1) in[L / 2] = 'A' + odd;
	return !printf("%s\n", in);
}