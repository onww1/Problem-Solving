#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 1e5;

int a[MAX + 1], n, s;
int main(int argc, char *argv[]) {
	int i;
	scanf("%d %d", &n, &s);
	for (i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		a[i] += a[i - 1];
	}

	int left = 0, right = 1, mn = 1e9, sum;
	while (left <= right && right <= n) {
		sum = a[right] - a[left];
		if (sum >= s) {
			mn = min(mn, right - left);
			++left;
		}
		else ++right;
	}
	return !printf("%d\n", mn == 1e9 ? 0 : mn);
}