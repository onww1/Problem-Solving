#include <cstdio>
#include <algorithm>
using namespace std;
int x[4], y[4];
int main() {
	for (int i = 0; i < 4; ++i) scanf("%d %d", x + i, y + i);
	sort(x, x + 4); sort(y, y + 4);
	int dd = max(x[3] - x[0], y[3] - y[0]);
	return !printf("%d\n", dd * dd);
}