#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;

int n, m;
set <int> a;

int main(int argc, char *argv[]) {
    scanf("%d %d", &n, &m);
    for (int i = 0, c; i < n; ++i) {
        scanf("%d", &c);
        a.insert(c);
    }

    int cnt = 0;
    for (int i = 0, c; i < m; ++i) {
        scanf("%d", &c);
        if (a.count(c)) cnt++;
    }

    printf("%d\n", n + m - 2 * cnt);
    return 0;
}