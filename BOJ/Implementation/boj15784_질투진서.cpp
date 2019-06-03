#include <cstdio>
int n, a, b, x[1001][1001];

int main(int argc, char *argv[]) {
    scanf("%d %d %d", &n, &a, &b);
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) 
        scanf("%d", x[i] + j);
    int refx = x[a][b];
    for (int i = 1; i <= n; ++i) 
        if (x[i][b] > refx || x[i][a] > refx) {
            puts("ANGRY");
            return 0;
        }

    puts("HAPPY");
    return 0;
}