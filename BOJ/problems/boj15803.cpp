#include <cstdio>
#include <algorithm>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;

int CCW(pii &a, pii &b, pii &c) {
	int ret = 0;
	ret += a.X * (b.Y - c.Y);
	ret += b.X * (c.Y - a.Y);
	ret += c.X * (a.Y - b.Y);
	return ret > 0 ? 1 : ret < 0 ? -1 : 0;
}

int main() {
	pii a, b, c;
	scanf("%d %d", &a.X, &a.Y);
	scanf("%d %d", &b.X, &b.Y);
	scanf("%d %d", &c.X, &c.Y);
	if (CCW(a, b, c)) puts("WINNER WINNER CHICKEN DINNER!");
	else puts("WHERE IS MY CHICKEN?");
	return 0;
}