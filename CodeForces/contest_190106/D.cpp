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

ll get_pow(ll base, ll exp);
ll get_min(ll a, ll b);
ll get_max(ll a, ll b);
ll get_abs(ll a);

vector<int> edges[100001];
int s[100001], a[100001];
bool valid = true;

void solve(int node, int sum) {
  if (s[node] == -1) a[node] = 0;
  else a[node] = s[node] - sum;

  if (a[node] < 0) valid = false;
  if (!valid) return;
  
  if (edges[node].size() == 0) return;

  for (auto &it : edges[node]) {
    if (s[node] == -1) solve(it, sum);
    else solve(it, s[node]);
  }
}

int main(int argc, char *argv[]) {
    int n, i, p;
    scanf("%d", &n);

    for (i = 2; i <= n; ++i) {
      scanf("%d", &p);
      edges[p].push_back(i);
    }

    for (i = 1; i <= n; ++i) {
      scanf("%d", &s[i]);
    }
    solve(1, 0);
    
    ll sum = 0LL;
    for (i = 1; i <= n; ++i) {
      if (a[i] < 0) {
        valid = false;
        break;
      }
      sum += (ll)a[i];
    }

    if (valid) printf("%lld\n", sum);
    else printf("-1\n");
    return 0;
}

ll get_pow(ll base, ll exp) {
    ll ret = 1LL;
    while (exp > 0) {
        if (exp % 2) {
            ret *= base;
            ret %= MOD;
        }
        base *= base;
        base %= MOD;
        exp /= 2;
    }
    return ret;
}

ll get_min(ll a, ll b) { return a < b ? a : b; }
ll get_max(ll a, ll b) { return a > b ? a : b; }
ll get_abs(ll a) { return a < 0 ? -a : a; }