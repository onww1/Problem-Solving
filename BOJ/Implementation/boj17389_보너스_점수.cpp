#include <cstdio>
int n, b, s;
char in[10050];
int main(int argc, char *argv[]) {
    scanf("%d %s", &n, in);
    for (int i = 0; i < n; ++i) {
        if (in[i] == 'O') s += i + 1 + b++;
        else b = 0;
    }
    printf("%d\n", s);
    return 0;
}