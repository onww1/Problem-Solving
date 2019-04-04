#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#define INF 1023456789
#define MOD 1000000007
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

char in[500][501];
int main(int argc, char *argv[]) {
  int n, i, j, cnt = 0;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) scanf(" %s", in[i]);
  for (i = 1; i < n - 1; ++i) {
    for (j = 1; j < n - 1; ++j) {
      if (in[i][j] == 'X' && in[i-1][j-1] == 'X' &&
          in[i-1][j+1] == 'X' && in[i+1][j-1] == 'X' &&
          in[i+1][j+1] == 'X') ++cnt;
    }
  }
  return !printf("%d\n", cnt);
}