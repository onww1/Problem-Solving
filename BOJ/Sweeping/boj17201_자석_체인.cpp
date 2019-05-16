#include <cstdio>

int N;
char in[105];

int main(int argc, char *argv[]) {
    scanf("%d %s", &N, in); N *= 2;
    for (int i = 1; i < N; ++i) 
        if (in[i] == in[i - 1]) return !printf("No\n");
    printf("Yes\n");
    return 0;
}