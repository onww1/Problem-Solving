#include <algorithm>
#include <cstdio>
using namespace std;

int main(int argc, char *argv[]) {
    int x[4], y[4];
    for (int i = 0; i < 4; ++i) scanf("%d %d", x + i, y + i);
    int x_mx = max(x[3], x[1]), x_mn = min(x[0], x[2]);
    int y_mx = max(y[3], y[1]), y_mn = min(y[0], y[2]);
    int L = max(y_mx - y_mn, x_mx - x_mn);
    printf("%d\n", L * L);
    return 0;
}