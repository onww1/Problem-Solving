#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#define INF 1023456789LL
#define MOD 1000000007LL
using namespace std;

typedef long long ll;
typedef double db;

int in[5050], cnt[5050];
set <int> s[5050];
int main(int argc, char *argv[]) {
  int n, k, i, j, mx = 0, color = 1;
  scanf("%d %d", &n, &k);
  for (i = 0; i < n; ++i) {
    scanf("%d", &in[i]);
    ++cnt[in[i]];
    mx = max(mx, cnt[in[i]]);
  }

  if (mx > k) return !printf("NO\n");
  printf("YES\n");
  for (i = 0; i < n; ++i) {
    while (s[in[i]].count(color) > 0) color = color % k + 1;
    s[in[i]].insert(color);
    in[i] = color;
    color = color % k + 1;
  }
  for (i = 0; i < n; ++i) printf("%d ", in[i]);
  return !printf("\n");
}
