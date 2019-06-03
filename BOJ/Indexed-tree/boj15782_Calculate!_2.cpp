#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int SZ = 1 << 17;
const int MAX = 1e5 + 1;
int n, m, o, a[SZ], idx[SZ], ridx[SZ], ch[SZ], tree[2 * SZ], lazy[2 * SZ];
vector <int> edges[MAX];

int dfs(int node, int pa) {
    ridx[node] = ++o;
    idx[o] = node;

    for (int next : edges[node]) 
        if (next != pa) 
            ch[node] += dfs(next, node);
    return ch[node] + 1;
}

int init(int node, int start, int end) {
    if (start == end) return tree[node] = a[idx[start]];
    int mid = (start + end) >> 1;
    return tree[node] = init(node * 2, start, mid) ^ init(node * 2 + 1, mid + 1, end);
}

void update_lazy(int node, int start, int end) {
    if (lazy[node]) {
        tree[node] ^= (end - start + 1) % 2 * lazy[node];
        if (start != end) {
            lazy[node * 2] ^= lazy[node];
            lazy[node * 2 + 1] ^= lazy[node];
        }
        lazy[node] = 0;
    }
}

void update_range(int node, int start, int end, int left, int right, int val) {
    update_lazy(node, start, end);
    if (end < left || right < start) return;
    if (left <= start && end <= right) {
        tree[node] ^= (end - start + 1) % 2 * val;
        if (start != end) {
            lazy[node * 2] ^= val;
            lazy[node * 2 + 1] ^= val;
        }
        return;
    }

    int mid = (start + end) >> 1;
    update_range(node * 2, start, mid, left, right, val);
    update_range(node * 2 + 1, mid + 1, end, left, right, val);
    tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}

int query(int node, int start, int end, int left, int right) {
    update_lazy(node, start, end);
    if (end < left || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) >> 1;
    return query(node * 2, start, mid, left, right) ^ query(node * 2 + 1, mid + 1, end, left, right);
}

int main(int argc, char *argv[]) {
    scanf("%d %d", &n, &m);
    for (int i = 1, u, v; i < n; ++i) {
        scanf("%d %d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);

    dfs(1, 0);
    init(1, 1, n);

    for (int i = 0, c, x, y; i < m; ++i) {
        scanf("%d %d", &c, &x);
        if (c == 1) printf("%d\n", query(1, 1, n, ridx[x], ridx[x] + ch[x]));
        else {
            scanf("%d", &y);
            update_range(1, 1, n, ridx[x], ridx[x] + ch[x], y);
        }
    }

    return 0;
}