#include <cstdio>
typedef long double ldb;

int main(int argc, char *argv[]) {
    int N, A;
    ldb P[2][2], C[2][2]{};

    scanf("%d %d", &N, &A);
    for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) scanf("%Lf", P[i] + j);

    C[0][A] = 1;
    for (int i = 0; i < N; ++i) {
        C[1][0] = (C[0][0] * P[0][0] + C[0][1] * P[1][0]);
        C[1][1] = (C[0][0] * P[0][1] + C[0][1] * P[1][1]);
        C[0][0] = C[1][0];
        C[0][1] = C[1][1];
    }

    printf("%.0Lf\n%.0Lf\n", C[0][0] * 1000, C[0][1] * 1000);
    return 0;
}