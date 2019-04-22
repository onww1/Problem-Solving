#include <stdio.h>
int N;
char in[105], ans[105];
int main() {
	scanf("%d", &N); getchar();
	for (int i = 0; i < N; ++i) {
		fgets(in, sizeof(in), stdin);
		bool flag = true;
		sprintf(ans, "god");
		for (int j = 0, l = 3; in[j]; ++j) {
			if (in[j] == ' ' || in[j] == '\n') flag = false;
			else if (!flag) ans[l++] = in[j], ans[l] = 0;
		}
		printf("%s\n", ans);
	}
	return 0;
}