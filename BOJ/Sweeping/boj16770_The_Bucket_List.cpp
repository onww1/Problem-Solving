#include <algorithm>
#include <functional>
#include <cstdio>
#include <queue>
using namespace std;

struct task {
    int s, t, b;
    bool operator< (const task& other) const {
        return t > other.t;
    }
} T[100];

int N;

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0, s, t, b; i < N; ++i) {
        scanf("%d %d %d", &s, &t, &b);
        T[i] = {s, t, b};
    }

    sort(T, T + N, [](const task& a, const task& b) { return a.s < b.s; });
    
    priority_queue <task> pq;
    int tot = 0, use = 0;
    for (int i = 0; i < N; ++i) {
        while (!pq.empty() && pq.top().t < T[i].s) {
            use -= pq.top().b;
            pq.pop();
        }
        if (tot - use < T[i].b) {
            int diff = T[i].b - tot + use;
            tot += diff;
        }
        pq.push(T[i]);
        use += T[i].b;
    }

    printf("%d\n", tot);
    return 0;
}