#include <cstdio>
#include <vector>
#define MOD 1000000007LL
using namespace std;

typedef long long ll;
struct edge {
  int v;
  ll w;
};

vector <edge> edges[100050];
bool visited[100050] = {true, true};
ll ans = 0LL;

ll solve(int node) {
  vector <ll> dist;
  for (auto it : edges[node]) {
    if (visited[it.v]) continue;
    visited[it.v] = true;
    dist.push_back((1LL + solve(it.v)) * it.w % MOD);
  }

  if (dist.size() == 0) return 0LL;

  ll s = 0LL, sum = 0LL;
  for (auto it : dist) s = (s + it) % MOD;
  for (auto it : dist) sum = (sum + (s - it) * it);
  ans = (ans + s + (sum / 2LL)) % MOD;
  return s;
}

int main(int argc, char *argv[]) {
  int n, i, u, v;
  ll w;
  scanf("%d", &n);
  for (i = 1; i < n; ++i) {
    scanf("%d %d %lld", &u, &v, &w);
    edges[u].push_back({v, w});
    edges[v].push_back({u, w});
  }
  
  solve(1);
  return !printf("%lld\n", ans);
}
