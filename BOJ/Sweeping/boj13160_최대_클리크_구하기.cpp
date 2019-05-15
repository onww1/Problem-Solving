#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;

const int MAX = 3e5;
int N, mx, x;

struct seg {
    int l, r, idx;
    bool operator< (const seg& other) const {
        return r > other.r;
    }
} P[MAX];

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &P[i].l, &P[i].r);
        P[i].idx = i + 1;
    }
    sort(P, P + N, [](const seg& a, const seg& b) { return a.l < b.l; });

    priority_queue <seg> pq;
    for (int i = 0; i < N; ++i) {
        while (!pq.empty() && pq.top().r < P[i].l) pq.pop();
        pq.push(P[i]);
        if (mx < (int)pq.size()) {
            mx = (int)pq.size();
            x = P[i].l;
        }
    }

    printf("%d\n", mx);
    for (int i = 0; i < N; ++i) 
        if (P[i].l <= x && x <= P[i].r) printf("%d ", P[i].idx);
    puts("");
    return 0;
}