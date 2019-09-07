#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;

int n, k, a[10050];

int main(int argc, char *argv[]) {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    sort(a, a + n);

    priority_queue <int> pq;
    for (int i = 1; i < n; ++i) pq.push(a[i] - a[i - 1]);

    int ans = a[n - 1] - a[0];
    for (int i = 1; !pq.empty() && i < k; ++i) ans -= pq.top(), pq.pop();
    printf("%d\n", ans);

    return 0;
}