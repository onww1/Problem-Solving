#include <algorithm>
#include <cstdio>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

const int SZ = 1 << 17;
const int INF = 0x3f3f3f3f;
int n, s[SZ];
pii tree[2 * SZ];

pii init(int node, int start, int end) {
    if (start == end) return tree[node] = {s[start], start};
    int mid = (start + end) >> 1;
    return tree[node] = min(init(node * 2, start, mid), init(node * 2 + 1, mid + 1, end));
}

pii query(int node, int start, int end, int left, int right) {
    if (end < left || right < start) return {INF, INF};
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) >> 1;
    return min(query(node * 2, start, mid, left, right),
               query(node * 2 + 1, mid + 1, end, left, right));
}

int main(int argc, char *argv[]) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%*d %d", s + i);

    init(1, 0, n - 1);
    int l = 0, ans = 0;
    while (l < n) {
        int idx = query(1, 0, n - 1, l, n - 1).Y;
        ans++;
        l = idx + 1;
    }

    printf("%d\n", ans);
    return 0;
}