#include <algorithm>
#include <cstdio>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

int main(int argc, char *argv[]) {
    pii in[9];
    int ans = -1;
    for (int i = 0; i < 9; ++i) scanf("%d %d", &in[i].X, &in[i].Y);
    for (int i = 0; i < 9; ++i) {
        int p[10]{}, r = 0, c = -1, valid = 1;
        for (int j = 0; j < 9; ++j) {
            if (in[j].X ^ (i == j)) {
                if (!p[in[j].Y]) p[in[j].Y] = 1, r++, c = in[j].Y;
                else if (p[in[j].Y] == -1) valid = 0;
                if (r > 1) valid = 0;
            } else {
                if (!p[in[j].Y]) p[in[j].Y] = -1;
                else if (p[in[j].Y] == 1) valid = 0;
            }
        }
        if (valid && (c != -1 || r == 0)) {
            int candidate = c;
            if (candidate == -1) {
                for (int j = 1; j < 10; ++j) {
                    if (p[j] != -1) {
                        if (ans != candidate) return !printf("-1\n");
                        ans = j;
                    }
                }
            } else {
                if (ans != -1 && candidate != ans) return !printf("-1\n");
                ans = candidate;
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}