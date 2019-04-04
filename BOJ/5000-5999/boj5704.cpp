#include <cstdio>
char in[210];
int main() {
	while (1) {
		fgets(in, sizeof(in), stdin);
		if (in[0] == '*') break;
		int cnt[26]{};
		for (int i = 0; in[i]; ++i) {
			if (in[i] == ' ' || in[i] == '\n') continue;
			cnt[in[i] - 'a']++;
		}
		bool flag = true;
		for (int i = 0; i < 26; ++i) if (!cnt[i]) flag = false;
		puts(flag ? "Y" : "N");
	}
	return 0;
}