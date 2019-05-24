#include <algorithm>
#include <cstdio>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

int N, ans;
pii P[100];

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf("%d %d", &P[i].X, &P[i].Y);
    sort(P, P + N);

    for (int i = 0; i < N; ++i) {
        if (P[i].X >= ans) ans = P[i].X + P[i].Y;
        else ans += P[i].Y;
    }

    printf("%d\n", ans);
    return 0;
}