#include <cstdio>
#include <set>
using namespace std;

const int MAX = 1e5 + 1;
const int MOD = 1 << 20;
int N, M, T[MAX], ans;

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &M);
    for (int i = 0, a, b, c; i < M; ++i) {
        scanf("%d %d", &a, &b);
        if (a < 3) scanf("%d", &c);

        if (a == 1) T[b] |= (1 << (c - 1));
        if (a == 2) if (T[b] & (1 << (c - 1))) T[b] ^= (1 << (c - 1));
        if (a == 3) T[b] = (T[b] * 2) % MOD;
        if (a == 4) T[b] /= 2;
    }

    set <int> s;
    for (int i = 1; i <= N; ++i) {
        if (s.count(T[i])) continue;
        ans++;
        s.insert(T[i]);
    }

    printf("%d\n", ans);
    return 0;
}