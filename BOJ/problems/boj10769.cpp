#include <cstdio>
#include <cstring>
char in[300];
int S, H, L;
int main() {
	fgets(in, sizeof(in), stdin);
	L = strlen(in);
	for (int i = 0; i < L; ++i) {
		if (i + 2 < L && in[i] == ':' && in[i + 1] == '-') {
			if (in[i + 2] == ')') H++, i += 2;
			else if (in[i + 2] == '(') S++, i += 2;
			else i += 1;
		}
	}
	if (!S && !H) puts("none");
	else if (S == H) puts("unsure");
	else if (S > H) puts("sad");
	else if (S < H) puts("happy");
	return 0;
}