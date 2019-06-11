#include <algorithm>
#include <cstdio>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

const int MAX = 1e5 + 1;
int N, DP[MAX], A[2 * MAX][2];
pii P[MAX];

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        char c = 0;
        scanf("%d %c", &P[i].X, &c);
        P[i].Y = (c == 'G');
    }
    sort(P + 1, P + N + 1);

    int ans = 0, mx = 0, mn = 2 * MAX;
    for (int i = 1, prev = P[1].Y, idx = 1; i <= N; ++i) {
        if (P[i].Y) DP[i] = DP[i - 1] + 1;
        else DP[i] = DP[i - 1] - 1;

        if (!A[DP[i - 1] + 100000][0]) A[DP[i - 1] + 100000][0] = i;
        A[DP[i] + 100000][1] = i;

        if (prev != P[i].Y) {
            ans = max(ans, P[i - 1].X - P[idx].X);
            prev = P[i].Y;
            idx = i;
        } else if (i == N) 
            ans = max(ans, P[i].X - P[idx].X);
    }

    for (int i = 0; i < 2 * MAX; ++i) 
        if (A[i][0] && A[i][1]) 
            ans = max(ans, P[A[i][1]].X - P[A[i][0]].X);

    printf("%d\n", ans);
    return 0;
}