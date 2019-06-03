#include <cstdio>
typedef long long ll;

int n, idx[128], cc[7][7];
char str[] = "BESIGOM", c;

int main(int argc, char *argv[]) {
    for (int i = 0; i < 7; ++i) idx[str[i]] = i;
    scanf("%d", &n);
    for (int i = 0, d; i < n; ++i) {
        scanf(" %c %d", &c, &d);
        cc[idx[c]][(d + 140000) % 7]++;
    }

    ll ans = 0;
    for (int i = 0; i < 7; ++i)
        for (int j = 0; j < 7; ++j)
            for (int k = 0; k < 7; ++k)
                for (int l = 0; l < 7; ++l)
                    for (int x = 0; x < 7; ++x)
                        for (int y = 0; y < 7; ++y)
                            for (int z = 0; z < 7; ++z)
                                if ((i + j * 2 + k * 2 + l) % 7 == 0 ||
                                    (j + k + x + y) % 7 == 0 ||
                                    (z + y * 2) % 7 == 0)
                                    ans += 1LL * cc[0][i] * cc[1][j] * cc[2][k] * cc[3][l] * cc[4][x] * cc[5][y] * cc[6][z];

    printf("%lld\n", ans);
    return 0;
}