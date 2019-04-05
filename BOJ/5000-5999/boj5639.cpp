#include <cstdio>
const int MAX = 1e4;

int a[MAX + 1], n = 0;

void postorder(int s, int e) {
	if (s >= e) {
		if (s == e) printf("%d\n", a[s]);
		return;
	}
	
	int val = a[s];
	int l = s + 1, r = e, m, p = e + 1;
	while (l <= r) {
		m = (l + r) / 2;
		if (a[m] > val) {
			p = m;
			r = m - 1;
		}
		else l = m + 1;
	}
	postorder(s + 1, p - 1);
	postorder(p, e);
	printf("%d\n", val);
}

int main(int argc, char *argv[]) {
	while (~scanf("%d", a + n++));
	postorder(0, n - 2);
	return 0;
}