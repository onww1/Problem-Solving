#include <cstdio>
char in[500001], c;
int N, f;
int main() {
    scanf(" %s", in); c = in[0];
    for (N = 0; in[N]; ++N) if (in[N] != c) f = 1; 
    int pal = 1;
    for (int i = 0; i < N / 2; ++i) 
        if (in[i] != in[N - 1 - i]) pal = 0;
    printf("%d\n", f ? N - pal : -1);
    return 0;
}