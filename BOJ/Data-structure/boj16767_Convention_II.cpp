#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;

struct cow {
    int age, a, t;
    bool operator< (const cow& other) const {
        return age < other.age;
    }
};

const int MAX = 1e5;
int N;
cow P[MAX];
priority_queue <cow> pq;

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0, a, t; i < N; ++i) {
        scanf("%d %d", &a, &t);
        P[i] = { N - i, a, t };
    }
    sort(P, P + N, [](const cow& a, const cow& b) { return a.a < b.a; });

    int cur = 0, mx = 0;
    for (int i = 0; 1;) {
        while (i < N && P[i].a <= cur) pq.push(P[i++]);
        if (pq.empty()) {
            cur = P[i].a;
            while (i < N && P[i].a <= cur) pq.push(P[i++]);
        }
        if (!pq.empty()) {
            cow c = pq.top(); pq.pop();
            mx = max(mx, cur - c.a);
            cur += c.t;
        } else break;
    }

    printf("%d\n", mx);
    return 0;
}