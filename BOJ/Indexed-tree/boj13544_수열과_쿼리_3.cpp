#include <cstdio>
#include <vector>
using namespace std;

const int SZ = 1 << 17;
int N, M, L, a, b, c, A[SZ];
vector <int> tree[2 * SZ];

void init(int node, int start, int end) {
    if (start == end) {
        tree[node].push_back(A[start]);
        return;
    }

    int mid = (start + end) >> 1;
    init(node * 2, start, mid);
    init(node * 2 + 1, mid + 1, end);
    int i = 0, j = 0;
    while (i < tree[node * 2].size() && j < tree[node * 2 + 1].size()) {
        if (tree[node * 2][i] < tree[node * 2 + 1][j]) tree[node].push_back(tree[node * 2][i++]);
        else tree[node].push_back(tree[node * 2 + 1][j++]);
    }
    while (i < tree[node * 2].size()) tree[node].push_back(tree[node * 2][i++]);
    while (j < tree[node * 2 + 1].size()) tree[node].push_back(tree[node * 2 + 1][j++]);
}

int query(int node, int start, int end, int left, int right, int k) {
    if (end < left || right < start) return 0;
    if (left <= start && end <= right) {
        auto it = lower_bound(tree[node].begin(), tree[node].end(), k);
        if (it == tree[node].end()) return 0;
        else return (int)tree[node].size() - (it - tree[node].begin() + (*it == k));
    }

    int mid = (start + end) >> 1;
    return query(node * 2, start, mid, left, right, k) + query(node * 2 + 1, mid + 1, end, left, right, k);
}

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf("%d", A + i);
    init(1, 0, N - 1);

    scanf("%d", &M);
    while (M--) {
        scanf("%d %d %d", &a, &b, &c);
        a ^= L;
        b ^= L;
        c ^= L;
        L = query(1, 0, N - 1, a - 1, b - 1, c);
        printf("%d\n", L);
    }

    return 0;
}