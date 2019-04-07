#include <cstdio>
char S[101], K[101];
int main() {
	scanf(" %s %s", S, K);
	bool found = false;
	for (int i = 0, j, k; !found && S[i]; ++i) {
		for (j = 0, k = 0; S[i + k] && K[j]; ++k) {
			if ('0' <= S[i + k] && S[i + k] <= '9') continue;
			if (S[i + k] != K[j]) break;
			else ++j;
		}
		if (!K[j]) found = true;
	}
	printf("%d\n", found ? 1 : 0);
}