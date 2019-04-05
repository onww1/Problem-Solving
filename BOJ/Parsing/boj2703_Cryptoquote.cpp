#include <cstdio>
int T;
char in[1002], c[27];

int main() {
	scanf("%d", &T);
	getchar();
	while (T--) {
		fgets(in, sizeof(in), stdin);
		scanf(" %s", c); getchar();
		for (int i = 0; in[i]; ++i) {
			if (in[i] == '\n') {
				in[i] = 0;
				break;
			}
			if (in[i] == ' ') continue;
			in[i] = c[in[i] - 'A'];
		}
		printf("%s\n", in);
	}
	return 0;
}