#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#define INF 1023456789LL
#define MOD 1000000007LL
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int, int> pii;

ll get_gcd(ll a, ll b) {
  ll gcd_val = b;
  while (a % gcd_val) {
    b = a % gcd_val;
    a = gcd_val;
    gcd_val = b;
  }
  return gcd_val;
}

int in[200050], mx = 0;
vector <int> edges[200050];

vector<pii> solve(int node, int parent) {
  vector <pii> d;
  if (in[node] > 1) d.push_back({in[node], 1});
  for (auto it : edges[node]) {
    if (it == parent) continue;
    vector<pii> val = solve(it, node);
    for (auto it2 : val) {
      ll gcd_val = get_gcd(it2.first, in[node]);
      if (gcd_val > 1) {
        d.push_back({gcd_val, it2.second + 1});
        mx = max(mx, it2.second + 1);
      }
    }
  }
  for (int i = 0; i < d.size() - 1; ++i) {
    for (int j = i + 1; j < d.size(); ++j) {
      ll gcd_val = get_gcd(d[i].first, d[j].first);
      if (gcd_val > 1) mx = max(mx, d[i].second + d[j].second - 1);
    }
  }
  return d;
}

int main(int argc, char *argv[]) {
  int n, i, u, v;
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) {
    scanf("%d", in + i);
    if (in[i] > 1) mx = 1;
  }
  for (i = 1; i < n; ++i) {
    scanf("%d %d", &u, &v);
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  if (mx == 0) return !printf("%d\n", mx);
  solve(1, 0);
  return !printf("%d\n", mx);
}
