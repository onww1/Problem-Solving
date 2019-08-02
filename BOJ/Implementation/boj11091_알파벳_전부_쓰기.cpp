#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n, c, a[26];
char in[105];

int main(int argc, char *argv[]) {
    scanf("%d", &n); getchar();
    while (n--) {
        c = 0;
        memset(a, 0, sizeof(a));
        fgets(in, sizeof(in), stdin);
        for (int i = 0; in[i]; ++i) {
            if ('a' <= in[i] && in[i] <= 'z') {
                if (!a[in[i] - 'a']) c++;
                a[in[i] - 'a']++;
            }
            else if ('A' <= in[i] && in[i] <= 'Z') {
                if (!a[in[i] - 'A']) c++;
                a[in[i] - 'A']++;
            }
        }
        if (c == 26) puts("pangram");
        else {
            printf("missing ");
            for (int i = 0; i < 26; ++i)
                if (!a[i]) printf("%c", 'a' + i);
            puts("");
        }
    }
    return 0;
}