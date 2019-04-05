#include <cstdio>
const int MAX = 1e4;

int a[MAX + 1];
int main(int argc, char *argv[]) {
	int n, m, i;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		a[i] += a[i - 1];
	}

	int left = 0, right = 1, cnt = 0, sum;
	while (left <= right && right <= n) {
		if (left == right) ++right;

		sum = a[right] - a[left];
		if (sum == m) {
			++cnt;
			++left;
			++right;
		}
		else if (sum < m) ++right;
		else ++left;
	}

	return !printf("%d\n", cnt);
}