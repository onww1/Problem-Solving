#include <cstdio>

int N;
char in[10][11];

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf(" %s", in[i]);

    int ans = 0;
    for (int i = N - 1; i >= 0; --i) 
        for (int j = N - 1; j >= 0; --j)
            if (in[i][j] == '1') {
                ans++;
                for (int a = 0; a <= i; ++a)
                    for (int b = 0; b <= j; ++b)
                        in[a][b] = in[a][b] == '1' ? '0' : '1';
            }

    printf("%d\n", ans);
    return 0;
}
