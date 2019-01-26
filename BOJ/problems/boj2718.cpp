#include <cstdio>
using namespace std;
typedef long long ll;

int DP[25];
int main(int argc, char *argv[]) {
  int t, n, i;
  ll s = 0LL, se = 0LL, so = 0LL;
  DP[0] = DP[1] = 1;
  for (i = 2; i < 25; ++i) {
    DP[i] = DP[i - 1] + 4 * DP[i - 2] + 2 * s;
    if (i > 3) DP[i] += (i % 2 ? so : se);
    s += DP[i - 2];
    se += (i % 2 == 1 ? 0 : DP[i - 2]);
    so += (i % 2 == 1 ? DP[i - 2] : 0);
  }
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    printf("%d\n", DP[n]);
  }
  return 0;
}
