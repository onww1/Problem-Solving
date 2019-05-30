#include <algorithm>
#include <cstdio>
using namespace std;

int N, M, DN[100], VN[100], DM[100], VM[100], D[200];

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", DN + i, VN + i);
        if (i) DN[i] += DN[i - 1];
        D[i] = DN[i];
    }
    for (int i = 0; i < M; ++i) {
        scanf("%d %d", DM + i, VM + i);
        if (i) DM[i] += DM[i - 1];
        D[N + i] = DM[i];
    }
    
    sort(D, D + N + M);
    int nn = unique(D, D + N + M) - D;

    int ans = 0;
    for (int i = 0, in = 0, im = 0; i < nn; ++i) {
        while (in < N && DN[in] < D[i]) in++;
        while (im < M && DM[im] < D[i]) im++;
        ans = max(ans, max(0, VM[im] - VN[in]));
    }

    printf("%d\n", ans);
    return 0;
}