#include <algorithm>
#include <cstdio>
#include <set>
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;

const int MAX = 1e5;
int N, M;
pii AB[MAX], CD[MAX];
set <pii> S;

bool cmp(pii &a, pii &b) {
    if (a.Y == b.Y) return a.X > b.X;
    return a.Y > b.Y;
}

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; ++i) scanf("%d %d", &AB[i].X, &AB[i].Y);
    for (int i = 0; i < M; ++i) scanf("%d %d", &CD[i].X, &CD[i].Y);

    sort(AB, AB + N, cmp);
    sort(CD, CD + M, cmp);

    ll ans = 0;
    for (int i = 0, j = 0; i < N; ++i) {
        while (j < M && AB[i].Y <= CD[j].Y) S.insert(CD[j++]);
        auto lower = S.lower_bound(AB[i]);
        if (lower == S.end()) return !printf("-1\n");
        ans += lower->X;
        S.erase(lower);
    }

    printf("%lld\n", ans);
    return 0;
}