#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#define INF 1023456789LL
#define MOD 1000000007LL
using namespace std;

typedef long long ll;
typedef double db;

ll get_pow(ll base, ll exp);

int in[16][10000], dp[16][16][1 << 16], diff[16][16];
int main(int argc, char *argv[]) {
  int n, m, i, j, k;
  scanf("%d %d", &n, &m);
  memset(dp, -1, sizeof(dp));
  memset(diff, 0x7f, sizeof(diff));
  for (i = 0; i < n; ++i) for (j = 0; j < m; ++j) {
    scanf("%d", &in[i][j]);
    for (k = 0; k < i; ++k) {
      diff[i][k] = diff[k][i] = min(diff[i][k], abs(in[i][j] - in[k][j]));
    }
  }

}

ll get_pow(ll base, ll exp) {
    ll ret = 1LL;
    while (exp > 0) {
        if (exp % 2) {
            ret *= base;
            ret %= MOD;
        }
        base *= base;
        base %= MOD;
        exp /= 2;
    }
    return ret;
}