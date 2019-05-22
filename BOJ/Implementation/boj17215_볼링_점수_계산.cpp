#include <cstdio>

char in[100];
int ans;

int main(int argc, char *argv[]) {
    scanf(" %s", in);
    int p = 1, c = 1, f = 1, s[3]{};
    for (int i = 0; in[i]; ++i, s[2] = s[1], s[1] = s[0], s[0] = 0) {
        if (in[i] == 'S') {
            if (f) {
                ans += 10;
                s[0] = 2;
            }
            if (s[1]) ans += 10;
            if (s[2] == 2) ans += 10;
            if (p == 10) f = 0, c++;
            else p++, c = 1;
        }
        else if (in[i] == 'P') {
            int point = 10 - (in[i - 1] == '-' ? 0 : in[i - 1] - '0');
            if (f) {
                ans += point;
                s[0] = 1;
            }
            if (s[1]) ans += point;
            if (s[2] == 2) ans += point;
            if (p == 10) f = 0, c++;
            else p++, c = 1;
        }
        else if (in[i] == '-') {
            if (c == 2) p++, c = 1;
            else c++;
        }
        else {
            int point = in[i] - '0';
            if (f) ans += point;
            if (s[1]) ans += point;
            if (s[2] == 2) ans += point;
            if (c == 2) p++, c = 1;
            else c++;
        }
    }

    printf("%d\n", ans);
    return 0;
}