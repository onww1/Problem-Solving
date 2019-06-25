#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int n, mn = 0x3f3f3f3f, a[20][20];
bool v[1 << 20];

int main(int argc, char *argv[]) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) scanf("%d", a[i] + j);

    int lim = (1 << n) - 1;
    for (int i = 1; i < lim; ++i) {
        if (v[i]) continue;
        v[i] = v[i ^ lim] = true;
        vector <int> x, y;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) x.push_back(j);
            else y.push_back(j);
        }
        int s1 = 0, s2 = 0;
        for (int j = 0; j < x.size() - 1; ++j)
            for (int k = j + 1; k < x.size(); ++k)
                s1 += a[x[j]][x[k]] + a[x[k]][x[j]];
        for (int j = 0; j < y.size() - 1; ++j)
            for (int k = j + 1; k < y.size(); ++k)
                s2 += a[y[j]][y[k]] + a[y[k]][y[j]];
        mn = min(mn, abs(s1 - s2));
    }

    printf("%d\n", mn);
    return 0;
}