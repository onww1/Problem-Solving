#include <cstdio>

char in[1001];
int c[2], f;

int main(int argc, char *argv[]) {
    scanf(" %s", in);
    for (int i = 0; in[i]; ++i) {
        if (in[i] == '(') f = 1;
        if (in[i] == '@') c[f]++;
    }
    printf("%d %d\n", c[0], c[1]);
    return 0;
}