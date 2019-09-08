#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;

struct info {
    int s, e, w;
} infos[10050];

int n, c, m, s[2050];

int main(int argc, char *argv[]) {
    scanf("%d %d %d", &n, &c, &m);
    for (int i = 0; i < m; ++i) scanf("%d %d %d", &infos[i].s, &infos[i].e, &infos[i].w);
    sort(infos, infos + m, [](const info a, const info b) {
        return a.s == b.s ? a.e < b.e : a.s < b.s;
    });
    
    int ans = 0, sum = 0;
    priority_queue <int> pq;
    for (int i = 1, pos = 0; i <= n; ++i) {
        ans += s[i];
        sum -= s[i];
        while (pos < m && infos[pos].s <= i) {
            s[infos[pos].e] += infos[pos].w;
            pq.push(infos[pos].e);
            sum += infos[pos].w;
            while (sum > c) {
                int idx = pq.top();
                int diff = min(s[idx], sum - c);
                sum -= diff;
                s[idx] -= diff;
                if (!s[idx]) pq.pop();
            }
            pos++;
        }
    }

    printf("%d\n", ans);
    return 0;
}