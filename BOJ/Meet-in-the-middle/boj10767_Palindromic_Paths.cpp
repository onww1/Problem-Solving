#include <algorithm>
#include <cstdio>
#include <set>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;
typedef pair<int, pii> piii;

const int MOD = 1e9 + 7;
int N, P[2] = {9973, 36151};
char MAP[18][19];
set <piii> S;

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf(" %s", MAP[i]);

    int lim = 1 << (N - 1);
    for (int i = 0, r, c, h1, h2; i < lim; ++i) {
        r = c = 0;
        h1 = h2 = MAP[r][c] - 'A';
        for (int j = 0; j < N - 1; ++j) {
            if (i & (1 << j)) r++;
            else c++;
            h1 = (1LL * h1 * P[0] + MAP[r][c] - 'A') % MOD;
            h2 = (1LL * h2 * P[1] + MAP[r][c] - 'A') % MOD;
        }
        piii hash = { r, { h1, h2 } };
        S.insert(hash);
    }

    set <pii> ans;
    for (int i = 0, r, c, h1, h2; i < lim; ++i) {
        r = c = N - 1;
        h1 = h2 = MAP[r][c] - 'A';
        for (int j = 0; j < N - 1; ++j) {
            if (i & (1 << j)) r--;
            else c--;
            h1 = (1LL * h1 * P[0] + MAP[r][c] - 'A') % MOD;
            h2 = (1LL * h2 * P[1] + MAP[r][c] - 'A') % MOD;
        }
        piii hash = { r, { h1, h2 } };
        if (S.count(hash)) {
            ans.insert(hash.Y);
            S.erase(hash);
        }
    }

    printf("%lu\n", ans.size());
    return 0;
}