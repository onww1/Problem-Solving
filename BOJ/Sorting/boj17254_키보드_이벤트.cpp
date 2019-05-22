#include <algorithm>
#include <cstdio>
using namespace std;

struct event {
    int idx, t;
    char c;
} events[1000];

int N, M;
char ans[1001];

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; ++i) 
        scanf("%d %d %c", &events[i].idx, &events[i].t, &events[i].c);

    sort(events, events + M, [](const event& a, const event& b) {
        if (a.t == b.t) return a.idx < b.idx;
        return a.t < b.t;
    });
    
    for (int i = 0; i < M; ++i) ans[i] = events[i].c;
    printf("%s\n", ans);
    return 0;
}