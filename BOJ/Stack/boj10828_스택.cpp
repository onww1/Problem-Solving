#include <cstdio>
#include <cstring>

char cmd[6];
int stack[10000], p = 0, a, n;
int main(int argc, char *argv[]) {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf(" %s", cmd);
		if (!strcmp(cmd, "push")) {
			scanf("%d", &a);
			stack[p++] = a;
		}
		else if (!strcmp(cmd, "pop")) {
			if (p) printf("%d\n", stack[--p]);
			else printf("-1\n");
		}
		else if (!strcmp(cmd, "size")) {
			printf("%d\n", p);
		}
		else if (!strcmp(cmd, "empty")) {
			printf("%d\n", p == 0 ? 1 : 0);
		}
		else if (!strcmp(cmd, "top")) {
			if (p) printf("%d\n", stack[p - 1]);
			else printf("-1\n");
		}
	}
	return 0;
}