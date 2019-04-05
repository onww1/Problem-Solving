#include <cstdio>
#include <cstring>
const int MAX = 1e6;

int pa[MAX + 1], n, m;

int _find(int a) {
	if (pa[a] < 0) return a;
	return pa[a] = _find(pa[a]);
}

void _union(int a, int b) {
	int pa_a = _find(a);
	int pa_b = _find(b);
	if (pa_a != pa_b) pa[pa_a] = pa_b;
}

int main(int argc, char *argv[]) {
	int a, b, c;
	scanf("%d %d", &n, &m);
	memset(pa, -1, sizeof(pa));
	while (m--) {
		scanf("%d %d %d", &c, &a, &b);
		if (c) printf("%s\n", _find(a) == _find(b) ? "YES" : "NO");
		else _union(a, b);
	}
	return 0;
}