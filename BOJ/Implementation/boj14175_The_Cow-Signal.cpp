#include <cstdio>
int N, M, K;
char in[11], out[101];
int main(int argc, char *argv[]) {
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0; i < N; ++i) {
        scanf(" %s", in);
        for (int j = 0; in[j]; ++j) 
            for (int k = 0; k < K; ++k)
                out[j * K + k] = in[j];
        for (int k = 0; k < K; ++k)
            printf("%s\n", out);
    }
    return 0;
}