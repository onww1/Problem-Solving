#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#define X first
#define Y second
using namespace std;
typedef long double ldb;

const ldb ERR = 1e-10;
int N, X[16], Y[16];
ldb D[16][16], DP[16][1 << 16];

ldb dist(int i, int j) { return (ldb)sqrt((X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j])); }

ldb TSP(int node, int state) {
    if (state == (1 << N) - 1) return D[node][0];

    ldb &ret = DP[node][state];
    if (abs(ret + 1) > ERR) return ret;
    ret = 987654321.0;

    for (int i = 1; i < N; ++i) {
        if (state & (1 << i)) continue;
        ret = min(ret, TSP(i, state | (1 << i)) + D[node][i]);
    }

    return ret;
}

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf("%d %d", X + i, Y + i);
    for (int i = 0; i < N - 1; ++i) for (int j = i + 1; j < N; ++j)
        D[i][j] = D[j][i] = dist(i, j);
        
    for (int i = 0; i < N; ++i) fill(DP[i], DP[i] + (1 << N), -1);

    printf("%.12Lf\n", TSP(0, 1));
    return 0;
}