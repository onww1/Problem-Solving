#include <algorithm>
#include <cstdio>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

int n;
pii a[501][501];
char in[501][502], refer[256];

int main(int argc, char *argv[]) {
    refer['M'] = 1, refer['O'] = 2;
    refer['L'] = 3, refer['A'] = 4;

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf(" %s", in[i] + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            pii upper = a[i - 1][j];
            if (upper.Y && refer[in[i - 1][j]] % 4 + 1 != refer[in[i][j]]) upper.Y = 0;
            if (!upper.Y && in[i][j] == 'M') upper.Y = 1;
            if (upper.Y && in[i][j] == 'A') upper.X++;

            pii left = a[i][j - 1];
            if (left.Y && refer[in[i][j - 1]] % 4 + 1 != refer[in[i][j]]) left.Y = 0;
            if (!left.Y && in[i][j] == 'M') left.Y = 1;
            if (left.Y && in[i][j] == 'A') left.X++;
            
            a[i][j] = max(upper, left);
        }
    }

    printf("%d\n", a[n][n].X);
    return 0;
}