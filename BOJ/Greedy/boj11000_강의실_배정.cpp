#include <algorithm>
#include <cstdio>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

int n;
pii a[200050];

int main(int argc, char *argv[]) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d %d", &a[i].Y, &a[i].X);
    sort(a, a + n, [](const pii aa, const pii bb){
        if (aa.Y == bb.Y) return aa.X < bb.X;
        return aa.Y < bb.Y;
    });

    priority_queue <pii, vector<pii>, greater<pii>> pq;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        while (!pq.empty() && pq.top().X <= a[i].Y) pq.pop();
        pq.push(a[i]);
        ans = max(ans, (int)pq.size());
    }

    printf("%d\n", ans);
    return 0;
}