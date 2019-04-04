#include <cstdio>
#include <cstring>

char cmd[6];
int queue[10000], h = 0, t = 0, a, n;
int main(int argc, char *argv[]) {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf(" %s", cmd);
		if (!strcmp(cmd, "push")) {
			scanf("%d", &a);
			queue[t++] = a;
		}
		else if (!strcmp(cmd, "pop")) {
			if (h == t) printf("-1\n");
			else printf("%d\n", queue[h++]);
		}
		else if (!strcmp(cmd, "size")) {
			printf("%d\n", t - h);
		}
		else if (!strcmp(cmd, "empty")) {
			printf("%d\n", t == h ? 1 : 0);
		}
		else if (!strcmp(cmd, "front")) {
			printf("%d\n", t == h ? -1 : queue[h]);
		}
		else if (!strcmp(cmd, "back")) {
			printf("%d\n", t == h ? -1 : queue[t - 1]);
		}
	}
	return 0;
}