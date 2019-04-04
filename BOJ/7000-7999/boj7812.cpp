#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, ll> pil;

struct edge {
    int v;
    ll w;
};

vector <edge> edges[10050];
pil dp[10050];

pil solve1(int node, int parent) {
    int nn = 1;
    ll s = 0;
    for (auto it : edges[node]) {
        if (it.v == parent) continue;
        pil val = solve1(it.v, node);
        nn += val.first;
        s += (val.second + it.w * val.first);
    }
    return dp[node] = {nn, s};
}

void solve2(int node, int parent) {
    for (auto it : edges[node]) {
        if (it.v == parent) continue;
        dp[it.v].second = dp[node].second + (it.w * (dp[node].first - 2 * dp[it.v].first));
        dp[it.v].first = dp[node].first;
        solve2(it.v, node);
    }
}

int main(int argc, char *argv[]) {
    int n, i, u, v;
    ll w;
    while (1) {
        scanf("%d", &n);
        if (!n) break;
        for (i = 0; i < n; ++i) edges[i].clear();
        for (i = 1; i < n; ++i) {
            scanf("%d %d %lld", &u, &v, &w);
            edges[u].push_back({v, w});
            edges[v].push_back({u, w});
        }
        solve1(0, -1);
        solve2(0, -1);
        ll mn = 1LL << 60;
        for (i = 0; i < n; ++i) mn = min(mn, dp[i].second);
        printf("%lld\n", mn);
    }
    return 0;
}