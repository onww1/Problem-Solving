#include <algorithm>
#include <cstdio>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

const int MAX = 1e4;
int N, L, P, idx, ans;
pii A[MAX + 1];
priority_queue <int> pq;

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf("%d %d", &A[i].X, &A[i].Y);
    scanf("%d %d", &L, &P);

    sort(A, A + N);

    while (P < L) {
        while (A[idx].X <= P) {
            if (idx == N) break;
            pq.push(A[idx++].Y);
        }
        if (pq.empty()) break;
        ans++;
        P += pq.top();
        pq.pop();
    }
    printf("%d\n", P < L ? -1 : ans);
    return 0;
}