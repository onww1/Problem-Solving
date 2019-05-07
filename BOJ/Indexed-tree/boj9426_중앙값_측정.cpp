#include <cstdio>
typedef long long ll;

int N, K, A[250001], tree[65537];
ll ans;

void update(int node, int v) {
    while (node <= 65536) {
        tree[node] += v;
        node += node & -node;
    }
}

int sum(int node) {
    int ret = 0;
    while (node) {
        ret += tree[node];
        node -= node & -node;
    }
    return ret;
}

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &K);
    for (int i = 1, half = (K + 1) / 2; i <= N; ++i) {
        scanf("%d", A + i);
        update(A[i] + 1, 1);
        if (i < K) continue;
        if (i > K) update(A[i - K] + 1, -1);

        int l = 1, r = 65536, m = r, median = r;
        while (l <= r) {
            m = (l + r) >> 1;
            if (sum(m) >= half) {
                median = m;
                r = m - 1;
            } else l = m + 1;
        }
        ans += median - 1;
    }
    
    printf("%lld\n", ans);
    return 0;
}