#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long double ldb;

const ldb ERR = 1e-10;
int T, N, P[16][16];
ldb DP[16][1 << 16];

ldb _abs(ldb a) { return a < 0 ? -a : a; }

ldb solve(int idx, int state) {
    // 모든 것을 확인했으면 1을 리턴
    if (state == (1 << N) - 1) return 1;
    
    ldb &ret = DP[idx][state];
    if (_abs(ret + 1) > ERR) return ret;    // DP가 -1이 아니면 그 값을 리턴
    ret = 1.0;

    ldb mx = 0;
    for (int i = 0; i < N; ++i) {
        // 아직 선택받지 않은 일들에 대해서 재귀 호출해보고 가장 큰값을 취함.
        if (state & (1 << i)) continue;
        mx = max(mx, solve(idx + 1, state | (1 << i)) * P[idx][i] / 100);
    }
    // ret 값에 곱해서 리턴
    ret *= mx;
    return ret;
}

int main(int argc, char *argv[]) {
    scanf("%d", &T);
    for (int tc = 1; tc <= T; ++tc) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) scanf("%d", &P[i][j]);
        // DP배열 초기화
        for (int i = 0; i < N; ++i) for (int j = 0; j < (1 << N); ++j) DP[i][j] = -1;
        printf("#%d %.6Lf\n", tc, solve(0, 0) * 100.0);
    }
    return 0;
}