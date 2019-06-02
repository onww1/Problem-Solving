#include <algorithm>
#include <cstdio>
using namespace std;

const int MAX = 1e5 + 1;
int n, x[MAX], y[MAX], tot;

int dist(int a, int b) {
    return abs(x[a] - x[b]) + abs(y[a] - y[b]);
}

int main(int argc, char *argv[]) {
    scanf("%d", &n);
    int mx = 0;
    for (int i = 0, pr = 0, cur = 0; i < n; ++i, pr = cur) {
        scanf("%d %d", x + i, y + i);
        if (i > 0) tot += (cur = dist(i, i - 1));
        if (i > 1) mx = max(mx, pr + cur - dist(i, i - 2));
    }
    printf("%d\n", tot - mx);
    return 0;
}