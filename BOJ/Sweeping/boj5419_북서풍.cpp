#include <algorithm>
#include <cstdio>
#include <cstring>
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;

const int MAX = 75001;
int t, n, yn, y[MAX], tree[MAX];
pii p[MAX];

int sum(int node) {
    int ret = 0;
    while (node) {
        ret += tree[node];
        node -= node & -node;
    }
    return ret;
}

void update(int node, int val) {
    while (node <= yn) {
        tree[node] += val;
        node += node & -node;
    }
}

int main(int argc, char *argv[]) {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d %d", &p[i].X, &p[i].Y), y[i] = p[i].Y;

        sort(y, y + n);
        yn = unique(y, y + n) - y;
        for (int i = 0; i < n; ++i) p[i].Y = lower_bound(y, y + yn, p[i].Y) - y + 1;

        sort(p, p + n, [](const pii a, const pii b) {
            if (a.X == b.X) return a.Y > b.Y;
            return a.X < b.X;
        });

        memset(tree, 0, sizeof(tree));
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += (i - sum(p[i].Y - 1));
            update(p[i].Y, 1);
        }

        printf("%lld\n", ans);
    }
  
    return 0;
}