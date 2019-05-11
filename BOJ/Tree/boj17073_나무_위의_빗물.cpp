#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
typedef long double ldb;

const int MAX = 5e5;
int N, W, cnt;
ldb sum;
vector <int> edges[MAX];

void dfs(int node, int pa, ll val) {
    if (edges[node].size() == 1) {
        ++cnt;
        sum += (ldb)W / val;
        return;
    }

    ll next_val = val * ((ll)edges[node].size() - 1);
    for (int next : edges[node]) {
        if (next != pa) {
            dfs(next, node, next_val);
        }
    }
}

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &W);
    edges[0].push_back(-1);
    for (int i = 1, u, v; i < N; ++i) {
        scanf("%d %d", &u, &v);
        --u; --v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    dfs(0, -1, 1);
    printf("%.12Lf\n", sum / cnt);

    return 0;
}