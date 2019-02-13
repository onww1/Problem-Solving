#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 1e6;
int n, tree[MAX + 1];

void update(int node, int diff) {
    while (node <= MAX) {
        tree[node] += diff;
        node += node & -node;
    }
}

int sum(int node) {
    int ret = 0;
    while (node > 0) {
        ret += tree[node];
        node -= node & -node;
    }
    return ret;
}

int main(int argc, char *argv[]) {
    int a, b, c;
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d", &a, &b);
        if (a == 2) {
            scanf("%d", &c);
            update(b, c);
        } else {
            int l = 1, r = MAX, m, sm, ans;
            while (l <= r) {
                m = (l + r) / 2;
                sm = sum(m);
                if (sm >= b) {
                    ans = m;
                    r = m - 1;
                }
                else l = m + 1;
            }
            printf("%d\n", ans);
            update(ans, -1);
        }
    }
    return 0;
}