#include <algorithm>
#include <cstdio>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

const int MAX = 1e5 + 1;
const int INF = 0x3f3f3f3f;
pii P[MAX];
int N, tot, mn = INF;

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    if (N == 1) return !printf("0\n");

    for (int i = 1; i <= N; ++i) {
        scanf("%d %d", &P[i].X, &P[i].Y);
        P[i].Y--;
    }
    sort(P + 1, P + N + 1, [](const pii& a, const pii& b){ return a.Y < b.Y; });

    for (int i = N, l = INF; i > 0; --i) {
        if (l > P[i].Y) {
            tot += (P[i].Y - P[i].X + 1);
            l = P[i].X;
        }
        else if (P[i].X < l && l <= P[i].Y) {
            tot += (l - P[i].X);
            l = P[i].X;
        }

        int L = P[i].X, R = P[i].Y;
        if (i > 1) L = max(L, P[i - 1].Y);
        if (i < N) R = min(R, P[i + 1].X);
        mn = min(mn, max(0, R - L - 1));
    }

    printf("%d\n", tot - mn);
    return 0;
}