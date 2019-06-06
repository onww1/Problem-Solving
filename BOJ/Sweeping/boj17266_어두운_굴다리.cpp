#include <algorithm>
#include <cstdio>
using namespace std;

const int MAX = 1e5 + 1;
int n, m, x[MAX];

int main(int argc, char *argv[]) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) scanf("%d", x + i);

    int mx = max(x[0], n - x[m - 1]);
    for (int i = 0; i < m - 1; ++i) mx = max(mx, (x[i + 1] - x[i] + 1) / 2);

    printf("%d\n", mx);
    return 0;
}