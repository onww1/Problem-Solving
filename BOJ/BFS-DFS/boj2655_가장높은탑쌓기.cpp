#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int n, mx, dp[105];
vector <int> edges[105], ans, tmp;

struct stone {
    int a, h, w;
} s[105];

void dfs(int node, int h) {
    if (edges[node].size() == 0) {
        if (h > mx) {
            ans.clear();
            for (int node : tmp) ans.push_back(node);
            mx = h;
        }
        return;
    }

    for (int next : edges[node]) {
        if (h + s[next].h > dp[next]) {
            dp[next] = h + s[next].h;
            tmp.push_back(next);
            dfs(next, h + s[next].h);
            tmp.pop_back();
        }
    }
}

int main(int argc, char *argv[]) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d %d", &s[i].a, &s[i].h, &s[i].w);
        for (int j = 1; j < i; ++j) {
            if (s[i].a > s[j].a && s[i].w > s[j].w) edges[i].push_back(j);
            else if (s[i].a < s[j].a && s[i].w < s[j].w) edges[j].push_back(i);
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (s[i].h > dp[i]) {
            dp[i] = s[i].h;
            tmp.clear(); tmp.push_back(i);
            dfs(i, s[i].h);    
        }
    }

    printf("%lu\n", ans.size());
    reverse(ans.begin(), ans.end());
    for (int node : ans) printf("%d\n", node);
    return 0;
}