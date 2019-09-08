#include <algorithm>
#include <cstdio>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

int n;
pii a[1005];

int main(int argc, char *argv[]) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d %d", &a[i].X, &a[i].Y);
    sort(a, a + n, [](const pii a, const pii b) { return a.X > b.X; });
    int ans = 0, idx = 0;
    priority_queue <int> pq;
    for (int i = 1000; i > 0; --i) {
        while (a[idx].X >= i) pq.push(a[idx++].Y);
        if (!pq.empty()) ans += pq.top(), pq.pop();
    }
    printf("%d\n", ans);
    return 0;
}