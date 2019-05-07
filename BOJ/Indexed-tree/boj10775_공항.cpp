#include <cstdio>

const int MAX = 1e5;
int G, P, ans, tree[MAX + 1];

void update(int node, int v) {
    while (node <= G) {
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
    scanf("%d %d", &G, &P);
    for (int i = 0, p; i < P; ++i, ++ans) {
        scanf("%d", &p);
        if (sum(p) == p) {
            for (++i; i < P; ++i) scanf("%d", &p);
            break;
        }

        int l = 1, r = p, m = p, s = p;
        while (l <= r) {
            m = (l + r) >> 1;
            if (sum(m) < m) {
                s = m;
                l = m + 1;
            } else r = m - 1;
        }
        update(s, 1);
    }

    printf("%d\n", ans);
    return 0;
}