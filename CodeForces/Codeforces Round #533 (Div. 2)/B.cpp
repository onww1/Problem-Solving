#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#define INF 1023456789
#define MOD 1000000007
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

char in[200050];
int cnt[26];
int main(int argc, char *argv[]) {
  int n, k, i, j, s = 0, mx = 0;
  scanf("%d %d", &n, &k);
  scanf(" %s", in);
  char cur = 0;
  for (i = 0; i < n; ++i) {
    if (in[i] == cur) ++s;
    else cur = in[i], s = 1;

    if (s == k) ++cnt[in[i] - 'a'], s = 0;
  }
  for (i = 0; i < 26; ++i) mx = max(mx, cnt[i]);
  return !printf("%d\n", mx);
}