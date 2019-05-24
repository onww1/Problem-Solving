#include <algorithm>
#include <cstdio>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

int C, N, T[20000];
pii P[20000];

int main(int argc, char *argv[]) {
    scanf("%d %d", &C, &N);
    for (int i = 0; i < C; ++i) scanf("%d", T + i);
    for (int i = 0; i < N; ++i) scanf("%d %d", &P[i].Y, &P[i].X);
    sort(T, T + C);
    sort(P, P + N, [](const pii& a, const pii& b) {
        if (a.Y == b.Y) return a.X < b.X;
        return a.Y < b.Y;
    });
    
    int ans = 0;
    priority_queue <pii, vector<pii>, greater<pii>> pq;
    for (int i = 0, j = 0; i < C; ++i) {
        while (j < N && P[j].Y <= T[i]) pq.push(P[j++]);
        while (!pq.empty() && pq.top().X < T[i]) pq.pop();
        if (pq.size()) ans++, pq.pop();
    }

    printf("%d\n", ans);
    return 0;
}