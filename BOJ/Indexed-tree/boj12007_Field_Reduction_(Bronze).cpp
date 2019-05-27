#include <cstdio>

const int SZ = 1 << 16;
const int INF = 0x7f7f7f7f;
int N, X[SZ], Y[SZ];
int X_mn[2 * SZ], Y_mn[2 * SZ], X_mx[2 * SZ], Y_mx[2 * SZ];

int init(int *arr, int *tree, int (*func)(int, int), int node, int start, int end) {
    if (start == end) return tree[node] = arr[start];
    int mid = (start + end) >> 1;
    return tree[node] = func(init(arr, tree, func, node * 2, start, mid),
                             init(arr, tree, func, node * 2 + 1, mid + 1, end));
}

int get_elem(int *tree, int (*func)(int, int), int node, int start, int end, int left, int right) {
    if (end < left || right < start) return func(1, 0) ? -INF : INF;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) >> 1;
    return func(get_elem(tree, func, node * 2, start, mid, left, right),
                get_elem(tree, func, node * 2 + 1, mid + 1, end, left, right));
}

int get_min(int a, int b) { return a < b ? a : b; }
int get_max(int a, int b) { return a > b ? a : b; }

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf("%d %d", X + i, Y + i);
    
    init(X, X_mn, get_min, 1, 0, N - 1);
    init(Y, Y_mn, get_min, 1, 0, N - 1);
    init(X, X_mx, get_max, 1, 0, N - 1);
    init(Y, Y_mx, get_max, 1, 0, N - 1);

    int ans = INF;
    for (int i = 0; i < N; ++i) {
        int x_mn = get_min(get_elem(X_mn, get_min, 1, 0, N - 1, 0, i - 1),
                           get_elem(X_mn, get_min, 1, 0, N - 1, i + 1, N - 1));
        int y_mn = get_min(get_elem(Y_mn, get_min, 1, 0, N - 1, 0, i - 1),
                           get_elem(Y_mn, get_min, 1, 0, N - 1, i + 1, N - 1));
        int x_mx = get_max(get_elem(X_mx, get_max, 1, 0, N - 1, 0, i - 1),
                           get_elem(X_mx, get_max, 1, 0, N - 1, i + 1, N - 1));
        int y_mx = get_max(get_elem(Y_mx, get_max, 1, 0, N - 1, 0, i - 1),
                           get_elem(Y_mx, get_max, 1, 0, N - 1, i + 1, N - 1));
        ans = get_min(ans, (y_mx - y_mn) * (x_mx - x_mn));
    }

    printf("%d\n", ans);
    return 0;
}