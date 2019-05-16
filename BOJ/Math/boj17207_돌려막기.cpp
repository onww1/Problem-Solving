#include <cstdio>

int A[5][5], B[5][5], C[5][5];
int main(int argc, char *argv[]) {
    for (int i = 0; i < 5; ++i) for (int j = 0; j < 5; ++j) scanf("%d", A[i] + j);
    for (int i = 0; i < 5; ++i) for (int j = 0; j < 5; ++j) scanf("%d", B[i] + j);
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            for (int k = 0; k < 5; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    for (int j = 1; j < 5; ++j) {
        for (int i = 0; i < 5; ++i) {
            C[i][j] += C[i][j - 1];
        }
    }
    int mn = C[4][4], idx = 4;
    for (int i = 3; i >= 0; --i) {
        if (mn > C[i][4]) {
            mn = C[i][4];
            idx = i;
        }
    }

    switch (idx) {
        case 0: puts("Inseo"); break;
        case 1: puts("Junsuk"); break;
        case 2: puts("Jungwoo"); break;
        case 3: puts("Jinwoo"); break;
        case 4: puts("Youngki"); break;
    }
    return 0;
}