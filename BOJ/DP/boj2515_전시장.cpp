#include <algorithm>
#include <cstdio>
#include <cstring>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

const int MAX = 3e5;
int N, S, DP[MAX];
pii A[MAX];

int solve(int idx) {
    if (idx >= N) return 0;

    int &ret = DP[idx];
    if (~ret) return ret;
    ret = A[idx].Y;

    // 선택 안하는 경우
    if (idx + 1 < N && A[idx + 1].X - A[idx].X < S) 
        ret = max(ret, solve(idx + 1));

    // 선택하고 다음으로 넘어가는 경우
    int s = idx, e = N - 1, m, aa = -1;
    while (s <= e) {
        m = (s + e) >> 1;
        if (A[m].X >= A[idx].X + S) {
            aa = m;
            e = m - 1;
        } else s = m + 1;
    } 
    if (aa != -1) ret = max(ret, solve(aa) + A[idx].Y);

    return ret;
}

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &S);
    for (int i = 0; i < N; ++i) scanf("%d %d", &A[i].X, &A[i].Y);
    sort(A, A + N);
    int offset = 0;
    for (int i = 0; i < N; ++i) {
        int tmp = A[i].X;
        while (i + 1 < N && tmp == A[i + 1].X) offset++, i++;
        A[i - offset] = A[i];
    }
    N -= offset;

    memset(DP, -1, sizeof(DP));
    printf("%d\n", solve(0));
    return 0;
}
