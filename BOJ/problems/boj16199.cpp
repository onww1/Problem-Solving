#include <cstdio>
int sy, sm, sd, ey, em, ed;
int main() {
	scanf("%d %d %d %d %d %d", &sy, &sm, &sd, &ey, &em, &ed);
	sd = sm * 100 + sd;
	ed = em * 100 + ed;
	printf("%d\n", ey - sy - 1 + (ed - sd >= 0 ? 1 : 0));
	printf("%d\n", ey - sy + 1);
	printf("%d\n", ey - sy);
	return 0;
}