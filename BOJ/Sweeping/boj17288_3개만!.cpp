#include <cstdio>
int main(int argc, char *argv[]) {
    char in[105]{};
    int ans = 0, c = 1;
    scanf(" %s", in);
    for (int i = 1; in[i]; ++i) {
        if (in[i] == in[i - 1] + 1) c++;
        else {
            if (c == 3) ans++;
            c = 1;
        }
    }
    if (c == 3) ans++;
    printf("%d\n", ans);
    return 0;
}