#include <cstdio>

int in[2][16];

int main(int argc, char *argv[]) {
    for (int i = 0; i < 8; ++i) scanf("%1d", &in[0][2 * i]);
    for (int i = 0; i < 8; ++i) scanf("%1d", &in[0][2 * i + 1]);

    for (int i = 0; i < 14; ++i) {
        for (int j = 0; j < 15 - i; ++j) 
            in[1][j] = (in[0][j] + in[0][j + 1]) % 10;
        for (int j = 0; j < 15 - i; ++j)
            in[0][j] = in[1][j];
    }

    printf("%d%d\n", in[0][0], in[0][1]);
    return 0;
}