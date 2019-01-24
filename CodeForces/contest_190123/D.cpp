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

char in[200050], str[4] = "RGB"; 
int dp[200050][3], m[256];
int main(int argc, char *argv[]) {
  int n, i, j, cnt = 0;
  scanf("%d %s", &n, in);
  m['R'] = 0, m['G'] = 1, m['B'] = 2;
  for (i = 1; i < n; ++i) {
    if (in[i] == in[i-1]) {
      if (i == n - 1) {
        in[i] = str[(m[in[i]] + 1) % 3];
      } else if (str[(m[in[i]] + 1) % 3] == in[i + 1]) {
        in[i] = str[(m[in[i]] + 2) % 3];
      } else {
        in[i] = str[(m[in[i]] + 1) % 3];
      }
      ++cnt;
    }
  }
  return !printf("%d\n%s\n", cnt, in);
}