#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#define MOD 1000000007
#define INF 1023456789
using namespace std;

typedef long long ll;
typedef double db;

ll get_pow(ll base, ll exp);
ll get_min(ll a, ll b);
ll get_max(ll a, ll b);
ll get_abs(ll a);

int parseDirection(char c);

int main(int argc, char *argv[]) {
	int *map;
	int n, i, s, dd;
	int row = 1000, col = 1000, min = INF, t = 0;
	int move_r[] = {0, 0, 1, -1};
	int move_c[] = {1, -1, 0, 0};
	char d;

	map = (int *)calloc(2001 * 2001, sizeof(int));
	scanf("%d", &n);
	while (n--) {
		scanf(" %c %d", &d, &s);
		dd = parseDirection(d);
		for (i = 0; i < s; ++i) {
			row += move_r[dd];
			col += move_c[dd];
			++t;

			if (*(map + row * 2001 + col)) 
				min = get_min(min, t - *(map + row * 2001 + col));
			*(map + row * 2001 + col) = t;
		}
	}

	free(map);
	if (min == INF) printf("-1\n");
	else printf("%d\n", min);
  return 0;
}

int parseDirection(char c) {
	if (c == 'E') return 0;
	else if (c == 'W') return 1;
	else if (c == 'S') return 2;
	else if (c == 'N') return 3;
	return -1;
}

ll get_pow(ll base, ll exp) {
  if (exp == 0ll) return 1ll;
  if (exp == 1ll) return base;

  ll half = get_pow(base, exp/2ll);
  ll res = half * half % MOD;
  if (exp % 2ll) res = res * base % MOD;
  return res;
}

ll get_min(ll a, ll b) { return a < b ? a : b; }
ll get_max(ll a, ll b) { return a > b ? a : b; }
ll get_abs(ll a) { return a < 0 ? -a : a; }
