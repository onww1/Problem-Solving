#include <cstdio>

int n, m;
char in[101][101], ans[101][101], tr[256];

int main(int argc, char *argv[]) {
    tr['.'] = '.'; tr['O'] = 'O'; tr['-'] = '|'; tr['|'] = '-'; tr['/'] = '\\';
    tr['\\'] = '/'; tr['^'] = '<'; tr['<'] = 'v'; tr['v'] = '>'; tr['>'] = '^';

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) scanf(" %s", in[i]);
    for (int j = m - 1; j >= 0; --j) {
        for (int i = 0; i < n; ++i)
            ans[m - 1 - j][i] = tr[in[i][j]];
        printf("%s\n", ans[m - 1 - j]);
    }
    
    return 0;
}