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
ll ans = 0LL;

ll solve(int node, int parent) {
  vector <ll> dist;
  for (auto it : edges[node]) {
    if (it.v == parent) continue;
    dist.push_back((1LL + solve(it.v, node)) * it.w % MOD);
  }
  if (dist.size() == 0) return 0LL;

  ll s = 0LL;
  for (auto it : dist) ans = (ans + (s + 1) * it) % MOD, s = (s + it) % MOD;
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
  
  solve(1, 0);
  return !printf("%lld\n", ans);
}

// #include <cstdio>
// #include <vector>
// #define MOD 1000000007LL
// using namespace std;

// typedef long long ll;
// struct edge {
//   int v;
//   ll w;
// };

// vector <edge> edges[100050];
// ll ans = 0LL;

// ll solve(int node, int parent) {
//   vector <ll> dist;
//   for (auto it : edges[node]) {
//     if (it.v == parent) continue;
//     dist.push_back((1LL + solve(it.v, node)) * it.w % MOD);
//   }

//   if (dist.size() == 0) return 0LL;

//   ll s = 0LL, ret;
//   for (auto it : dist) s = (s + it) % MOD;
//   ret = s;
//   ans = (ans + s) % MOD;
//   for (auto it : dist) s = (s - it + MOD) % MOD, ans = (ans + s * it) % MOD;
//   return ret;
// }

// int main(int argc, char *argv[]) {
//   int n, i, u, v;
//   ll w;
//   scanf("%d", &n);
//   for (i = 1; i < n; ++i) {
//     scanf("%d %d %lld", &u, &v, &w);
//     edges[u].push_back({v, w});
//     edges[v].push_back({u, w});
//   }
  
//   solve(1, 0);
//   return !printf("%lld\n", ans);
// }