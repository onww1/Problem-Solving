#include <cstdio>

int N, M;
char in[101], p[1001];

int main(int argc, char *argv[]) {
    scanf("%d %d %s", &N, &M, in);
    for (int i = 0; i < M; ++i) {
        scanf(" %s", p);
        int idx = 0;
        for (int j = 0; p[j] && idx < N; ++j)
            if (in[idx] == p[j]) idx++;
        puts(idx == N ? "true" : "false");
    }
    return 0;
}