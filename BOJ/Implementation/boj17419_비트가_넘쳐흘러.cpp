#include <cstdio>
char in[1000050];
int n, ans;
int main(int argc, char *argv[]) {
    scanf("%d %s", &n, in);
    for (int i = 0; in[i]; ++i)
        if (in[i] == '1') ++ans;
    printf("%d\n", ans);
    return 0;
}