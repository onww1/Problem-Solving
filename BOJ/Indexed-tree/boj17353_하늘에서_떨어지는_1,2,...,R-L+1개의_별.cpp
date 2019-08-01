#include <algorithm>
#include <cstdio>
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

const int SZ = 1 << 17;
ll a[SZ];
pll lazy[2 * SZ];
int n, q;

void update_lazy(int node, int start, int end) {
    if (lazy[node].X) {
        if (start != end) {
            int mid = (start + end) >> 1;
            lazy[node * 2].X += lazy[node].X;
            lazy[node * 2].Y += lazy[node].Y;
            lazy[node * 2 + 1].X += lazy[node].X;
            lazy[node * 2 + 1].Y += lazy[node].Y;
            lazy[node * 2 + 1].Y += lazy[node].X * (mid + 1 - start);
        }
        else a[start] += lazy[node].Y;
        lazy[node] = {0, 0};
    }
}

void update_range(int node, int start, int end, int left, int right, int v) {
    update_lazy(node, start, end);
    if (end < left || right < start) return;
    if (left <= start && end <= right) {
        lazy[node].X += 1;
        lazy[node].Y += v;
        update_lazy(node, start, end);
        return;
    }

    int mid = (start + end) >> 1;
    update_range(node * 2, start, mid, left, right, v);
    update_range(node * 2 + 1, mid + 1, end, left, right, max(0, mid + 2 - left));
}

ll query(int node, int start, int end, int pos) {
    update_lazy(node, start, end);
    if (end < pos || pos < start) return 0;
    if (pos <= start && end <= pos) return a[pos];
    int mid = (start + end) >> 1;
    return query(node * 2, start, mid, pos) +
           query(node * 2 + 1, mid + 1, end, pos);
}

int main(int argc, char *argv[]) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%lld", a + i);

    scanf("%d", &q);
    for (int i = 0, x, y, z; i < q; ++i) {
        scanf("%d %d", &x, &y);
        if (x == 1) {
            scanf("%d", &z);
            update_range(1, 1, n, y, z, 1);
        }
        else 
            printf("%lld\n", query(1, 1, n, y));
    }
    return 0;
}