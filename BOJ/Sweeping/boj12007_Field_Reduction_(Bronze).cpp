#include <algorithm>
#include <cstdio>
using namespace std;

const int INF = 0x7f7f7f7f;
int N, X[50000], Y[50000], x_mn[2], y_mn[2], x_mx[2], y_mx[2];

int main(int argc, char *argv[]) {
    x_mn[0] = x_mn[1] = y_mn[0] = y_mn[1] = INF;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", X + i, Y + i);
        if (X[i] > x_mx[0]) x_mx[1] = x_mx[0], x_mx[0] = X[i];
        else if (X[i] > x_mx[1]) x_mx[1] = X[i];
        if (Y[i] > y_mx[0]) y_mx[1] = y_mx[0], y_mx[0] = Y[i];
        else if (Y[i] > y_mx[1]) y_mx[1] = Y[i];
        if (X[i] < x_mn[0]) x_mn[1] = x_mn[0], x_mn[0] = X[i];
        else if (X[i] < x_mn[1]) x_mn[1] = X[i];
        if (Y[i] < y_mn[0]) y_mn[1] = y_mn[0], y_mn[0] = Y[i];
        else if (Y[i] < y_mn[1]) y_mn[1] = Y[i];
    }

    int ans = INF;
    for (int i = 0; i < N; ++i) {
        int xn = X[i] == x_mn[0] ? x_mn[1] : x_mn[0];
        int xx = X[i] == x_mx[0] ? x_mx[1] : x_mx[0];
        int yn = Y[i] == y_mn[0] ? y_mn[1] : y_mn[0];
        int yx = Y[i] == y_mx[0] ? y_mx[1] : y_mx[0];
        ans = min(ans, (xx - xn) * (yx - yn));
    }

    printf("%d\n", ans);
    return 0;
}