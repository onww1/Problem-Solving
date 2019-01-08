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

vector <int> edges[100001];
int s[100001], a[100001];

void solve(int node, ll prev_sum) {
  if (edges[node].size() == 0) {
    if (s[node] == -1) a[node] = 0;
    else a[node] = s[node] - prev_sum;
    return;
  }

  if (s[node] == -1) {
    int mn = INF;
    for (auto it : edges[node]) {
      mn = min(mn, s[it]);
    }
    a[node] = mn - prev_sum;
    prev_sum = mn;
  } else {
    a[node] = s[node] - prev_sum;
    prev_sum = s[node];
  }

  for (auto it : edges[node]) {
    solve(it, prev_sum);
  }
}

int main(int argc, char *argv[]) {
  int n, p, i;
  ll sum = 0;

  scanf("%d", &n);

  for (i = 2; i <= n; ++i) {
    scanf("%d", &p);
    edges[p].push_back(i);
  }

  for (i = 1; i <= n; ++i) {
    scanf("%d", &s[i]);
  }

  solve(1, 0LL);

  bool valid = true;
  for (i = 1; valid && i <= n; ++i) {
    if (a[i] < 0) valid = false;
    sum += (ll)a[i];
  }

  if (!valid) return !printf("-1\n");
  return !printf("%lld\n", sum);
}
