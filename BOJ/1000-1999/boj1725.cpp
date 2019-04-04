#include <algorithm>
#include <cstdio>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

const int SZ = 1 << 17;
const int INF = 0x7f7f7f7f;
int N, H[SZ];
pii tree[2 * SZ];

pii init(int node, int start, int end) {
    if (start == end) return tree[node] = { H[start], start };
    int mid = (start + end) / 2;
    return tree[node] = min(init(node * 2, start, mid), init(node * 2 + 1, mid + 1, end));
}

pii get_min(int node, int start, int end, int left, int right) {
    if (right < start || end < left) return {INF, INF};
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return min(get_min(node * 2, start, mid, left, right),
               get_min(node * 2 + 1, mid + 1, end, left, right));
}

int solve(int s, int e) {
    if (s > e) return 0;
    if (s == e) return H[s];
    pii mn = get_min(1, 0, N - 1, s, e);
    int ret = (e - s + 1) * mn.X;
    ret = max(ret, solve(s, mn.Y - 1));
    ret = max(ret, solve(mn.Y + 1, e));
    return ret;
}

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", H + i);
    init(1, 0, N - 1);
    printf("%d\n", solve(0, N - 1));
    return 0;
}