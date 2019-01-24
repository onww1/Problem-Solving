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

char str[4] = "RGB";
char in[200050];
vector <int> ans, cur;
int mn = 1e9, cnt[3][3];

void solve(int visited) {
  if (visited == ((1 << 3) - 1)) {
    if (mn > cnt[0][cur[0]] + cnt[1][cur[1]] + cnt[2][cur[2]]) {
      mn = cnt[0][cur[0]] + cnt[1][cur[1]] + cnt[2][cur[2]];
      ans = vector <int> (cur.begin(), cur.end());
    }
  }

  for (int i = 0; i < 3; ++i) {
    if (!visited) {
      cur.push_back(i);
      solve(visited | (1 << i));
      cur.pop_back();
    }
    else if (!(visited & (1 << i))) {
      cur.push_back(i);
      solve(visited | (1 << i));
      cur.pop_back();
    }
  }
}

int main(int argc, char *argv[]) {
  int n, i, j;
  scanf("%d %s", &n, in);
  for (i = 0; i < n; ++i) {
    for (j = 0; j < 3; ++j) {
      cnt[i % 3][j] += (in[i] != str[j] ? 1 : 0);
    }
  }
  solve(0);
  printf("%d\n", cnt[0][ans[0]] + cnt[1][ans[1]] + cnt[2][ans[2]]);
  for (i = 0; i < n; ++i) in[i] = str[ans[i % 3]];
  return !printf("%s\n", in);
}