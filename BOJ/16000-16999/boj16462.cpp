#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#define MOD 1000000007LL
#define INF 1023456789LL
using namespace std;

typedef long long ll;
typedef double db;

int main(int argc, char *argv[]) {
    char q[4];
		int n, s = 0, d, i, j;

		scanf("%d", &n);
		for (i = 0; i < n; ++i) {
			scanf("%s", q);
			d = 0;
			for (j = 0; q[j]; ++j) {
				d *= 10;
				if (q[j] == '0' || q[j] == '6') d += 9;
				else d += (q[j] - '0');
			}
			if (d > 100) d = 100;
			s += d;
		} 

		if (2 * (s % n) >= n) return !printf("%d\n", s/n + 1);
		else return !printf("%d\n", s/n);
}
