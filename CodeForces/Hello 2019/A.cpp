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

ll get_pow(ll base, ll exp);

char in[6][3];
int main(int argc, char *argv[]) {
  int n, i, j;
  for (i = 0; i < 6; ++i) scanf("%s", in[i]);
  for (i = 1; i < 6; ++i) {
    for (j = 0; j < 2; ++j) {
      if (in[0][j] == in[i][j]) return !printf("YES\n");
    }
  }
  return !printf("NO\n");
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
